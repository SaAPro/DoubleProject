//
//  CAIInput.h
//  Clarifai-Apple-SDK
//
//  Copyright © 2017 Clarifai. All rights reserved.
//

#import "CAIDataModel.h"

@class CAIDataAsset;
@class CAIStatus;

/** Input contains assets associated with Concepts and is fed to a Model to
 either train it or for the Model to predict what is the Input.
 */
NS_SWIFT_NAME(Input)
@interface CAIInput : CAIDataModel <NSCoding>

/// Creation time expressed in seconds since epoch time.
@property (nonatomic, readonly) NSTimeInterval createdAt;

/// Creation date.
@property (nonatomic, strong, nonnull, readonly) NSDate *createdDate;

/// DataAsset associated with the Input.
@property (nonatomic, strong, nonnull) CAIDataAsset *dataAsset;

/// Modified time expressed in seconds since epoch time.
@property (nonatomic) NSTimeInterval modifiedAt;

/// Modified date.
@property (nonatomic, strong, nullable, readonly) NSDate *modifiedDate;

/// Input's unique id.
@property (nonatomic, strong, nonnull) NSString *inputId NS_SWIFT_NAME(id);

/// Input's status.
@property (nonatomic, strong, nonnull, readonly) CAIStatus *status;

/** Initializer
 @param dataAsset An instance of DataAsset
 @returns An instance of Input
 */
- (nonnull instancetype)initWithDataAsset:(nonnull CAIDataAsset *)dataAsset NS_SWIFT_NAME(init(dataAsset:));

@end
