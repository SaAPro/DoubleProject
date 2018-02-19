//
//  CAIOutputConfiguration.h
//  Clarifai-Apple-SDK
//
//  Copyright © 2017 Clarifai. All rights reserved.
//

#import <Foundation/Foundation.h>

@class CAIConcept;

NS_SWIFT_NAME(OutputConfiguration)
@interface CAIOutputConfiguration : NSObject <NSCoding>

/// Flag indicating whether the concept predictions must sum to 1.
@property (nonatomic) BOOL conceptsMutuallyExclusive;

/// Flag indicating whether negatives should only be sampled from within the app during training, for custom models.
@property (nonatomic) BOOL closedEnvironment;

/// For custom models, this is the base model to use for image embeddings. Default is general model.
@property (nonatomic, strong, nonnull) NSString *existingModelId;

/// Overrides the default_language for the app in a predict call.
@property (nonatomic, strong, nonnull) NSString *language;

/// Hyper-parameters for custom training.
@property (nonatomic, strong, nonnull) NSString *hyperParameters;

/// Maximum number of concepts in result.
@property (nonatomic) NSUInteger maxConcepts;

/// Minimum value of concept's probability score in result. Score must be between 0 and 1.
@property (nonatomic) float minScore;

/// Select concepts in result.
@property (nonatomic, strong, nullable) NSArray<CAIConcept *> *selectedConcepts;

@end
