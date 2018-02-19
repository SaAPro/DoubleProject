//
//  ViewController.m
//  Double_project
//
//  Created by Alexandre Sarazin on 19/01/2018.
//  Copyright © 2018 Alexandre Sarazin. All rights reserved.
//

#import "ViewController.h"

@interface ViewController () <DRDoubleDelegate>
@property (strong, nonatomic) IBOutlet UITextView *textView;
@property (strong, nonatomic) IBOutlet UITextView *textViewWarning;
@property (strong, nonatomic) IBOutlet UIImageView *imageView; // DO NOT DELETE IT FROM THE STORYBOARD
@property (strong, nonatomic) IBOutlet UISegmentedControl *segmentedControl;
@property (strong, nonatomic) IBOutlet UISlider *slider;
@property (strong, nonatomic) IBOutlet UIButton *train;
@property (strong, nonatomic) ClarifaiApp *_app;
@property (strong, nonatomic) IBOutlet UIButton *button;
@property (strong, nonatomic) IBOutlet UIButton *buttonAcquireTrainingSet;
@property (strong, nonatomic) IBOutlet UIButton *buttonRecognizeImage;
@end

@implementation ViewController

@synthesize imagePreview, stillImageOutput;

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [UIApplication sharedApplication].idleTimerDisabled = YES; // avoid stand-by

    [DRDouble sharedDouble].delegate = self;
    NSLog(@"SDK Version: %@", kDoubleBasicSDKVersion);
    
    /* Global varaibles initialization */
    _n_concept = 0; // n° of the concept being used
    _speed = .8; // Robot speed [0 1]
    _ip_address = @""; // ip address
    _ApiKey = @""; // Your personal Clarifai's Api Key
    _app = [[ClarifaiApp alloc] initWithApiKey:_ApiKey];
    _concept = @[@"laboratorium",@"corridor",@"graal_laboratory",@"stairs"]; // Define the different concepts as a String
    _conceptArray = @[@[@"laboratorium"],@[@"corridor"],@[@"graal_laboratory"],@[@"stairs"]]; // Define the different concept as a StringArray
    _modelName = @"model2"; // Model's name
    
    _angleMaxAcquireTrainingset = 360; // Define the angle in degrees to be used for the 'acquireTrainingSet' function
    _angle_incAcquireTrainingSet = 10; // Define the increment angle in degrees to be used for the 'acquireTrainingSet' function. n_picture = _angleMax/_angle_inc
    
    _nMaxpictureRecognizeImage = 3; // Number of pictures to be used to recognize a scene
    _angle_incRecognizeImage = 15; // Define the increment angle in degrees to be used for the 'recognizeImage' function. final_angle = _nMax * _angle_inc
    
    NSLog(@"Application started");
    
    // The following three lines are needed in order to hear the voice synthethizer even if the SOUNDS (not the volume) on the iPad are muted
    NSError *sessionError = nil;
    AVAudioSession *session = [AVAudioSession sharedInstance];
    [session setCategory:AVAudioSessionCategoryPlayAndRecord error:&sessionError];
}

- (void)viewDidAppear:(BOOL)animated {
    [self initCamera];
}

