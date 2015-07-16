//
//  IDPBlock.m
//  IDPStudy
//
//  Created by Alexander Kradenkov on 7/16/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import "IDPBlock.h"

typedef void(^IDPVoidBlock)(void);

@interface IDPBlock ()
@property (nonatomic, copy)     IDPVoidBlock    copiedBlock;
@property (nonatomic, retain)   IDPVoidBlock    retainedBlock;


+ (void)performLambdaBlockTest;
+ (void)performTypedefLambdaBlockTest;

+ (void)performStackClosureBlockTest;
+ (void)performIVarBlockTest;

+ (void)performClosureWithObjectBlock;
+ (void)performHeapClosureWithObjectBlock;

+ (void)performWeakify;
@end

@implementation IDPBlock

#pragma mark -
#pragma mark Class Methods

+ (void)performTests {
    [self performLambdaBlockTest];
    [self performTypedefLambdaBlockTest];
    [self performStackClosureBlockTest];
    [self performIVarBlockTest];
    [self performClosureWithObjectBlock];
    [self performHeapClosureWithObjectBlock];
    [self performWeakify];
}

+ (void)performLambdaBlockTest {
    void(^currentBlockValue)(void) = ^void(void) {
        NSLog(@"lambda block");
    };
    
    NSLog(@"%@", currentBlockValue);
    
    currentBlockValue();
}

+ (void)performTypedefLambdaBlockTest {
    IDPVoidBlock currentBlockValue = ^{
        NSLog(@"typedef lambda block");
    };

    NSLog(@"%@", currentBlockValue);
    currentBlockValue();
}

+ (void)performStackClosureBlockTest {
    int intValue = 42;
    
    IDPVoidBlock intValueBlock = ^{
        NSLog(@"%d", intValue);
    };
    
    intValue = 0;
    NSLog(@"%d", intValue);
    
    NSLog(@"%@", intValueBlock);
    intValueBlock();
    
    __block int intVariable = 42;
    
    intValueBlock = ^{
        NSLog(@"%d", intVariable);
        intVariable = 84;
        NSLog(@"%d", intVariable);
    };
    
    intVariable = 0;
    
    NSLog(@"%@", intValueBlock);
    intValueBlock(); // after block invocation intVariable is 84
    
    NSLog(@"%d", intVariable);
}

+ (void)performIVarBlockTest {
    IDPVoidBlock stackBlock = ^{
        NSLog(@"stackBlock");
    };
    
    NSLog(@"%@", stackBlock);
    stackBlock();
    
    IDPBlock *object = [[[IDPBlock alloc] init] autorelease];
    object.copiedBlock = stackBlock;

    
    NSLog(@"copiedBlock -> %@", object.copiedBlock);
    object.copiedBlock();
    
    // BAD BAD BAD block isn't copied to the heap!
#warning OLOLO CODE
    object.retainedBlock = stackBlock;
    NSLog(@"retainedBlock -> %@", object.retainedBlock);
    object.retainedBlock();
}

+ (void)performClosureWithObjectBlock {
    NSObject *object = [[NSObject alloc] init];

    
    NSLog(@"%@, retainCount = %lu", object, [object retainCount]);
    
    IDPVoidBlock block = ^{
        NSLog(@"%@, retainCount = %lu", object, [object retainCount]);
        [object retain];
//        object = nil; // object value doesn't have __block attribute
        NSLog(@"%@, retainCount = %lu", object, [object retainCount]);
        [object release];
        NSLog(@"block END");
    };

    NSLog(@"%@, retainCount = %lu", object, [object retainCount]);
    NSLog(@"%@", block);
    block();
    

    
    NSLog(@"\n\n__block");
    
    __block NSObject *object2 = [[NSObject alloc] init];
    
    block = ^{
        NSLog(@"%@, retainCount = %lu", object2, [object2 retainCount]);
        [object2 release];
        object2 = object;
        
        NSLog(@"%@, retainCount = %lu", object2, [object2 retainCount]);
    };
    
    [object2 release];
    object2 = nil;
    
    NSLog(@"%@, retainCount = %lu", object2, [object2 retainCount]);
    NSLog(@"%@", block);
    block();
    
    
    [object release];
}

+ (void)performHeapClosureWithObjectBlock {
    NSLog(@"\n\nperformHeapClosureWithObjectBlock");
    NSObject *object = [[NSObject alloc] init];
    
    
    NSLog(@"%@, retainCount = %lu", object, [object retainCount]);
    
    IDPVoidBlock block = ^{
        NSLog(@"%@, retainCount = %lu", object, [object retainCount]);
        NSLog(@"block END");
    };
    
    NSLog(@"%@, retainCount = %lu", object, [object retainCount]);
    NSLog(@"%@", block);
    block();
    
    
    IDPBlock *object2 = [[[IDPBlock alloc] init] autorelease];
    object2.copiedBlock = block;
    
    
    NSLog(@"copiedBlock -> %@", object2.copiedBlock);
    object2.copiedBlock();
    [object release];
}


+ (void)performWeakify {
    NSLog(@"\n\nperformWeakifySelf");
    IDPBlock *object = [[self alloc] init];
    
    NSLog(@"%@, retainCount = %lu", object, [object retainCount]);
    
    NSLog(@"%@, retainCount = %lu", object, [object retainCount]);

    __unsafe_unretained IDPBlock * __unsafe_unretained weakObject = object;
    IDPVoidBlock block = ^{
        NSLog(@"%@, retainCount = %lu", weakObject, [weakObject retainCount]);
    };
    
#warning wrong object retainCount. shouldn't increment
    NSLog(@"%@, retainCount = %lu", object, [object retainCount]);
    
    object.copiedBlock = block;
    
    NSLog(@"%@, retainCount = %lu", object, [object retainCount]);
    object.copiedBlock();
    
    [object release];
    
    NSLog(@"%@, retainCount = %lu", object, [object retainCount]);
}

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.copiedBlock = nil;
    self.retainedBlock = nil;
    
    [super dealloc];
}

@end
