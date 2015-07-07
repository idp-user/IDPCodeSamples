//
//  IDPSyntax.m
//  IDPStudy
//
//  Created by Alexander Kradenkov on 7/6/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import "IDPSyntax.h"

#import "IDPSyntax+IDPExtensions.h"

@interface IDPSyntax ()
@property (nonatomic, assign, readwrite) int publicReadonlyValue;

@end



@implementation IDPSyntax

@synthesize nonatomicAssignValue = _nonatomicAssignValue;
@synthesize atomicAssignValue =_atomicAssignValue;

//@synthesize value; // ivar name is equal to property name
////@synthesize nextValue = _nextValue; // by default
//@dynamic married;

#pragma mark -
#pragma mark Class Methods

+ (void)syntaxTest {
    IDPSyntax *object = [self object];
    
    NSAssert(YES == [object isKindOfClass:[self class]], @"nope");
}

+ (id)syntax {
    return [[[self alloc] init] autorelease];
}

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {

    [super dealloc];
}

#pragma mark -
#pragma mark Accessors

- (void)setNonatomicAssignValue:(int)nonatomicAssignValue {
    _nonatomicAssignValue = nonatomicAssignValue;
}

- (int)nonatomicAssignValue {
    return _nonatomicAssignValue;
}

- (void)setAtomicAssignValue:(id)atomicAssignValue {
    @synchronized(_atomicAssignValue) {
        _atomicAssignValue = atomicAssignValue;
    }
}

- (id)atomicAssignValue {
    @synchronized(_atomicAssignValue) {
        return _atomicAssignValue;
    }
}

- (void)setRetainedObject:(id)retainedObject {
    if (_retainedObject != retainedObject) {
        [retainedObject retain];
        [_retainedObject release];
        _retainedObject = retainedObject;
    }
}

- (void)setCopiedObject:(id)copiedObject {
    if (_copiedObject != copiedObject) {
        [_copiedObject release];
        _copiedObject = [copiedObject copy];
    }
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
