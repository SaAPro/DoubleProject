//
//  CAIEmbedding.h
//  Clarifai-Apple-SDK
//
//  Copyright © 2017 Clarifai. All rights reserved.
//

#import <Foundation/Foundation.h>

#pragma mark - CAIEmbedding
NS_SWIFT_NAME(Embedding)
@interface CAIEmbedding : NSObject <NSCoding>

@property (nonatomic, strong, readonly) NSArray<NSNumber *> *values;

@end

#pragma mark - CAIEmbeddingPacker
@interface CAIEmbeddingPacker : NSObject
/** Returns a new packer for embeddings of a given dimension. */
+ (CAIEmbeddingPacker *)standardPackerForDimension:(NSInteger)dimension;

/** Initializes with range parameters and whether or not to unit norm vectors. */
- (instancetype)initWithMinValue:(float)min maxValue:(float)max normalize:(BOOL)normalize;

/**
 * Returns a packed embedding from an array of NSNumbers.
 * @param numbers an array of NSNumbers to be packed
 */
- (NSData *)packEmbeddingFromNumbers:(NSArray<NSNumber *> *)numbers;

/**
 Returns data from an array of NSNumbers, unpacked.
 */
+ (NSData *)embeddingDataFromNumbers:(NSArray *)numbers;

@end


#pragma mark - CAIEmbeddingUnpacker
/** Unpacks packed embeddings. This class is NOT thread-safe. */
@interface CAIEmbeddingUnpacker : NSObject

/** Returns a new unpacker for embeddings of a given dimension. */
+ (CAIEmbeddingUnpacker *)standardUnpackerForDimension:(NSInteger)dimension;

/** Initializes with range parameters. */
- (instancetype)initWithMinValue:(float)min maxValue:(float)max;

/** Unpacks a packed embedding into a new, appropriately-sized NSData containing floats. */
- (NSData *)unpackEmbeddingIntoData:(NSData *)packed;

@end

#pragma mark - CAIEmbeddingArchiver
@interface CAIEmbeddingArchiver : NSObject

+ (NSData *)dataFromEmbedding:(NSArray<NSNumber *> *)embeddings;

+ (void)enumerateNegatives:(NSUInteger)numberOfIterations enumerationBlock:(void (^)(NSData *negativeEmbeddingData, NSUInteger idx, BOOL *stop))enumerationBlock;

@end
