//
//  XenonSDK.h
//  XenonSDK
//
//  Created by SAGESSE on 2019/1/20.
//  Copyright © 2019 SAGESSE. All rights reserved.
//

#import <UIKit/UIKit.h>

///
/// Game SDK
///
@interface XenonSDK : NSObject

///
/// A sington instance of SDK.
///
+ (instancetype)sharedSDK;

- (NSString *)configIDFA;

///
/// Init the sdk with application code.
/// \param parameter The parameter provided by the platform.
///
/// \param complete This closure called when init complete.
///
- (void)initWithParameter:(NSString*)parameter delegate:(id)delegate complete:(void (^)(NSError* error))complete;


///
/// Login the sdk.
/// \param complete This closure called when login complete.
///
- (void)loginWithComplete:(void (^)(id user, NSError* error))complete;

///
/// Logout the sdk.
/// \param complete This closure called when logout complete.
///
- (void)logoutWithComplete:(void (^)(void))complete;

///
/// Logout the game and sdk.
/// \param handler This closure called when user logout in web view.
/// \note Warning this handler will retain in until next call this method.
///
- (void)logoutWhenNotification:(void (^)(void))handler;

///
/// Buy a product.
/// \param parameters Payment request parameters.
/// \param complete Payment result of the callback, if the apple payment is completed before the callback, other payments will be the official launch of the callback
///
- (void)buy:(NSDictionary*)parameters complete:(void (^)(id order, NSError* error))complete;

///
/// User Center.
///
- (void)center;

/// Report role info.
/// \param roleName This role name.
///
/// \param level This role current level.
///
/// \param serverId This role current server.
///
- (void)reportWithRoleName:(NSString*)roleName level:(NSInteger)level serverId:(NSString*)serverId;


///check In-app Purchase lost list.
- (void)checkOrderStatus;

@end

