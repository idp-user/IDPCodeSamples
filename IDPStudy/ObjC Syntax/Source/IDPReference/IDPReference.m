//
//  IDPReference.m
//  IDPStudy
//
//  Created by Alexander Kradenkov on 7/28/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import "IDPReference.h"

@implementation IDPReference

@dynamic target;

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.target = nil;
    
    [super dealloc];
}

- (instancetype)initWithTarget:(id)object {
    if (nil == object) {
        return nil;
    }
    
    self = [super init];
    if (self) {
        self.target = object;
    }
    
    return self;
}

#pragma mark -
#pragma mark NSCopying

- (id)copyWithZone:(NSZone *)zone {
    return [[[self class] alloc] initWithTarget:self.target];
}

#pragma mark -
#pragma mark NSObject equality

- (NSUInteger)hash {
    return [self.target hash];
}

- (BOOL)isEqual:(IDPReference *)object {
    return [object isMemberOfClass:[self class]] && object.target == self.target;
}

@end
