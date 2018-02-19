//
//  CAIRoc.h
//  Clarifai-Apple-SDK
//
//  Copyright © 2017 Clarifai. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_SWIFT_NAME(Roc)
@interface CAIRoc : NSObject

@property (nonatomic, strong, nullable, readonly) NSArray<NSNumber *> *fprs;

@property (nonatomic, strong, nullable, readonly) NSArray<NSNumber *> *tprs;

@property (nonatomic, strong, nullable, readonly) NSArray<NSNumber *> *thresholds;

@end
