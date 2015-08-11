//
//  IDPMessagingObject.m
//  IDPStudy
//
//  Created by Alexander Kradenkov on 8/11/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import "IDPMessagingObject.h"



@implementation IDPMessagingObject

+ (BOOL)resolveInstanceMethod:(SEL)sel {
    NSLog(@"%@ %s - %@", self, __PRETTY_FUNCTION__, NSStringFromSelector(sel));
    
    return sel == kIDPMessagingVirtualSelector || [super resolveInstanceMethod:sel];
}

- (id)forwardingTargetForSelector:(SEL)aSelector {
    NSLog(@"%@ %s - %@", self, __PRETTY_FUNCTION__, NSStringFromSelector(aSelector));
    if (aSelector == kIDPMessagingVirtualSelector) {
        return self;
    }
    
    return [super forwardingTargetForSelector:aSelector];
}

- (NSMethodSignature *)methodSignatureForSelector:(SEL)aSelector {
    NSLog(@"%@ %s - %@", self, __PRETTY_FUNCTION__, NSStringFromSelector(aSelector));
    
    NSMethodSignature *signature = [super methodSignatureForSelector:aSelector];
    if (!signature && aSelector == kIDPMessagingVirtualSelector) {
        signature = [self methodSignatureForSelector:@selector(privateFoo:)];
    }
    
    return signature;
}


- (IMP)methodForSelector:(SEL)aSelector {
    NSLog(@"%@ %s - %@", self, __PRETTY_FUNCTION__, NSStringFromSelector(aSelector));
    
    return [super methodForSelector:aSelector];
}

- (void)forwardInvocation:(NSInvocation *)anInvocation {
    NSLog(@"%@ %s - %@", self, __PRETTY_FUNCTION__, anInvocation);
    if (anInvocation.selector == kIDPMessagingVirtualSelector) {
        anInvocation.selector = @selector(privateFoo:);
        [anInvocation invokeWithTarget:self];
        
        return;
    }
    
    return [super forwardInvocation:anInvocation];
}

#pragma mark -
#pragma mark Private

- (void)privateFoo:(id)obj {
    NSLog(@"%@ %s - %@", self, __PRETTY_FUNCTION__, obj);
}

@end
