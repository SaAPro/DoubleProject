//
//  CAILabelDistribution.h
//  Clarifai-Apple-SDK
//
//  Copyright © 2017 Clarifai. All rights reserved.
//

#import <Foundation/Foundation.h>

#pragma mark - Label count
NS_SWIFT_NAME(LabelCount)
@interface CAILabelCount : NSObject

@property (nonatomic, strong, nullable, readonly) NSString *conceptName;

@property (nonatomic, readonly) NSUInteger count;

@end

#pragma mark - Label distribution
NS_SWIFT_NAME(LabelDistribution)
@interface CAILabelDistribution : NSObject

@property (nonatomic, strong, nullable, readonly) NSArray<CAILabelCount *> *positiveLabelsCount;

@end
