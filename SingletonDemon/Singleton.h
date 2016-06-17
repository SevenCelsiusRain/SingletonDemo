//
//  Singleton.h
//  SingletonDemon
//
//  Created by SevenCelsius on 16/6/15.
//  Copyright © 2016年 SevenCelsius. All rights reserved.
//

#ifndef Singleton_h
#define Singleton_h

// .h
#define SINGLETON_H(methodName) +(instancetype)share##methodName;

// .m
#if __has_feature(objc_arc)  // 是ARC
#define SINGLETON_M(className, methodName)  \
static className *_instance = nil;\
\
+ (instancetype)allocWithZone:(struct _NSZone *)zone {\
\
if (!_instance) {\
\
static dispatch_once_t onceToken;\
dispatch_once(&onceToken, ^{\
\
_instance = [super allocWithZone:zone];\
\
});\
}\
\
return _instance;\
}\
- (id)init {\
static dispatch_once_t onceToken;\
dispatch_once(&onceToken, ^{\
\
_instance = [super init];\
});\
\
return _instance;\
}\
\
+ (instancetype)share##methodName {\
\
return [[self alloc] init];\
}\
\
- (id)mutableCopy {\
    \
    return _instance;\
}\
\
- (id)copy {\
    \
    return _instance;\
}

#else
#define SINGLETON_M(className, methodName)  \
static className *_instance = nil;\
\
+ (instancetype)allocWithZone:(struct _NSZone *)zone {\
\
if (!_instance) {\
\
static dispatch_once_t onceToken;\
dispatch_once(&onceToken, ^{\
\
_instance = [super allocWithZone:zone];\
\
});\
}\
\
return _instance;\
}\
- (id)init {\
static dispatch_once_t onceToken;\
dispatch_once(&onceToken, ^{\
\
_instance = [super init];\
});\
\
return _instance;\
}\
\
+ (instancetype)share##methodName {\
\
return [[self alloc] init];\
}\
\
- (oneway void)release {\
}\
\
- (instancetype)retain {\
\
return self;\
}\
\
- (NSUInteger)retainCount{\
\
return 1;\
}
#endif


#endif /* Singleton_h */
