//
//  CAIConfusionMatrix.h
//  Clarifai-Apple-SDK
//
//  Copyright © 2017 Clarifai. All rights reserved.
//

#import <Foundation/Foundation.h>

#pragma mark - Confusion matrix entry
NS_SWIFT_NAME(ConfusionMatrixEntry)
@interface CAIConfusionMatrixEntry : NSObject

@property (nonatomic, strong, nonnull, readonly) NSString *predicted;
@property (nonatomic, strong, nonnull, readonly) NSString *actual;
@property (nonatomic, readonly) float score;

@end


#pragma mark - Confusion matrix
NS_SWIFT_NAME(ConfusionMatrix)
@interface CAIConfusionMatrix : NSObject

@property (nonatomic, strong, nonnull, readonly) NSArray<NSString *> *conceptsOrder;
@property (nonatomic, strong, nullable, readonly) NSArray<CAIConfusionMatrixEntry *> *confusionEntries;

@end
