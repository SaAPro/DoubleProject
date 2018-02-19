<img src="https://clarifai.com/static/images/logo.png" width="256">

# Clarifai Apple SDK

Hello and welcome! This is the public repository of the Clarifai SDK for Apple platforms. We currently support iOS, but plans are in the works to expand.

Our vision at Clarifai is to answer every question. And with this SDK we can help you to bring power A.I. to mobile applications. Check our developer's site at [https://developer.clarifai.com](https://developer.clarifai.com) or contact us at <mobile-feedback@clarifai.com> to learn more.

# Getting started

Sign up for a free developer account at: https://developer.clarifai.com/signup/

The Clarifai-Apple-SDK is available via [CocoaPods](https://cocoapods.org/?q=clarifai-apple-sdk) or can be installed manually. Follow the instructions below based on your preference.


>### Git LFS
>
>Before we proceed with the installation, please make sure you have Git-LFS installed on your system. The binary contained in the framework is managed by GitHub using `git-lfs`.
>
>If you don't have it installed yet, you can find details at: [https://git-lfs.github.com](https://git-lfs.github.com)


## CocoaPods

To integrate the SDK using CocoaPods, specify it in your [Podfile](https://guides.cocoapods.org/syntax/podfile.html):

```ruby
target '<Your Target>' do
    platform :ios, '8.2'
    use_frameworks!

    pod 'Clarifai-Apple-SDK', '3.0.0-beta13'
end
```

Install with:

```bash
pod install --repo-update
```

> iOS 8.2 is the minimum version supported by the Clarifai SDK.


## Manual installation

The best way to stay up-to-date with the latest version of the SDK with a manual installation is to clone our [GitHub repo](https://github.com/Clarifai/clarifai-apple-sdk.git).

```bash
git clone https://github.com/Clarifai/clarifai-apple-sdk.git
```

1. In your project's root directory, *$(PROJECT_DIR)* [the same directory as the .xcodeproj file], create a directory named **Clarifai** and move the **Clarifai-Apple-SDK.framework** to that directory
    ```bash
    cd <project root directory>
    mkdir Clarifai
    cp -r <directory the SDK was cloned to>/Clarifai_Apple_SDK.framework <project root directory>/Clarifai
    ```

2. Also, copy to the same **Clarifai** directory, the `setup_framework.sh` script.
    ```bash
    cp -r <directory the SDK was cloned to>/scripts/setup_framework.sh <project root directory>/Clarifai
    ```

3. Add the **Clarifai-Apple-SDK.framework** to your project's **Embedded Binaries**.

    * From your Xcode project/workspace go to the project configurations, **General** tab, and click the **+** button under the **Embedded Binaries** section. Navigate to the directory where you cloned the repository and select the **Clarifai-Apple-SDK.framework**

4. Include the following required dependencies to **Linked Frameworks and Libraries**:

    * `Accelerate.framework`
    * `CoreGraphics.framework`
    * `Foundation.framework`
    * `libc++`
    * `libsqlite3`
    * `libz`
    * `UIKit.framework`

5. Create a new **Run Script Build Phase** (Xcode > Editor > Add Build Phase > Add Run Script Build Phase). In the execution line enter:
    ```bash
    "$(PROJECT_DIR)/Clarifai/setup_framework.sh"
    ```

6. Make sure the position of the new **Run Script** is after **Compile Sources** and before **Link Binary With Libraries**. If needed drag and drop it to the right position.
    <img src="https://user-images.githubusercontent.com/204792/31673152-7acff1a0-b32c-11e7-92bb-cb2a53ab1383.png" width="640">


You should be able to build your project and start using the SDK in your project.


## Start the SDK

The Clarifai SDK is initialized by calling the `startWithApiKey` method. We recommend to start it when your app finishes launching, but that is not absolutely required. And don't worry about hogging the launching of your app. We offload the work to background threads; there should be little to no impact.

* **Swift**

    ```swift
    import Clarifai_Apple_SDK

    func application(application: UIApplication, didFinishLaunchingWithOptions launchOptions: [NSObject: AnyObject]?) -> Bool {
        Clarifai.sharedInstance().start(apiKey:"<Your API Key>")

        return true
    }
    ```

* **Objective-C**

    ```objective-c
    @import Clarifai_Apple_SDK;

    - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
        [[Clarifai sharedInstance] startWithApiKey:@"<Your API Key>"];

        return YES;
    }
    ```


## General model availability notifications

Clarifai's *general model* becomes available to the SDK on demand. After you start the SDK for the first time, with a valid API Key, the model will be made available and cached locally for future faster use.

You can be notified on the progress of the availability of the SDK by registering to listen to the following notifications:

| Swift | Objective-C | Description |
|:---:|:---:|:---|
| `CAIWillFetchModel` | `CAIWillFetchModelNotification` | Broadcast right before the SDK begins fetching a model |
| `CAIDidFetchModel` | `CAIDidFetchModelNotification` | Broadcast right after a model has been fetched |
| `CAIModelDidBecomeAvailable` | `CAIModelDidBecomeAvailableNotification` | Broadcast when a model has become available to use |

The first two notifications usually happen only once, when you first use the SDK. After becoming available a model remains cached locally. The last notification, on the other hand, is broadcast every time the SDK is started.

Each of the notifications above contain a payload (`userInfo`) with the `id` of the model. Retrieve it by using the `CAIModelUniqueIdentifierKey` key.

* **Swift**

    ```swift
    func handleModelDidBecomeAvailable(notification: NSNotification) {
        if let userInfo = notification.userInfo {
            let modelId = userInfo[CAIModelDidBecomeAvailable] as? String
        }
    }
    ```

* **Objective-C**

    ```objective-c
    - (void)handleModelDidBecomeAvailable:(NSNotification *)notification {
        NSDictionary *userInfo = [notification UserInfo];
        NSString *modelId = userInfo[CAIModelUniqueIdentifierKey];
    }
    ```

## Learn and do more

Check out our [documentation site](https://developer.clarifai.com/docs/) to learn a lot more about how to bring A.I. to your app.


## Support

Questions? Have an issue? Send us a message at <mobile-feedback@clarifai.com>.


## License

The Clarifai-Apple-SDK is available under a commercial license. See the [LICENSE](https://github.com/Clarifai/clarifai-apple-sdk/blob/master/LICENSE) file for more information.
