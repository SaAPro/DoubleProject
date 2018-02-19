//
//  CAIModel.h
//  Clarifai-Apple-SDK
//
//  Copyright © 2017 Clarifai. All rights reserved.
//

#import "CAIDataModel.h"

@class CAIConcept;
@class CAIInput;
@class CAIModelVersion;
@class CAIOutput;

NS_SWIFT_NAME(Model)
@interface CAIModel : CAIDataModel <NSCoding>

/// The app id the model is associated with.
@property (nonatomic, strong, nullable) NSString *appId;

/// Creation time expressed in seconds since epoch time.
@property (nonatomic) NSTimeInterval createdAt;

/// Creation date.
@property (nonatomic, strong, nullable) NSDate *createdDate;

/// Model's unique id.
@property (nonatomic, strong, nonnull) NSString *modelId NS_SWIFT_NAME(id);

/// Model's name. It can have spaces and special characters.
@property (nonatomic, strong, nonnull) NSString *name;

/// Info about the model's output and configuration.
@property (nonatomic, strong, nullable) CAIOutput *output;

/// Indicates the version of the model.
@property (nonatomic, strong, nonnull) CAIModelVersion *version;

- (nonnull instancetype)initWithId:(nullable NSString *)modelId name:(nullable NSString *)name NS_SWIFT_NAME(init(id:name:));

- (void)predict:(nonnull NSArray<CAIInput *> *)inputs completionHandler:(void (^ _Nonnull)(NSArray<CAIOutput *> * _Nullable outputs, NSError * _Nullable error))completionHandler;

- (void)trainWithConcepts:(nonnull NSArray<CAIConcept *> *)concepts completionHandler:(void (^ _Nonnull)(NSError * _Nullable error))completionHandler NS_SWIFT_NAME(train(concepts:completionHandler:));

- (void)trainWithConcepts:(nonnull NSArray<CAIConcept *> *)concepts inputs:(nonnull NSArray<CAIInput *> *)inputs completionHandler:(void (^ _Nonnull)(NSError * _Nullable error))completionHandler NS_SWIFT_NAME(train(concepts:inputs:completionHandler:));

- (void)trainWithInputs:(nonnull NSArray<CAIInput *> *)inputs completionHandler:(void (^ _Nonnull)(NSError * _Nullable error))completionHandler NS_SWIFT_NAME(train(inputs:completionHandler:));

- (void)update:(void (^ _Nonnull)(NSError * _Nullable error))completionHandler;

@end
