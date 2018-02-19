//
//  CAIOutput.h
//  Clarifai-Apple-SDK
//
//  Copyright © 2017 Clarifai. All rights reserved.
//

#import "CAIDataModel.h"

@class CAIDataAsset;
@class CAIOutputConfiguration;
@class CAIStatus;

NS_SWIFT_NAME(Output)
@interface CAIOutput : CAIDataModel <NSCoding>

/// Output configuration with regards to the Model
@property (nonatomic, strong, nonnull, readonly) CAIOutputConfiguration *configuration;

/// DataAsset associated with the Output
@property (nonatomic, strong, nonnull, readonly) CAIDataAsset *dataAsset;

/// Helps to know what type of DataAsset to expect out of the model.
@property (nonatomic, strong, nonnull, readonly) NSString *type;

/// Extra information about the type.
@property (nonatomic, strong, nonnull, readonly) NSString *typeExtra;

- (nonnull instancetype)initWithDataAsset:(nonnull CAIDataAsset *)dataAsset configuration:(nonnull CAIOutputConfiguration *)configuration NS_SWIFT_NAME(init(dataAsset:configuration:));

@end
