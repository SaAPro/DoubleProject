//
//  CAIDataAsset.h
//  Clarifai-Apple-SDK
//
//  Copyright © 2017 Clarifai. All rights reserved.
//

#import <Foundation/Foundation.h>

@class CAIConcept;
@class CAIEmbedding;
@class CAIImage;

typedef NS_ENUM(NSUInteger, CAIDataAssetType) {
    CAIDataAssetTypeImage = 0,
    CAIDataAssetTypeVideo
} NS_SWIFT_NAME(DataAssetType);


NS_SWIFT_NAME(DataAsset)
@interface CAIDataAsset : NSObject <NSCoding>

@property (nonatomic, strong, nullable, readonly) NSArray<CAIConcept *> *concepts;
@property (nonatomic, strong, null_resettable) CAIImage *image;
@property (nonatomic, strong, nullable, readonly) NSDictionary<NSString *, id> *metadata;
@property (nonatomic) CAIDataAssetType type;

- (nonnull instancetype)initWithImage:(nullable CAIImage *)image NS_SWIFT_NAME(init(image:));
- (void)addConcepts:(nonnull NSArray<CAIConcept *> *)concepts NS_SWIFT_NAME(add(concepts:));
- (void)addMetadata:(nonnull NSDictionary<NSString *, id> *)metadata NS_SWIFT_NAME(add(metadata:));
- (void)clearConcepts;
- (void)clearMetadata;
- (void)embeddings:(void (^ _Nonnull)(NSArray<CAIEmbedding *> * _Nullable embeddings))completionHandler;
- (void)removeConcepts:(nonnull NSArray<CAIConcept *> *)concept NS_SWIFT_NAME(remove(concepts:));
- (void)removeMetadata:(nonnull NSDictionary<NSString *, id> *)metadata NS_SWIFT_NAME(remove(metadata:));

@end
