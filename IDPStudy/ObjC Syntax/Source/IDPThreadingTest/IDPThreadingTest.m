//
//  IDPThreadingTest.m
//  IDPStudy
//
//  Created by Alexander Kradenkov on 8/3/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import "IDPThreadingTest.h"

#import "IDPThreadUnsafeObject.h"
#import "IDPThreadSafeObject.h"

@implementation IDPThreadingTest

#pragma mark -
#pragma mark Class Methods

+ (void)performTests {
    NSUInteger operationCount = 1000;
    IDPThreadUnsafeObject *object = [[IDPThreadUnsafeObject new] autorelease];
    
    
//    // one thread operations
//    for (NSUInteger iteration = 0; iteration < operationCount; iteration++) {
//        NSObject *value = [[NSObject new] autorelease];
////        object.object = value;
//        [object performSelector:@selector(setObject:) withObject:value];
//        
//    }
//    NSLog(@"FINISHED IN MAIN");

    // Will raise exception
//    for (NSUInteger iteration = 0; iteration < operationCount; iteration++) {
//        NSObject *value = [[NSObject new] autorelease];
//        [object performSelectorInBackground:@selector(setObject:)
//                                 withObject:value];
//        
//    }
    
    IDPThreadSafeObject *safeObject = [[IDPThreadSafeObject new] autorelease];
    
//    for (NSUInteger iteration = 0; iteration < operationCount; iteration++) {
//        NSObject *value = [[NSObject new] autorelease];
//        [safeObject performSelectorInBackground:@selector(setObject:)
//                                     withObject:value];
//        
//        [safeObject performSelectorInBackground:@selector(addObject:)
//                                     withObject:value];
//    }
    
    
//    for (NSUInteger iteration = 0; iteration < operationCount; iteration++) {
//        NSObject *value = [[NSObject new] autorelease];
//        [safeObject performSelectorInBackground:@selector(setObject:)
//                                     withObject:value];
//        
//        [safeObject performSelectorInBackground:@selector(addObjectWhileSelfSynchronized:)
//                                     withObject:value];
//    }

    
    
//    for (NSUInteger iteration = 0; iteration < operationCount; iteration++) {
//        NSObject *value = [[NSObject new] autorelease];
//
//        [safeObject.mutableObjects performSelectorInBackground:@selector(addObject:)
//                                     withObject:value];
//
//    }
//    
//    for (id object in safeObject.mutableObjects) {
//        NSLog(@"%@", object);
//    }
    
        for (NSUInteger iteration = 0; iteration < operationCount; iteration++) {
            NSObject *value = [[NSObject new] autorelease];
    
            [safeObject performSelectorInBackground:@selector(addObject:)
                                         withObject:value];
    
        }
    
    NSArray *array = safeObject.objects;
    NSLog(@"%lu", [array count]);
    
    for (id object in array) {
//        NSLog(@"%@", object);
        usleep(1);
    }
    
    array = safeObject.objects;
    NSLog(@"%lu", [array count]);


    [[NSRunLoop currentRunLoop] run];

}

@end
