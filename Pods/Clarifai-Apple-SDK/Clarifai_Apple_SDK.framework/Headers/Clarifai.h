//
//  Clarifai.h
//  Clarifai-Apple-SDK
//
//  Copyright © 2017 Clarifai. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CAIConstants.h"
#import "CAIDataModel.h"

@class CAIModel;

@interface Clarifai : NSObject

/// Returns an instance of the general model
@property (nonatomic, strong, nonnull, readonly) CAIModel *generalModel;

/// Specifies the log level output to the console
@property (nonatomic, unsafe_unretained) CAILogLevel logLevel;

/// Specifies the initialization status of the SDK
@property (nonatomic, unsafe_unretained, readonly) CAISDKStatus sdkStatus;

/// Defines network communication constraints. Default value is no constraint
@property (nonatomic, unsafe_unretained) CAINetworkConstraint networkConstraint;

/// Singleton instance
+ (nonnull instancetype)sharedInstance;

- (void)deleteEntities:(nonnull NSArray<CAIDataModel *> *)entities NS_SWIFT_NAME(delete(entities:));

- (void)loadEntityId:(nonnull NSString *)entityId entityType:(CAIEntityType)entityType completionHandler:(void (^ _Nonnull)(CAIDataModel * _Nullable entity, NSError * _Nullable error))completionHandler NS_SWIFT_NAME(load(entityId:entityType:completionHandler:));

- (void)loadEntityId:(nonnull NSString *)entityId versionId:(nullable NSString *)versionId entityType:(CAIEntityType)entityType completionHandler:(void (^ _Nonnull)(CAIDataModel * _Nullable entity, NSError * _Nullable error))completionHandler NS_SWIFT_NAME(load(entityId:versionId:entityType:completionHandler:));

- (void)loadEntityType:(CAIEntityType)entityType range:(NSRange)range completionHandler:(void (^ _Nonnull)(NSArray<CAIDataModel *> * _Nullable entities, NSError * _Nullable error))completionHandler NS_SWIFT_NAME(load(entityType:range:completionHandler:));

- (void)saveEntities:(nonnull NSArray<CAIDataModel *> *)entities NS_SWIFT_NAME(save(entities:));

- (void)startWithApiKey:(nonnull NSString *)apiKey NS_SWIFT_NAME(start(apiKey:));

- (void)startWithAppKey:(nonnull NSString *)appKey NS_SWIFT_NAME(start(appKey:)) __attribute__((deprecated("use start(apiKey:)/startWithApiKey: instead")));

@end
