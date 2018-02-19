//
//  CAIEvaluationMetrics.h
//  Clarifai-Apple-SDK
//
//  Copyright © 2017 Clarifai. All rights reserved.
//

#import <Foundation/Foundation.h>

@class CAIBinaryMetrics;
@class CAIConfusionMatrix;
@class CAICooccurrenceMatrix;
@class CAILabelDistribution;
@class CAIMetricsSummary;
@class CAIStatus;

NS_SWIFT_NAME(EvaluationMetrics)
@interface CAIEvaluationMetrics : NSObject

@property (nonatomic, strong, nullable, readonly) NSArray<CAIBinaryMetrics *> *binaryMetrics;

@property (nonatomic, strong, nullable, readonly) CAIConfusionMatrix *confusionMatrix;

@property (nonatomic, strong, nullable, readonly) CAICooccurrenceMatrix *cooccurrences;

@property (nonatomic, strong, nullable, readonly) CAILabelDistribution *labelDistributions;

@property (nonatomic, strong, nullable, readonly) CAIStatus *status;

@property (nonatomic, strong, nullable, readonly) CAIMetricsSummary *summary;

@end
