//
//  CAIBinaryMetrics.h
//  Clarifai-Apple-SDK
//
//  Copyright © 2017 Clarifai. All rights reserved.
//

#import <Foundation/Foundation.h>

@class CAIConcept;
@class CAIPrecisionRecallCurve;
@class CAIRoc;

NS_SWIFT_NAME(BinaryMetrics)
@interface CAIBinaryMetrics : NSObject

@property (nonatomic, strong, nullable, readonly) CAIConcept *concept;

@property (nonatomic, readonly) float f1;

@property (nonatomic, readonly) NSUInteger numberOfNegatives;

@property (nonatomic, readonly) NSUInteger numberOfPositives;

@property (nonatomic, strong, nullable, readonly) CAIPrecisionRecallCurve *precisionRecallCurve;

@property (nonatomic, readonly) float rocAuc;

@property (nonatomic, strong, nullable, readonly) CAIRoc *rocCurve;

@property (nonatomic, readonly) NSUInteger totalNumber;

@end
