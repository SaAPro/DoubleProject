//
//  CAIModelVersion.h
//  Clarifai-Apple-SDK
//
//  Copyright © 2017 Clarifai. All rights reserved.
//

#import <Foundation/Foundation.h>

@class CAIEvaluationMetrics;
@class CAIStatus;

NS_SWIFT_NAME(ModelVersion)
@interface CAIModelVersion : NSObject <NSCoding>

/// Number of active convepts associated with this version of the Model.
@property (nonatomic, readonly) NSUInteger activeConceptCount;

/// Creation time expressed in seconds since epoch time.
@property (nonatomic, readonly) NSTimeInterval createdAt;

/// Creation date.
@property (nonatomic, strong, nullable, readonly) NSDate *createdDate;

/// Evaluation metrics of the model version.
@property (nonatomic, strong, nullable, readonly) CAIEvaluationMetrics *evaluationMetrics;

/// ModelVersion's unique id.
@property (nonatomic, strong, nonnull) NSString *modelVersionId NS_SWIFT_NAME(id);

/** The status of the version.

 Example of a few possible values: Status.code.modelUntrained, Status.code.modelTraining, Status.code.modelTrained
 */
@property (nonatomic, strong, nonnull) CAIStatus *status;

@end
