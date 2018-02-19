//
//  ViewController.h
//  Double_project
//
//  Created by Alexandre Sarazin on 19/01/2018.
//  Copyright © 2018 Alexandre Sarazin. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import <DoubleControlSDK/DoubleControlSDK.h>
#import "ClarifaiApp.h"


NSInputStream  *control_inputStream;
NSOutputStream *control_outputStream;

NSTimer *timerAcquireTrainingSet;
NSTimer *timerRecognizeImage;

int _angleAcquireTrainingSet;
int _angleMaxAcquireTrainingset;
int _n_pictureAcquireTrainingSet;
int _angle_incAcquireTrainingSet;

int _n_pictureRecognizeImage;
int _nMaxpictureRecognizeImage;
int _angle_incRecognizeImage;

int _n_concept;
float _speed;
UIImage *_image;
NSString *_ip_address;
NSString *_ApiKey;
ClarifaiApp *_app;
NSArray *_concept;
NSArray *_conceptArray;
NSString *_modelName;
NSMutableArray *_pTagResult;

BOOL forward      = false;
BOOL backward     = false;
BOOL stop         = true;
BOOL right        = false;
BOOL left         = false;
BOOL stop_turning = true;
BOOL oneeighty    = false;
BOOL ninety       = false;
BOOL research_180 = false;
BOOL research_90  = false;
BOOL go_back      = false;

@interface ViewController : UIViewController

@property(nonatomic, retain) AVCaptureStillImageOutput *stillImageOutput;
@property (strong, nonatomic) IBOutlet UIView *imagePreview;

- (IBAction)kickstandsDeploy:(id)sender;
- (IBAction)kickstandsRetract:(id)sender;

- (IBAction)poleUp:(id)sender;
- (IBAction)poleStop:(id)sender;
- (IBAction)poleDown:(id)sender;

- (IBAction)moveForward:(id)sender;
- (IBAction)moveBackward:(id)sender;
- (IBAction)stopMotion:(id)sender;
- (IBAction)turnRight:(id)sender;
- (IBAction)turnLeft:(id)sender;

- (IBAction)connectToServer:(id)sender;

@end

