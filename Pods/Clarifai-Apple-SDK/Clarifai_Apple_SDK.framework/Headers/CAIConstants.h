//
//  CAIConstants.h
//  Clarifai-Apple-SDK
//
//  Copyright © 2017 Clarifai. All rights reserved.
//

#ifndef Clarifai_Apple_SDK_CAIConstants_h
#define Clarifai_Apple_SDK_CAIConstants_h

#import <Foundation/Foundation.h>

/// Notification broadcasted right before fetching of a model begins. The model's unique identifier is included in the payload (userInfo) of the notification.
extern NSString * const CAIWillFetchModelNotification;

/// Notification broadcasted immediately after fetching a model. The model's unique identifier is included in the payload (userInfo) of the notification.
extern NSString * const CAIDidFetchModelNotification;

/// Notification broadcasted when a fetched model has become available to use. The model's unique identifier is included in the payload (userInfo) of the notification.
extern NSString * const CAIModelDidBecomeAvailableNotification;

/// Notification broadcasted when the SDK has finished initializing
extern NSString * const CAIDidFinishInitializingNotification;

/// Notification broadcasted when the authentication state of the SDK changes or is renewed
extern NSString * const CAIAuthenticationNotification;

/// Key to the authentication type in the payload (userInfo) of an authentication notification
extern NSString * const CAIAuthenticationTypeKey;

/// Notification broadcasted when the SDK budget usage reaches certain thresholds
extern NSString * const CAIUsageNotification;

/// Key to the current usage level of the SDK budget
extern NSString * const CAIUsageLevelKey;

/// Key to the current budget for usage of the SDK
extern NSString * const CAIUsageBudgetKey;

/// Key to a model's unique identier in payload (userInfo) of a notification.
extern NSString * const CAIModelUniqueIdentifierKey;

extern NSString * const CAIWillDownloadGeneralModelNotification __attribute__((deprecated("use CAIWillFetchModelNotification instead")));

extern NSString * const CAIDidDownloadGeneralModelNotification __attribute__((deprecated("use CAIDidFetchModelNotification instead")));

extern NSString * const CAIGeneralModelDidBecomeAvailableNotification __attribute__((deprecated("use CAIModelDidBecomeAvailableNotification instead")));

typedef NS_ENUM(NSUInteger, CAILogLevel) {
    /// Nothing is displayed on the console
    CAILogLevelNone = 0,
    /// Only errors are displayed on the console
    CAILogLevelErrors,
    /// Warnings and errors are displayed on the console
    CAILogLevelWarnings,
    /// Debug information is shown, plus warnings and errors
    CAILogLevelDebug,
    /// Detailed information is shown, plus debug, warnings, and errors
    CAILogLevelVerbose
} NS_SWIFT_NAME(LogLevel);

typedef NS_ENUM(NSUInteger, CAISDKStatus) {
    /// The SDK has not been initialized
    CAISDKStatusNotInitialized = 0,
    /// Initialization has started, but has not finished yet
    CAISDKStatusInitializing,
    /// The SDK is initialized and ready for use
    CAISDKStatusInitialized
} NS_SWIFT_NAME(SDKStatus);

typedef NS_ENUM(NSUInteger, CAINetworkConstraint) {
    /// Syncing with the server happens anytime an internet connection of any type is available.
    CAINetworkConstraintNone = 0,
    /// Syncing with the server only happens over wifi connections.
    CAINetworkConstraintWiFiOnly
} NS_SWIFT_NAME(NetworkConstraint);

typedef NS_ENUM(NSUInteger, CAIAuthenticationType) {
    /// Authentication failed or there is no network connectivity
    CAIAuthenticationTypeUnknown = 0,
    /// Authentication granted to a valid API Key
    CAIAuthenticationTypeGranted = 1,
    /// Authentication denied. Perhaps an invalid API Key or a revoked one
    CAIAuthenticationTypeDenied = 2
} NS_SWIFT_NAME(AuthenticationType);

#endif
