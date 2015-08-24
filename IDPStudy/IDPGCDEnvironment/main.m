//
//  main.m
//  IDPGCDEnvironment
//
//  Created by Alexander Kradenkov on 8/19/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "IDPGCDWorker.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        
        IDPGCDWorker *worker = [[IDPGCDWorker new] autorelease];
        worker.backgroundBlock = ^{
            NSLog(@"the backgroundBlock");
        };
        
        worker.completionBlock = ^{
            NSLog(@"the completion");
        };
        
        
//        [worker executeBarrier];
//        NSLog(@"_________");
//        
//        
//        worker.backgroundBlock = ^{
//            NSLog(@"the backgroundBlock2");
//        };
//        
//        worker.completionBlock = ^{
//            NSLog(@"the completion2");
//            
//        };
//        
//        [worker executeWithNotificationOnMainQueue];
//        
//        NSLog(@"_________");
//        [worker executeOnce];
//        
//        NSLog(@"_________");
//        [worker executeApply];
        
        [worker executeGroup];
        
        
        [[NSRunLoop currentRunLoop] run];
    }
    
    return 0;
}
