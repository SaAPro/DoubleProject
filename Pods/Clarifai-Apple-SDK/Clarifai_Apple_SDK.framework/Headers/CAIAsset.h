//
//  CAIAsset.h
//  Clarifai-Apple-SDK
//
//  Copyright © 2017 Clarifai. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_SWIFT_NAME(Asset)
@interface CAIAsset : NSObject <NSCoding>

/// String with the Base64 representation of the asset
@property (nonatomic, strong, nullable) NSString *base64;

/// String representation of the asset's URL
@property (nonatomic, strong, nullable) NSURL *url;

@end