- (void)initRemoteControl {
    
    CFReadStreamRef  control_readStream;
    CFWriteStreamRef control_writeStream;
    CFStreamCreatePairWithSocketToHost(NULL, (__bridge CFStringRef)_ip_address, 6001, &control_readStream, &control_writeStream);
    control_inputStream  = (__bridge NSInputStream *)control_readStream;
    control_outputStream = (__bridge NSOutputStream *)control_writeStream;
    
    [control_inputStream  setDelegate:self];
    [control_outputStream setDelegate:self];
    
    [control_inputStream  scheduleInRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
    [control_outputStream scheduleInRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
    
    [control_inputStream  open];
    [control_outputStream open];
}

- (void)initCamera {
    
    AVCaptureSession *session = [[AVCaptureSession alloc] init];
    session.sessionPreset = AVCaptureSessionPresetPhoto;
    
    AVCaptureVideoPreviewLayer *captureVideoPreviewLayer = [[AVCaptureVideoPreviewLayer alloc] initWithSession:session];
    [captureVideoPreviewLayer setVideoGravity:AVLayerVideoGravityResizeAspectFill];
    
    captureVideoPreviewLayer.frame = self.imagePreview.bounds;
    [self.imagePreview.layer addSublayer:captureVideoPreviewLayer];
    
    UIView *view = [self imagePreview];
    CALayer *viewLayer = [view layer];
    [viewLayer setMasksToBounds:YES];
    
    CGRect bounds = [imagePreview bounds];
    [captureVideoPreviewLayer setFrame:bounds];
    
    /* SET DEFAULT CAMERA TO BE THE FRONT ONE */
    
    NSArray *devices = [AVCaptureDevice devices];
    AVCaptureDevice *frontCamera;
    AVCaptureDevice *backCamera;
    
    for (AVCaptureDevice *device in devices) {              // iterate through all the cameras
        if ([device hasMediaType:AVMediaTypeVideo]) {
            if ([device position] == AVCaptureDevicePositionBack) {
                backCamera = device;
            }
            if ([device position] == AVCaptureDevicePositionFront) {
                frontCamera = device;
            }
        }
    }
    
    NSError *error = nil;
    AVCaptureDeviceInput *input = [AVCaptureDeviceInput deviceInputWithDevice:frontCamera error:&error];
    if (!input) {
        NSLog(@"ERROR: trying to open camera: %@", error);
        dispatch_async(dispatch_get_main_queue(), ^{
            self.textViewWarning.text = @"ERROR: trying to open camera";
        });
    }
    [session addInput:input];
    
    /* --- */
    
    stillImageOutput = [[AVCaptureStillImageOutput alloc] init];
    NSDictionary *outputSettings = [[NSDictionary alloc] initWithObjectsAndKeys:AVVideoCodecJPEG, AVVideoCodecKey, nil];
    [stillImageOutput setOutputSettings:outputSettings];
    
    [session addOutput:stillImageOutput];
    
    [session startRunning];
    NSLog(@"Session: %@", session);
}

- (UIImage *) capImage {
    AVCaptureConnection *videoConnection = nil;
    for (AVCaptureConnection *connection in stillImageOutput.connections) {
        for (AVCaptureInputPort *port in [connection inputPorts]) {
            if ([[port mediaType] isEqual:AVMediaTypeVideo]) {
                videoConnection = connection;
                break;
            }
        }
        if (videoConnection) {
            break;
        }
    }
    [stillImageOutput captureStillImageAsynchronouslyFromConnection:videoConnection completionHandler:^(CMSampleBufferRef imageSampleBuffer, NSError *error) {
        if (imageSampleBuffer != NULL) {
            NSData *imageData = [AVCaptureStillImageOutput jpegStillImageNSDataRepresentation:imageSampleBuffer];
            _image = [UIImage imageWithData:imageData];
            dispatch_async(dispatch_get_main_queue(), ^{
                self.imageView.image = _image;
            });
        }
    }];
    return _image;
}

- (void)doubleDriveShouldUpdate:(DRDouble *)theDouble {
    float drive = (forward) ? _speed : ((backward) ? -_speed : kDRDriveDirectionStop);
    float turn  = (right)   ? 1.0 : ((left)     ? -1.0 : 0.0);
    
    [theDouble variableDrive:drive turn:turn];
}

- (void) remoteControl {
    uint8_t control_buffer[1024];
    int control_len;
    
    while ([control_inputStream hasBytesAvailable]) {
        control_len = [control_inputStream read:control_buffer maxLength:sizeof(control_buffer)];
        
        if (control_len > 0) {
            
            NSString *control_output = [[NSString alloc] initWithBytes:control_buffer length:control_len encoding:NSASCIIStringEncoding];
            
            if (nil != control_output) {
                dispatch_async(dispatch_get_main_queue(), ^{
                    self.textViewWarning.text = [NSString stringWithFormat:@"Control input: %@", control_output];
                });
                if ([control_output  isEqual: @"b"]){
                    [[DRDouble sharedDouble] deployKickstands];
                }
                else if([control_output  isEqual: @"u"]){
                    [[DRDouble sharedDouble] retractKickstands];
                }
                else if([control_output  isEqual: @"KEY_UP"]){
                    [self goForward];
                }
                else if([control_output  isEqual: @"KEY_DOWN"]){
                    [self goBackward];
                }
                else if([control_output  isEqual: @"KEY_LEFT"]){
                    [[DRDouble sharedDouble] turnByDegrees: 5];
                }
                else if([control_output  isEqual: @"KEY_RIGHT"]){
                    [[DRDouble sharedDouble] turnByDegrees:-5];
                }
                else if([control_output  isEqual: @" "]){
                    [self stopMotion];
                }
                else if([control_output  isEqual: @"t"]){
                    [self trainModel];
                }
                else if([control_output  isEqual: @"e"]){
                    [_buttonRecognizeImage sendActionsForControlEvents:UIControlEventTouchUpInside];
                }
                else if([control_output  isEqual: @"a"]){
                    [_buttonAcquireTrainingSet sendActionsForControlEvents:UIControlEventTouchUpInside];
                }
                else if([control_output  isEqual: @"1"]){
                    _n_concept = 0;
                    dispatch_async(dispatch_get_main_queue(), ^{
                        NSString *string = [NSString stringWithFormat:@"Concept set '%@' for further processing.", _concept[_n_concept]];
                        self.textView.text = string;
                        [self say:string];
                    });
                }
                else if([control_output  isEqual: @"2"]){
                    _n_concept = 1;
                    dispatch_async(dispatch_get_main_queue(), ^{
                        NSString *string = [NSString stringWithFormat:@"Concept set '%@' for further processing.", _concept[_n_concept]];
                        self.textView.text = string;
                        [self say:string];
                    });
                }
                else if([control_output  isEqual: @"3"]){
                    _n_concept = 2;
                    dispatch_async(dispatch_get_main_queue(), ^{
                        NSString *string = [NSString stringWithFormat:@"Concept set '%@' for further processing.", _concept[_n_concept]];
                        self.textView.text = string;
                        [self say:string];
                    });
                }
                else if([control_output  isEqual: @"4"]){
                    _n_concept = 3;
                    dispatch_async(dispatch_get_main_queue(), ^{
                        NSString *string = [NSString stringWithFormat:@"Concept set '%@' for further processing.", _concept[_n_concept]];
                        self.textView.text = string;
                        [self say:string];
                    });
                }
                //else if([control_output  isEqual: @"KEY_LEFT"]){
                //    [self goLeft];
                //}
                //else if([control_output  isEqual: @"KEY_RIGHT"]){
                //    [self goRight];
                //}
                else if([control_output  isEqual: @"0"]){
                    [self stopTurning];
                }
                else if([control_output  isEqual: @"+"]){
                    [[DRDouble sharedDouble] poleUp];
                }
                else if([control_output  isEqual: @"-"]){
                    [[DRDouble sharedDouble] poleDown];
                }
                else if([control_output  isEqual: @"00"]){
                    [[DRDouble sharedDouble] poleStop];
                }
                else if([control_output  isEqual: @"q"]){
                    exit(0);
                }
                else {
                }
            }
            [control_inputStream  close];
            [control_outputStream close];
            [self initRemoteControl];
        }
    }
}

- (void) acquireTrainingSet:(NSTimer*)t {
    if (_angleAcquireTrainingSet >= _angleMaxAcquireTrainingset) {
        [t invalidate];
        t = nil;
        NSLog(@"Finished acquiring the training set for the %@", _concept[_n_concept]);
        NSString *string = [NSString stringWithFormat:@"Finished acquiring the training set for the %@", _concept[_n_concept]];
        dispatch_async(dispatch_get_main_queue(), ^{
            self.textView.text = string;
            [self say:string];
        });
    }
    else {
        NSLog(@"Picture n°: %i; Angle: %i; Concept: %@",_n_pictureAcquireTrainingSet, _angleAcquireTrainingSet, _concept[_n_concept]);
        UIImage *image = [self capImage];
        [self uploadImage:image];
        [[DRDouble sharedDouble] turnByDegrees:_angle_incAcquireTrainingSet];
        [control_inputStream  close];
        [control_outputStream close];
        [self initRemoteControl];
        _angleAcquireTrainingSet += _angle_incAcquireTrainingSet;
        _n_pictureAcquireTrainingSet += 1;
    }
}

- (void)uploadImage:(UIImage *)image {
    // Add image with concept.
    dispatch_async(dispatch_get_main_queue(), ^{
        self.textView.text = [NSString stringWithFormat:@"Uploading image...\nTag: %@", _concept[_n_concept]];
    });
    // ROTATE THE IMAGE BY 90 CW - NOT DONE. SHOULD ROTATE ON THE LEFT. COULD IMPROVED THE PERFORMANCES.
    ClarifaiImage *clarifaiImage = [[ClarifaiImage alloc] initWithImage:image andConcepts:_conceptArray[_n_concept]];
    [_app addInputs:@[clarifaiImage] completion:^(NSArray<ClarifaiInput *> *inputs, NSError *error) {
        if (!error) {
            NSLog(@"inputs: %@", inputs);
            dispatch_async(dispatch_get_main_queue(), ^{
                self.textViewWarning.text = [NSString stringWithFormat:@"The image has been uploaded.\nTag: %@", _concept[_n_concept]];
            });
        } else {
            NSLog(@"Error: %@", error.description);
            dispatch_async(dispatch_get_main_queue(), ^{
                self.textViewWarning.text = @"Error: coud not upload images";
            });
        }
    }];
}

- (void)trainModel { // COMMENT THE NEXT 15 LINES IF THE MODEL HAS BEEN ALREADY CREATED. CAN CREATE PROBLEM WITH CLARIFAI API.
    // Create the model with concepts
    [_app createModel:_concept name:_modelName conceptsMutuallyExclusive:NO closedEnvironment:NO
          completion:^(ClarifaiModel *model, NSError *error) {
              if (!error) {
                  NSLog(@"model: %@", model);
                  dispatch_async(dispatch_get_main_queue(), ^{
                      self.textViewWarning.text = @"The model has been generated.";
                  });
              } else {
                  NSLog(@"Error: %@", error.description);
                  dispatch_async(dispatch_get_main_queue(), ^{
                      self.textViewWarning.text = @"Error: coud not generate the model.";
                  });
              }
          }];
    
    // Train the model with concepts
    [_app getModelByName:_modelName completion:^(ClarifaiModel *model, NSError *error) {
        [model train:^(ClarifaiModelVersion *version, NSError *error) {
            if (!error) {
                NSLog(@"model: %@", model);
                dispatch_async(dispatch_get_main_queue(), ^{
                    self.textViewWarning.text = @"The model has been train.";
                });
            } else {
                NSLog(@"Error: %@", error.description);
                dispatch_async(dispatch_get_main_queue(), ^{
                    self.textViewWarning.text = @"Error: coud not train the model.";
                });
            }
        }];
    }];
}

- (void)recognizeImage:(NSTimer*)t {
    int n = _n_pictureRecognizeImage;
    if (n > _nMaxpictureRecognizeImage) {
        [t invalidate];
        t = nil;
        int max = 0;
        NSMutableString *tagResult;
        // Count the number of occurence in _pTagResult for each concept and save in tagResult the concept with the higher number of occurence
        for(NSString *concept in _concept){
            int occurrences = 0;
            for(NSString *string in _pTagResult){
                occurrences += ([string isEqualToString:concept]?1:0);
            }
            if (occurrences > max) {
                max = occurrences;
                tagResult = [NSMutableString stringWithString:concept];
            }
        }
        dispatch_async(dispatch_get_main_queue(), ^{
            self.textView.text = [NSString stringWithFormat:@"Recognition finished. Result:\n%@", tagResult];
            [self say:[NSString stringWithFormat:@"I should be in the %@", tagResult]];
        });
    }
    else {
        // capture image
        UIImage *image = [self capImage];

        // Fetch Clarifai's general model.
        [_app getModelByName:_modelName completion:^(ClarifaiModel *model, NSError *error) {
            // Create a Clarifai image from a uiimage.
            ClarifaiImage *clarifaiImage = [[ClarifaiImage alloc] initWithImage:image];
            
            // Use our own train model to predict tags for the given image.
            [model predictOnImages:@[clarifaiImage] completion:^(NSArray<ClarifaiOutput *> *outputs, NSError *error) {
                if (!error) {
                    ClarifaiOutput *output = outputs[0];
                    
                    // Display predicted concept on the screen.
                    NSMutableArray *tags = [NSMutableArray array];
                    for (ClarifaiConcept *concept in output.concepts) {
                        [tags addObject:concept.conceptName];
                        dispatch_async(dispatch_get_main_queue(), ^{
                            self.textView.text = [NSString stringWithFormat:@"Tag:\n%@", tags[0]];
                            [self say:[NSString stringWithFormat:@"Concept in picture %i: %@", n,tags[0]]];
                        });
                    }
                    [_pTagResult addObject:tags[0]];
                } else {
                    NSLog(@"Error: %@", error.description);
                    dispatch_async(dispatch_get_main_queue(), ^{
                        self.textViewWarning.text = @"Error model.";
                        [self say:[NSString stringWithFormat:@"Error model picture %i", n]];
                    });
                }
            }];
        }];
        [[DRDouble sharedDouble] turnByDegrees:_angle_incRecognizeImage];
        [control_inputStream  close];
        [control_outputStream close];
        [self initRemoteControl];
        _n_pictureRecognizeImage += 1;
    }
}

- (void) say:(NSString*)phrase {
    AVSpeechSynthesizer *synthesizer = [[AVSpeechSynthesizer alloc]init];
    AVSpeechUtterance   *utterance   = [AVSpeechUtterance speechUtteranceWithString:phrase];
    utterance.voice = [AVSpeechSynthesisVoice voiceWithLanguage:@"en-US"];
    utterance.pitchMultiplier = 1.25; // higher pitch
    [utterance   setRate:0.2f];
    [synthesizer speakUtterance:utterance];
}

- (IBAction)connectToServer:(id)sender {
    [self initRemoteControl];
    [NSTimer scheduledTimerWithTimeInterval:0.2 target:self selector:@selector(remoteControl) userInfo:nil repeats:YES];
}
- (IBAction)train:(id)sender {
    [self trainModel];
}
- (IBAction)acquire:(id)sender {
    _angleAcquireTrainingSet = 0;
    _n_pictureAcquireTrainingSet = 1;
    NSLog(@"Start acquiring the training set for the %@", _concept[_n_concept]);
    NSString *string = [NSString stringWithFormat:@"Start acquiring the training set for the %@", _concept[_n_concept]];
    dispatch_async(dispatch_get_main_queue(), ^{
        [self say:string];
    });
    timerAcquireTrainingSet = [NSTimer scheduledTimerWithTimeInterval:4 target:self selector:@selector(acquireTrainingSet:) userInfo:nil repeats:YES];
}

- (IBAction)acquireOneShot:(id)sender {
    UIImage *image = [self capImage];
    [self uploadImage:image];
}

- (IBAction)recognize:(id)sender {
    _n_pictureRecognizeImage = 1;
    _pTagResult = [NSMutableArray array];
    timerRecognizeImage = [NSTimer scheduledTimerWithTimeInterval:5 target:self selector:@selector(recognizeImage:) userInfo:nil repeats:YES];
    dispatch_async(dispatch_get_main_queue(), ^{
        NSString *string = [NSString stringWithFormat:@"Starting to recognize the scene."];
        self.textView.text = string;
        [self say:string];
    });
}

- (IBAction)setn_concept:(id)sender {
    _n_concept = _segmentedControl.selectedSegmentIndex;
    dispatch_async(dispatch_get_main_queue(), ^{
        NSString *string = [NSString stringWithFormat:@"Concept set '%@' for further processing.", _concept[_n_concept]];
        self.textView.text = string;
        [self say:string];
    });
}
- (IBAction)setSpeed:(id)sender {
    _speed = _slider.value;
}

- (IBAction)kickstandsDeploy:(id)sender {
    [[DRDouble sharedDouble] deployKickstands];
}

- (IBAction)kickstandsRetract:(id)sender {
    [[DRDouble sharedDouble] retractKickstands];
}

- (IBAction)poleUp:(id)sender {
    [[DRDouble sharedDouble] poleUp];
}

- (IBAction)poleStop:(id)sender {
    [[DRDouble sharedDouble] poleStop];
}

- (IBAction)poleDown:(id)sender {
    [[DRDouble sharedDouble] poleDown];
}

- (IBAction)moveForward:(id)sender {
    [self goForward];
}

- (IBAction)moveBackward:(id)sender {
    [self goBackward];
}

- (IBAction)stopMotion:(id)sender {
    [self stopMotion];
}

- (IBAction)turnRight:(id)sender {
    [[DRDouble sharedDouble] turnByDegrees:-5];
}

- (IBAction)turnLeft:(id)sender {
    [[DRDouble sharedDouble] turnByDegrees: 5];
}

- (void) goForward{
    forward  = true;
    backward = false;
    stop     = false;
}

-(void) goBackward{
    forward  = false;
    backward = true;
    stop     = false;
}

-(void) stopMotion {
    forward  = false;
    backward = false;
    stop     = true;
}

-(void) goRight{
    right        = true;
    left         = false;
    stop_turning = false;
}

-(void) goLeft{
    right        = false;
    left         = true;
    stop_turning = false;
}

-(void) stopTurning{
    right        = false;
    left         = false;
    stop_turning = true;
}

@end
