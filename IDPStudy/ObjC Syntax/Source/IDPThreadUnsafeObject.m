//
//  IDPThreadUnsafeObject.m
//  IDPStudy
//
//  Created by Alexander Kradenkov on 8/3/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import "IDPThreadUnsafeObject.h"

@interface IDPThreadUnsafeObject ()
@property (nonatomic, retain) NSLock *lockingObject;

@end

@implementation IDPThreadUnsafeObject

- (void)dealloc {
    self.lockingObject = nil;
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.lockingObject = [[[NSLock alloc] init] autorelease];
    }
    
    return self;
}


- (void)setObject:(NSObject *)object {
    NSLock *lockingObject = self.lockingObject;
    [lockingObject lock];
    
    if (_object != object) {
        [_object release];
        _object = [object retain];
        
        usleep(10 * 1000);
        
        assert(_object == object);
        NSLog(@"OK");
    }
    
    [lockingObject unlock];
}

@end
