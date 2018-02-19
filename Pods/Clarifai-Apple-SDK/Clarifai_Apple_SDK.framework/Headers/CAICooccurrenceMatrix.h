//
//  CAICooccurrenceMatrix.h
//  Clarifai-Apple-SDK
//
//  Copyright © 2017 Clarifai. All rights reserved.
//

#import <Foundation/Foundation.h>

#pragma mark - Co-occurrence matrix entry
NS_SWIFT_NAME(CooccurrenceMatrixEntry)
@interface CAICooccurrenceMatrixEntry : NSObject

/// Concept id for the row
@property (nonatomic, strong, nonnull, readonly) NSString *conceptRow;

/// Concept id for the column
@property (nonatomic, strong, nonnull, readonly) NSString *conceptColumn;
@property (nonatomic, readonly) NSUInteger count;

@end


#pragma mark - Co-occurrence matrix
NS_SWIFT_NAME(CooccurrenceMatrix)
@interface CAICooccurrenceMatrix : NSObject

@property (nonatomic, strong, nullable, readonly) NSArray<CAICooccurrenceMatrixEntry *> *cooccurrences;
@property (nonatomic, strong, nullable, readonly) NSArray<NSString *> *conceptsOrder;

@end
