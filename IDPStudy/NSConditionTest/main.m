//
//  main.m
//  NSConditionTest
//
//  Created by Alexander Kradenkov on 8/13/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "IDPConditionExample.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        [IDPConditionExample performSynchronousTest];
        
        NSLog(@"Hello, Asynchronous World!");
        [IDPConditionExample performAsynchronousTest];

        NSLog(@"OK");
        [[NSRunLoop currentRunLoop] run];
    }
    return 0;
}
