//
//  IDPSyntax.m
//  IDPStudy
//
//  Created by Alexander Kradenkov on 7/6/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import "IDPSyntax.h"

@implementation IDPSyntax

//@synthesize value; // ivar name is equal to property name
////@synthesize nextValue = _nextValue; // by default
//@dynamic married;

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self->_name = NULL;
 
    [super dealloc];
}

#pragma mark -
#pragma mark Public Methods

- (void)foo {
    NSLog(@"%@ %d", self, 1);
}

#pragma mark -
#pragma mark IDPObjectSyntax

+ (id)objectForClass:(Class)objectClass {
    return [[[objectClass alloc] init] autorelease];
}

- (void)protocolFoo {
    NSLog(@"%@", NSStringFromSelector(_cmd));
}

- (uint64_t)protocolFooWithArgument:(NSString *)arg1 secondArgument:(id)argument2 count:(uint64_t)count {
    NSLog(@"%@, arg2: %@", arg1, argument2);
    
    return count;
}

@end
