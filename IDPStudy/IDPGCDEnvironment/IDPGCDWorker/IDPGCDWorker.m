//
//  IDPGCDWorker.m
//  IDPStudy
//
//  Created by Alexander Kradenkov on 8/19/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import "IDPGCDWorker.h"

@implementation IDPGCDWorker

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.backgroundBlock = nil;
    self.completionBlock = nil;
    
    [super dealloc];
}

#pragma mark -
#pragma mark Public

- (void)executeBarrier {
    dispatch_queue_t backgroundQueue = dispatch_get_global_queue(QOS_CLASS_BACKGROUND, 0);
    
    dispatch_block_t backgroundBlock = self.backgroundBlock;
    if (backgroundBlock) {
        dispatch_async(backgroundQueue, backgroundBlock);
        
        dispatch_block_t completion = self.completionBlock;
        
        if (completion) {
            dispatch_barrier_async(backgroundQueue, completion); // wait until ALL tasks in backgroundQueue will be executed
        }
        
        NSLog(@"end of %s", __PRETTY_FUNCTION__);
    }
}

- (void)executeWithNotificationOnMainQueue {
    dispatch_queue_t backgroundQueue = dispatch_get_global_queue(QOS_CLASS_BACKGROUND, 0);
    
    dispatch_block_t backgroundBlock = self.backgroundBlock;

    dispatch_async(backgroundQueue, ^{
        if (backgroundBlock) {
            backgroundBlock();
        }
        
        dispatch_sync(dispatch_get_main_queue(), ^{
            
            dispatch_block_t completion = self.completionBlock;
            
            if (completion) {
                completion();
            }
        });
        
        NSLog(@"end of %s", __PRETTY_FUNCTION__);
    });
}

- (void)executeOnce {
    
    static dispatch_once_t onceToken;
    NSLog(@"%lu", onceToken);
    
    for (NSUInteger iterator = 0; iterator < 100; iterator++) {
        dispatch_async(dispatch_get_global_queue(QOS_CLASS_BACKGROUND, 0), ^{
            dispatch_once(&onceToken, ^{
                NSLog(@"end of %s %lu token - %lu", __PRETTY_FUNCTION__, iterator, onceToken);
            });
            
            NSLog(@"end of %s %lu", __PRETTY_FUNCTION__, iterator);
        });
    }
}

@end
