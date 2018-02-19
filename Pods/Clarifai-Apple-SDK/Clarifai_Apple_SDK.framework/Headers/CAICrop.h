//
//  CAICrop.h
//  Clarifai-Apple-SDK
//
//  Copyright © 2017 Clarifai. All rights reserved.
//

#import <Foundation/Foundation.h>

/** Crop is used to limit the region of interest.

 If an image is too large and the region of interest is at the center-right of the image, you may want to crop the other parts of the image.
 */
NS_SWIFT_NAME(Crop)
@interface CAICrop : NSObject <NSCoding>

/// Distance, as a percentage, from the top margin of the image where cropping should take place
@property (nonatomic) float top;

/// Distance, as a percentage, from the left margin of the image where cropping should take place
@property (nonatomic) float left;

/// Distance, as a percentage, from the bottom margin of the image where cropping should take place
@property (nonatomic) float bottom;

/// Distance, as a percentage, from the right margin of the image where cropping should take place
@property (nonatomic) float right;

- (nonnull instancetype)init;

/** Initialize Crop with the cropping parameters. Values must be between 0 and 1
 @param top Distance, as a percentage, from the top of the image where cropping should take place
 @param left Distance, as a percentage, from the left of the image where cropping should take place
 @param bottom Distance, as a percentage, from the bottom of the image where cropping should take place
 @param right Distance, as a percentage, from the right of the image where cropping should take place
 @returns An instance of crop
 */
- (nonnull instancetype)initWithTop:(float)top left:(float)left bottom:(float)bottom right:(float)right NS_SWIFT_NAME(init(top:left:bottom:right:));

@end
