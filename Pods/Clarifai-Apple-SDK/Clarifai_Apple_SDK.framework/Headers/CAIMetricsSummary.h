//
//  CAIMetricsSummary.h
//  Clarifai-Apple-SDK
//
//  Copyright © 2017 Clarifai. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_SWIFT_NAME(MetricsSummary)
@interface CAIMetricsSummary : NSObject

@property (nonatomic) float top1Accuracy;

@property (nonatomic) float top5Accuracy;

@property (nonatomic) float macroAvgRocAuc;

@property (nonatomic) float macroStdRocAuc;

@property (nonatomic) float macroAvgF1Score;

@property (nonatomic) float macroStdF1Score;

@property (nonatomic) float macroAvgPrecision;

@property (nonatomic) float macroAvgRecall;

@end
