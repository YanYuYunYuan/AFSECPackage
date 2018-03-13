//
//  ShareSingleton.h
//  AFSECPackage
//
//  Created by Mac on 2018/3/13.
//  Copyright © 2018年 Mac. All rights reserved.
//

#import <Foundation/Foundation.h>

#define ShareSingletonH(name) +(instancetype)share##name;

#if __has_feature(objc_arc)

#define ShareSingletonM(name)                         \
static id _instace;                            \
\
+(id)allocWithZone : (struct _NSZone*)zone     \
{                                              \
static dispatch_once_t onceToken;          \
dispatch_once(&onceToken, ^{               \
_instace = [super allocWithZone:zone]; \
});                                        \
return _instace;                           \
}                                              \
\
+(instancetype)share##name                     \
{                                              \
static dispatch_once_t onceToken;          \
dispatch_once(&onceToken, ^{               \
_instace = [[self alloc] init];        \
});                                        \
return _instace;                           \
}                                              \
\
-(id)copyWithZone : (NSZone*)zone              \
{                                              \
return _instace;                           \
}
//如果是非ARC
#else

#define HMSingletonM(name)                                \
static id _instace;                                   \
\
+(id)allocWithZone : (struct _NSZone*)zone            \
{                                                     \
static dispatch_once_t onceToken;                 \
dispatch_once(&onceToken, ^{                      \
_instace = [super allocWithZone:zone];        \
});                                               \
return _instace;                                  \
}                                                     \
\
+(instancetype)share##name                            \
{                                                     \
static dispatch_once_t onceToken;                 \
dispatch_once(&onceToken, ^{                      \
_instace = [[self alloc] init];               \
});                                               \
return _instace;                                  \
}                                                     \
\
-(id)copyWithZone : (NSZone*)zone                     \
{                                                     \
return _instace;                                  \
}                                                     \
\
-(oneway void)release{} - (id)retain { return self; } \
-(NSUInteger)retainCount { return 1; }                \
-(id)autorelease { return self; }

#endif
