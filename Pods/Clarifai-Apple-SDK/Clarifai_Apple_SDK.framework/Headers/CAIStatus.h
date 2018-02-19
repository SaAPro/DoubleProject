//
//  CAIStatus.h
//  Clarifai-Apple-SDK
//
//  Copyright © 2017 Clarifai. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CAIStatusCode.h"

NS_SWIFT_NAME(Status)
@interface CAIStatus : NSObject

/// Status code
@property (nonatomic) CAIStatusCode code;

/// Description of the status
@property (nonatomic, strong, nonnull) NSString *message;

/// Detailed description of the status
@property (nonatomic, strong, nonnull) NSString *details;

/** Initializer
 @param code Status code
 @param message Description of the status
 @returns An instance os Status
 */
- (nonnull instancetype)initWithCode:(CAIStatusCode)code message:(nonnull NSString *)message NS_SWIFT_NAME(init(code:message:));

/** Initializer
 @param code Status code
 @param message Description of the status
 @param details Detailed description of the status (Optional)
 @returns An instance os Status
 */
- (nonnull instancetype)initWithCode:(CAIStatusCode)code message:(nonnull NSString *)message details:(nullable NSString *)details NS_SWIFT_NAME(init(code:message:details:));

@end
