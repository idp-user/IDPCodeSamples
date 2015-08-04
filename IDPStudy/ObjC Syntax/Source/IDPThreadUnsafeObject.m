//
//  IDPThreadUnsafeObject.m
//  IDPStudy
//
//  Created by Alexander Kradenkov on 8/3/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import "IDPThreadUnsafeObject.h"

@interface IDPThreadUnsafeObject ()

@end

@implementation IDPThreadUnsafeObject

- (void)dealloc {
    self.object = nil;
    
    [super dealloc];
}

- (void)setObject:(NSObject *)object {
    if (_object != object) {
        [_object release];
        _object = [object retain];
        
        usleep(10 * 1000);
        
        NSAssert(_object == object, @"object n\missing");
        NSLog(@"OK");
    }
}

@end
