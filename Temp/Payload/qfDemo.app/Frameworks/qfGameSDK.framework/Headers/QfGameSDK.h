//
//  QfGameSDK.h
//  qfGameSDK
//
//  Created by xiaomai on 2022/3/17.
//

//20220317 公开 聚合动态SDK对应头文件，此文件中通过预留api对接各个渠道的sdk

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


NS_ASSUME_NONNULL_BEGIN

typedef void (^qfGameSuccessBlock)(id response);
typedef void (^qfGameFailBlock)(NSString *errorStr);

@interface QfGameSDK : NSObject

+(instancetype)sharedInstance;

/**
 * 初始化
 * @param param 聚合SDK初始化参数
 */
- (void)InitApi:(id)param
            application:(UIApplication *)application
didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;

/**
 * SDK登录(打开登录面板)
 * @param success  成功回调
 * @param fail  失败回调
 */
- (void)Login:(qfGameSuccessBlock)success
              fail:(qfGameFailBlock)fail;

/**
 * SDK退出登录-切换账号
 * @param success  成功回调
 * @param fail  失败回调
 */
- (void)Logout:(qfGameSuccessBlock)success
               fail:(qfGameFailBlock)fail;

/**
 * SDK创角 注意：创角信息既要传到渠道SDK服务器，还要上传到聚合SDK服务器
 * @param roleId 游戏-角色ID  必传
 * @param roleName 游戏-角色名称  必传
 * @param roleGrade 游戏-角色等级 必传
 * @param serverId 游戏-区服ID  必传
 * @param serverName  游戏-区服名称   必传
 * @param success  成功回调
 * @param fail  失败回调
 */
- (void)CreateRole:(NSString *)roleId
          roleName:(NSString *)roleName
         roleGrade:(NSString *)roleGrade
          serverId:(NSString *)serverId
        serverName:(NSString *)serverName
           success:(qfGameSuccessBlock)success
              fail:(qfGameFailBlock)fail;

/**
 * SDK角色信息上报(角色升级同步角色信息到服务器) 注意：角色信息既要传到渠道SDK服务器，还要上传到聚合SDK服务器
 * @param roleId 游戏-角色ID  必传
 * @param roleName 游戏-角色名称  必传
 * @param roleGrade 游戏-角色等级 必传
 * @param serverId 游戏-区服ID  必传
 * @param serverName  游戏-区服名称   必传
 * @param success  成功回调
 * @param fail  失败回调
 */
- (void)SynRoleInfo:(NSString *)roleId
           roleName:(NSString *)roleName
          roleGrade:(NSString *)roleGrade
           serverId:(NSString *)serverId
         serverName:(NSString *)serverName
            success:(qfGameSuccessBlock)success
               fail:(qfGameFailBlock)fail;

/**
 * SDK调用支付
 * @param productId 产品ID    必传
 * @param roleId 游戏-角色ID  必传
 * @param roleName 游戏-角色名称  必传
 * @param roleGrade 游戏-角色等级  必传
 * @param serverId 游戏-区服ID  必传
 * @param serverName  游戏-区服名称   必传
 * @param productName   商品名称    必传
 * @param productDesc   商品描述(商品明细)  必传
 * @param attach  CP扩展参数(必传CP订单号)
 * @param virtualA 虚拟币金额  必填(如果没有，可以使用订单金额)
 * @param money  支付金额   必传
 * @param extraInfo  额外信息 选填(没有传空)
 * @param success  成功回调
 * @param fail  失败回调
 */
- (void)Buy:(NSString *)productId
     roleID:(NSString *)roleId
   roleName:(NSString *)roleName
  roleGrade:(NSString *)roleGrade
   serverId:(NSString *)serverId
 serverName:(NSString *)serverName
productName:(NSString *)productName
productDesc:(NSString *)productDesc
     attach:(NSString *)attach
   virtualA:(NSString *)virtualA
      money:(NSString *)money
  extraInfo:(NSString *)extraInfo
    success:(qfGameSuccessBlock)success
       fail:(qfGameFailBlock)fail;

/**
 * SDK实名认证-可选(防沉迷，根据游戏确定，如果游戏内部有防沉迷则不需要调用)
 */
- (void)authenRealName:(qfGameSuccessBlock)callback;

/**
 * 是否展示SDK打印日志(默认不展示)
 */
- (void)ShowSDKLogs:(BOOL)show;



#pragma mark - UIApplicationDelegate
/**
 * 用于AppDelegate 入口类文件处理第三方回调
 */
//Open URI-scheme for iOS 8 and below 其他APP回调自己APP时候调用
- (void)application:(UIApplication *)application
            openURL:(NSURL *)url
  sourceApplication:(NSString *)sourceApplication
         annotation:(id)annotation;

//Open URI-scheme for iOS 8 and below 其他APP回调自己APP时候调用
- (void)application:(UIApplication *)application
      handleOpenURL:(NSURL *)url;//https://www.jianshu.com/p/32fbbc0b978f

//Open URI-scheme for iOS 9 and above 其他APP回调自己APP时候调用
- (void)application:(UIApplication *)application
            openURL:(NSURL *)url
            options:(NSDictionary<UIApplicationOpenURLOptionsKey, id> *)options;

//程序将进入前台(将要进入活跃状态)
- (void)applicationWillEnterForeground:(UIApplication *)application;

//程序已经进入前台(已经进入活跃状态)
- (void)applicationDidBecomeActive:(UIApplication *)application;

//程序将进入后台(即将变成非激活状态)
- (void)applicationWillResignActive:(UIApplication *)application;

//程序已经进入后台
- (void)applicationDidEnterBackground:(UIApplication *)application;

//代码控制横竖屏设置
- (UIInterfaceOrientationMask)application:(UIApplication *)application supportedInterfaceOrientationsForWindow:(UIWindow *)window;

//推送消息时候，获取设备的tokenid
- (void)application:(UIApplication *)application
didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken;

//tokenid获取失败时，做对应处理
- (void)application:(UIApplication *)application
didFailToRegisterForRemoteNotificationsWithError:(NSError *)error;

//接收到推送消息处理 ios(3.0, 10.0)
- (void)application:(UIApplication *)application
didReceiveRemoteNotification:(NSDictionary *)userInfo;

//接收到推送消息处理 收到推送消息时候 ios(7.0)
- (void)application:(UIApplication *)application
didReceiveRemoteNotification:(NSDictionary *)userInfo
fetchCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler;

//程序将要退出(通常用于保存数据和一些退出前的清理工作)
- (void)applicationWillTerminate:(UIApplication *)application;

//从其他APP跳转至当前APP时, 该方法会自动调用 Open Universal Links方式
- (void)application:(UIApplication *)application
continueUserActivity:(NSUserActivity *)userActivity
 restorationHandler:(void(^)(NSArray * restorableObjects))restorationHandler;


//系统内存不足，需要进行清理工作
- (void)applicationDidReceiveMemoryWarning:(UIApplication *)application;

//当系统时间发生改变时执行
- (void)applicationSignificantTimeChange:(UIApplication *)application;

//当程序载入后执行
- (void)applicationDidFinishLaunching:(UIApplication *)application;


@end

NS_ASSUME_NONNULL_END
