//
//  IDPThreadSafeObject.m
//  IDPStudy
//
//  Created by Alexander Kradenkov on 8/4/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import "IDPThreadSafeObject.h"

volatile static id __sharedLazyObject;
static dispatch_once_t onceToken;

@interface IDPThreadSafeObject ()
@property (nonatomic, retain)   NSMutableArray  *mutableObjects;

- (void)resetToken;

@end

@implementation IDPThreadSafeObject

@dynamic objects;
@synthesize object = _object;

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.mutableObjects = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.mutableObjects = [NSMutableArray array];
    }
    return self;
}
#pragma mark -
#pragma mark Accessors

- (void)setObject:(NSObject *)object {
    @synchronized(self) {
        [super setObject:object];
        NSLog(@"setted %@", object);
    }
}


- (id)lazyObject {
//    if (nil == __sharedLazyObject) {
//        @synchronized(self) {
//            if (nil == __sharedLazyObject) {
//                __sharedLazyObject = [[[NSObject alloc] init] autorelease];
//            }
//        }
//    }

    if (nil == __sharedLazyObject) {

        dispatch_once(&onceToken, ^{
            __sharedLazyObject = [[[NSObject alloc] init] autorelease];
        });
    }
    
    return __sharedLazyObject;
}

- (NSArray *)objects {
    @synchronized(_mutableObjects) {
        return [[_mutableObjects copy] autorelease];
    }
}

#pragma mark -
#pragma mark Public


- (void)addObject:(id)object {
    @synchronized(_mutableObjects) {
        [_mutableObjects addObject:object];
        NSLog(@"added %@", object);
    }
}

- (void)addObjectWhileSelfSynchronized:(id)object {
    @synchronized(self) {
        [_mutableObjects addObject:object];
        NSLog(@"added self synched %@", object);
    }
}


#pragma mark -
#pragma mark Private

- (void)resetToken {
    onceToken = 0;
}
@end
