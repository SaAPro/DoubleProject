//
//  CAIPrecisionRecallCurve.h
//  Clarifai-Apple-SDK
//
//  Copyright © 2017 Clarifai. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_SWIFT_NAME(PrecisionRecallCurve)
@interface CAIPrecisionRecallCurve : NSObject

@property (nonatomic, strong, nullable, readonly) NSArray<NSNumber *> *recalls;

@property (nonatomic, strong, nullable, readonly) NSArray<NSNumber *> *precisions;

@property (nonatomic, strong, nullable, readonly) NSArray<NSNumber *> *thresholds;

@end
