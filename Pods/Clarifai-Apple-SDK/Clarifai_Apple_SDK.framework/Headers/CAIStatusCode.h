//
//  CAIStatusCode.h
//  Clarifai-Apple-SDK
//
//  Copyright © 2017 Clarifai. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, CAIStatusCode) {
    CAIStatusCodeZero = 0,

    /** success */
    CAIStatusCodeSuccess = 10000,
    CAIStatusCodeMixedStatus = 10010,

    /**
     * SUCCESS_WARNING_API_DEPRECATED = 10001;
     * SUCCESS_WARNING_CLIENT_DEPRECATED = 10002;
     **/
    CAIStatusCodeFailure = 10020,

    /** Clarifai Connection Codes: 11xxx */
    CAIStatusCodeConnAccountIssues = 11000,

    /** invalid auth token used */
    CAIStatusCodeConnTokenInvalid = 11001,

    /** invalid auth credentials */
    CAIStatusCodeConnCredentialsInvalid = 11002,

    /** throttle hourly limit exceeded */
    CAIStatusCodeConnExceedHourlyLimit = 11003,

    /** throttle monthly limit exceeded */
    CAIStatusCodeConnExceedMonthlyLimit = 11004,

    /** throttler and billing stuff */
    CAIStatusCodeConnThrottled = 11005,

    /** throttler and billing stuff */
    CAIStatusCodeConnExceedsLimits = 11006,

    /** api key has insufficient permissions */
    CAIStatusCodeConnInsufficientScopes = 11007,

    /** api key is invalid */
    CAIStatusCodeConnKeyInvalid = 11008,

    /** api key not found */
    CAIStatusCodeConnKeyNotFound = 11009,

    /** multipart form parsing, broken json, etc */
    CAIStatusCodeConnBadRequestFormat = 11100,

    /** when path is bad */
    CAIStatusCodeConnDoesNotExist = 11101,

    /** something wrong with a header */
    CAIStatusCodeConnInvalidRequest = 11102,

    /** when a request method is not allowed */
    CAIStatusCodeConnMethodNotAllowed = 11103,

    /** Model/Custom Training related 20xxx */
    CAIStatusCodeModelTrained = 21100,

    /** Custom model is currently training. */
    CAIStatusCodeModelTraining = 21101,

    /** Custom model has not yet been trained. */
    CAIStatusCodeModelUntrained = 21102,

    /** Custom model is currently in queue for training, waiting on assets to process first. */
    CAIStatusCodeModelQueuedForTraining = 21103,

    /** Custom model training had no data. */
    CAIStatusCodeModelTrainingNoData = 21110,

    /** Custom model training had no positive examples. */
    CAIStatusCodeModelTrainingNoPositives = 21111,

    /** Custom model training was ONE_VS_N but with a single class. */
    CAIStatusCodeModelTrainingOneVsNSingleClass = 21112,

    /** Training took longer than hard coded timeouts. */
    CAIStatusCodeModelTrainingTimedOut = 21113,

    /** Training got error waiting on asset pipeline to finish. */
    CAIStatusCodeModelTrainingWaitingError = 21114,

    /** Training threw an unknown exception. */
    CAIStatusCodeModelTrainingUnknownError = 21115,

    /** Training message was redelivered. */
    CAIStatusCodeModelTrainingMsgRedeliver = 21116,
    CAIStatusCodeModelModifySuccess = 21150,
    CAIStatusCodeModelModifyPending = 21151,
    CAIStatusCodeModelModifyFailed = 21152,
    CAIStatusCodeModelDoesNotExist = 21200,
    CAIStatusCodeModelPermissionDenied = 21201,
    CAIStatusCodeModelInvalidArgument = 21202,
    CAIStatusCodeModelInvalidRequest = 21203,
    CAIStatusCodeModelEvaluated = 21300,
    CAIStatusCodeModelEvaluating = 21301,
    CAIStatusCodeModelNotEvaluated = 21302,
    CAIStatusCodeModelQueuedForEvaluation = 21303,

    /** Evaluation took longer than hard coded timeouts. */
    CAIStatusCodeModelEvaluationTimedOut = 21310,

    /** Evaluation got error waiting on asset pipeline to finish. */
    CAIStatusCodeModelEvaluationWaitingError = 21311,

    /** EVALUATION THREW AN UNKNOWN EXCEPTION. */
    CAIStatusCodeModelEvaluationUnknownError = 21312,
    CAIStatusCodeModelPredictionFailed = 21313,

    /** Eval message was redelivered. */
    CAIStatusCodeModelEvaluationMsgRedeliver = 21314,

    /** Don't have enough concepts labelled to perform evaluation */
    CAIStatusCodeModelEvaluationNeedLabels = 21315,

    /** specified model input not in workflow */
    CAIStatusCodeWorkflowNoMatchingInput = 22001,

    /** specified model must be trained */
    CAIStatusCodeWorkflowRequireTrainedModel = 22002,
    CAIStatusCodeWorkflowDuplicate = 22100,
    CAIStatusCodeWorkflowUnsupportedFormat = 22101,
    CAIStatusCodeWorkflowDoesNotExist = 22102,
    CAIStatusCodeWorkflowPermissionDenied = 22103,

    /** error in the request somewhere */
    CAIStatusCodeWorkflowInvalidArgument = 22104,

    /** error in the request somewhere */
    CAIStatusCodeWorkflowInvalidRequest = 22999,
    CAIStatusCodeWorkflowModifySuccess = 22150,
    CAIStatusCodeWorkflowModifyPending = 22151,
    CAIStatusCodeWorkflowModifyFailed = 22152,

    /** Input:Image related 30xxx */
    CAIStatusCodeInputImageDownloadSuccess = 30000,

    /** when things are async, this is the default status. */
    CAIStatusCodeInputImageDownloadPending = 30001,

    /** any type of error downloading and processing */
    CAIStatusCodeInputImageDownloadFailed = 30002,
    CAIStatusCodeInputImageDuplicate = 30100,
    CAIStatusCodeInputImageUnsupportedFormat = 30101,
    CAIStatusCodeInputImageDoesNotExist = 30102,
    CAIStatusCodeInputImagePermissionDenied = 30103,
    CAIStatusCodeInputImageInvalidArgument = 30104,
    CAIStatusCodeInputImageModifySuccess = 30200,
    CAIStatusCodeInputImageModifyPending = 30201,
    CAIStatusCodeInputImageModifyFailed = 30203,
    CAIStatusCodeAllInputImagesInvalidBytes = 30300,

    /** Input:Video related 31xxx */
    CAIStatusCodeInputVideoDownloadSuccess = 31000,
    CAIStatusCodeInputVideoDownloadPending = 31001,
    CAIStatusCodeInputVideoDownloadFailed = 31002,
    CAIStatusCodeInputVideoDuplicate = 31100,
    CAIStatusCodeInputVideoUnsupportedFormat = 31101,
    CAIStatusCodeInputVideoDoesNotExist = 31102,
    CAIStatusCodeInputVideoPermissionDenied = 31103,
    CAIStatusCodeInputVideoInvalidArgument = 31104,
    CAIStatusCodeInputVideoModifySuccess = 31200,
    CAIStatusCodeInputVideoModifyPending = 31201,
    CAIStatusCodeInputVideoModifyFailed = 31203,
    CAIStatusCodeInputWritesDisabledForMaintenance = 39998,
    CAIStatusCodeInputInvalidRequest = 39999,

    /** Other related 40xxx */
    CAIStatusCodePredictInvalidRequest = 40001,
    CAIStatusCodeConceptsInvalidRequest = 40003,
    CAIStatusCodeDatabaseDuplicateKey = 40010,
    CAIStatusCodeDatabaseStatementTimeout = 40011,
    CAIStatusCodeDatabaseInvalidRowsAffected = 40012,
    CAIStatusCodeDatabaseDeadlockDetected = 40013,
    CAIStatusCodeAsyncWorkerMultiErrors = 40020,
    CAIStatusCodeRpcRequestQueueFull = 40030,
    CAIStatusCodeRpcServerUnavailable = 40031,
    CAIStatusCodeRpcRequestTimeout = 40032,

    /** Queue related errors 41xxx */
    CAIStatusCodeQueueConnError = 41000,
    CAIStatusCodeQueueCloseRequestTimeout = 41002,
    CAIStatusCodeQueueConnClosed = 41003,
    CAIStatusCodeQueuePublishAckTimeout = 41004,
    CAIStatusCodeQueuePublishError = 41005,
    CAIStatusCodeQueueSubscriptionTimeout = 41006,
    CAIStatusCodeQueueSubscriptionError = 41007,
    CAIStatusCodeQueueMarshallingFailed = 41008,
    CAIStatusCodeQueueUnmarshallingFailed = 41009,
    CAIStatusCodeQueueMaxMsgRedeliveryExceeded = 41010,
    CAIStatusCodeQueueAckFailure = 41011,

    /** Visualization related 42xxx */
    CAIStatusCodeVisualizationSuccess = 42000,
    CAIStatusCodeVisualizationPending = 42001,
    CAIStatusCodeVisualizationFailed = 42002,
    CAIStatusCodeVisualizationInvalidRequest = 42003,
    CAIStatusCodeMissingAppVisualization = 42004,
    CAIStatusCodeVisualizationTooManyUrls = 42005,
    CAIStatusCodeVisualizationFailedToSampleApp = 42006,
    CAIStatusCodeVisualizationFailedToEmbed = 42007,
    CAIStatusCodeVisualizationS3Error = 42008,

    /** Search related errors 43xxxx */
    CAIStatusCodeSearchInvalidRequest = 40002,
    CAIStatusCodeSearchInternalIssue = 43001,
    CAIStatusCodeSearchProjectionFailure = 43002,
    CAIStatusCodeSearchPredictionFailure = 43003,

    /** Stripe 44xxx */
    CAIStatusCodeStripeEventError = 44001,

    /** Redis/Cache 45xxx */
    CAIStatusCodeCacheMiss = 45001,

    /** Internal issues: 98xxx */
    CAIStatusCodeInternalServerIssue = 98004,
    CAIStatusCodeInternalFetchingIssue = 98005,
    CAIStatusCodeInternalDatabaseIssue = 98006,
    CAIStatusCodeInternalUnexpectedTimeout = 98009,
    CAIStatusCodeInternalUnexpectedV1 = 98010,
    CAIStatusCodeInternalUnexpectedPanic = 98011,
    CAIStatusCodeInternalUnexpectedSpire = 98012,
    CAIStatusCodeInternalRedisUnavailable = 98013,

    /** Uncategorized: 99xxx: move off as soon as known */
    CAIStatusCodeConnUncategorized = 99001,
    CAIStatusCodeModelUncategorized = 99002,
    CAIStatusCodeInputUncategorized = 99003,
    CAIStatusCodeInternalUncategorized = 99009,

    /** Depreciated codes: migrate off these to one of the internal issues */
    CAIStatusCodeBadRequest = 90400,
    CAIStatusCodeServerError = 90500,
} NS_SWIFT_NAME(StatusCode);
