//
//  HttpRequest.h
//  AFSECPackage
//
//  Created by Mac on 2018/3/13.
//  Copyright © 2018年 Mac. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ShareSingleton.h"

@class AFNetworking;
@interface HttpRequest : NSObject
//+ (HttpRequest *)sharedInstance;
ShareSingletonH(manager)

- (void)Get:(NSString *)URLString dict:(id)dict succeed:(void (^)(id data))succeed failure:(void (^)(NSError *error))failure;

- (void)Post:(NSString *)URLString dict:(id)dict succeed:(void (^)(id data))succeed failure:(void (^)(NSError *error))failure;
@end
