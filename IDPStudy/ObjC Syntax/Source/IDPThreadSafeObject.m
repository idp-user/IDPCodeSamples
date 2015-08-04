//
//  IDPThreadSafeObject.m
//  IDPStudy
//
//  Created by Alexander Kradenkov on 8/4/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import "IDPThreadSafeObject.h"

@interface IDPThreadSafeObject ()
@property (nonatomic, retain)   NSMutableArray  *mutableObjects;

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

@end
