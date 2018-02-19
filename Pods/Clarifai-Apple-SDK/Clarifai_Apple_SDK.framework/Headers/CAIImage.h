//
//  CAIImage.h
//  Clarifai-Apple-SDK
//
//  Copyright © 2017 Clarifai. All rights reserved.
//

#import "CAIAsset.h"
#import <UIKit/UIKit.h>

@class CAICrop;

/**
 Image is used to represent an image in a DataAsset
 */
NS_SWIFT_NAME(Image)
@interface CAIImage : CAIAsset <NSCoding>

/// Flag indicating if the same image may have more than one URL associated with it
@property (nonatomic) BOOL allowDuplicateURL;

/// Limits the region of interest.
@property (nonatomic, strong, nonnull) CAICrop *crop;

/// An instance of UIImage
@property (nonatomic, strong, nullable) UIImage *image;

/** Initializes Image with an UIImage
 @param image An instance of UIImage
 @returns An instace of image
 */
- (nonnull instancetype)initWithImage:(nullable UIImage *)image NS_SWIFT_NAME(init(image:));

/** Initializes Image with an UIImage
 @param url A URL with the location of the image
 @returns An instace of image
 */
- (nonnull instancetype)initWithURL:(nullable NSURL *)url NS_SWIFT_NAME(init(url:));

@end
