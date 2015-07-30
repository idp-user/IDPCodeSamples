//
//  IDPParentObject.m
//  IDPStudy
//
//  Created by Alexander Kradenkov on 7/30/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import "IDPParentObject.h"

@implementation IDPParentObject

#pragma mark -
#pragma mark Accessors

- (void)setChild:(IDPBabyObject *)child {
    if (_child != child) {
        _child.delegate = nil;
        
        [child retain];
        [_child release];
        
        _child = child;
        
        child.delegate = self;
    }
}

#pragma mark -
#pragma mark IDPBabyDelegate

- (NSObject *)cleanPampersForBaby:(IDPBabyObject *)child {
    return [[[NSObject alloc] init] autorelease];
}

@end
