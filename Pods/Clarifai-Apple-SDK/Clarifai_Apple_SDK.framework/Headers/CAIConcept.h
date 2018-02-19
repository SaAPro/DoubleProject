//
//  CAIConcept.h
//  Clarifai-Apple-SDK
//
//  Copyright © 2017 Clarifai. All rights reserved.
//

#import "CAIDataModel.h"

/** Concept is used to describe an attribute of a data asset.
 */
NS_SWIFT_NAME(Concept)
@interface CAIConcept : CAIDataModel <NSCoding>

/// Concept's unique id.
@property (nonatomic, strong, nonnull) NSString *conceptId NS_SWIFT_NAME(id);

/// Creation time expressed in seconds since epoch time.
@property (nonatomic) NSTimeInterval createdAt;

/// Creation date.
@property (nonatomic, strong, nullable) NSDate *createdDate;

/// The language in which the concept name is in.
@property (nonatomic, strong, nonnull) NSString *language;

/// Concept's name in the given language.
@property (nonatomic, strong, null_resettable) NSString *name;

/// Used to indicate the score associated with the concept.
@property (nonatomic) float score;

/** Initializer
 @param conceptId Concept's unique id.
 @param name Concept's name in the given language.
 @returns An instance of Concept
 */
- (nonnull instancetype)initWithId:(nonnull NSString *)conceptId name:(nullable NSString *)name NS_SWIFT_NAME(init(id:name:));

/** Initializer
 @param conceptId Concept's unique id.
 @param name Concept's name in the given language.
 @param score The score associated with the concept.
 @returns An instance of Concept
 */
- (nonnull instancetype)initWithId:(nonnull NSString *)conceptId name:(nullable NSString *)name score:(float)score NS_SWIFT_NAME(init(id:name:score:));

@end
