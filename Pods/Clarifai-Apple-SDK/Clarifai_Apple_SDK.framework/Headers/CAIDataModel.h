//
//  CAIDataModel.h
//  Clarifai-Apple-SDK
//
//  Copyright © 2017 Clarifai. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, CAIEntityType) {
    CAIEntityTypeUnknown = 0,
    CAIEntityTypeConcept,
    CAIEntityTypeInput,
    CAIEntityTypeModel,
    CAIEntityTypeOutput,
    CAIEntityTypeSearchResult
} NS_SWIFT_NAME(EntityType);

NS_SWIFT_NAME(DataModel)
@interface CAIDataModel : NSObject <NSCoding> {
@protected
    CAIEntityType _entityType;
}

@property (nonatomic, readonly) CAIEntityType entityType;

- (nonnull instancetype)initWithEntityType:(CAIEntityType)entityType;

@end
