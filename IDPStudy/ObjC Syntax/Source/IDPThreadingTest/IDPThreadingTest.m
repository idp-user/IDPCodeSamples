//
//  IDPThreadingTest.m
//  IDPStudy
//
//  Created by Alexander Kradenkov on 8/3/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import "IDPThreadingTest.h"

#import "IDPThreadUnsafeObject.h"

@implementation IDPThreadingTest

#pragma mark -
#pragma mark Class Methods

+ (void)performTests {
    NSUInteger operationCount = 100;
    IDPThreadUnsafeObject *object = [[IDPThreadUnsafeObject new] autorelease];
    
    
    // one thread operations
    for (NSUInteger iteration = 0; iteration < operationCount; iteration++) {
        NSObject *value = [[NSObject new] autorelease];
//        object.object = value;
        [object performSelector:@selector(setObject:) withObject:value];
        
    }
    NSLog(@"FINISHED IN MAIN");
    
    // multiple thread operations
    for (NSUInteger iteration = 0; iteration < operationCount; iteration++) {
        NSObject *value = [[NSObject new] autorelease];
        [object performSelectorInBackground:@selector(setObject:) withObject:value];
    }
    
    usleep(200 * 1000);
    NSLog(@"FINISHED");
    
    [[NSRunLoop currentRunLoop] run];
}

@end
