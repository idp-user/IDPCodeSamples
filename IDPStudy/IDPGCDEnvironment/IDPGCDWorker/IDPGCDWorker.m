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

- (void)executeApply {
    dispatch_queue_t queue = dispatch_queue_create("Apply Queue", DISPATCH_QUEUE_SERIAL);
    
    dispatch_apply(10, queue, ^(size_t iterator) {
        NSLog(@"%lu", iterator);
    });
    
    dispatch_release(queue);
}


- (void)executeGroup {
    dispatch_group_t group = dispatch_group_create();
    
    dispatch_queue_t queue = dispatch_queue_create("Apply Queue", DISPATCH_QUEUE_CONCURRENT);
    
    dispatch_async(queue, ^{
        NSLog(@"Async block");
    });
    
    for (NSUInteger iterator = 0 ; iterator < 100; iterator++) {
        dispatch_group_async(group, queue, ^{
            usleep(1000);
            NSLog(@"Group queue #%lu", iterator);
        });
        
        dispatch_async(queue, ^{
            dispatch_group_enter(group);
            
            usleep(1000);
            NSLog(@"Async block #%lu", iterator);

            dispatch_group_leave(group);
        });
    }    

//    dispatch_async(queue, ^{
//        dispatch_group_wait(group, DISPATCH_TIME_FOREVER);
//        NSLog(@"Async completion block");
//    });
    
    dispatch_group_notify(group, queue, ^{
        usleep(1000);
        //        dispatch_group_wait(group, DISPATCH_TIME_FOREVER);
        NSLog(@"Notify block");
    });
    
    dispatch_group_notify(group, queue, ^{
        usleep(1000);
        //        dispatch_group_wait(group, DISPATCH_TIME_FOREVER);
        NSLog(@"Notify block1");
    });
    
    dispatch_group_notify(group, queue, ^{
        usleep(1000);
        //        dispatch_group_wait(group, DISPATCH_TIME_FOREVER);
        NSLog(@"Notify block2");
    });
    
    dispatch_group_notify(group, queue, ^{
        usleep(1000);
        //        dispatch_group_wait(group, DISPATCH_TIME_FOREVER);
        NSLog(@"Notify block3");
    });
    
//    dispatch_async(queue, ^{
//        dispatch_group_wait(group, DISPATCH_TIME_FOREVER);
//        NSLog(@"Async completion block");
//    });
    
    dispatch_group_wait(group, DISPATCH_TIME_FOREVER);
    NSLog(@"Async completion block");
    
    dispatch_release(queue);
    dispatch_release(group);
}

- (void)executeSemaphore {
    dispatch_semaphore_t semaphore = dispatch_semaphore_create(0);
    dispatch_queue_t queue = dispatch_queue_create("semaphore queue", DISPATCH_QUEUE_CONCURRENT);

//    __block BOOL isDone = NO;
    
    [self waitInQueue:queue withCompletion:^{
        NSLog(@"completion");
        dispatch_semaphore_signal(semaphore);
//        isDone = YES;
    }];
    
    NSLog(@"wait for completion");
    dispatch_semaphore_wait(semaphore, DISPATCH_TIME_FOREVER);
    
//    while (!isDone) {
//        [[NSRunLoop currentRunLoop] runUntilDate:[NSDate dateWithTimeIntervalSinceNow:0.1]];
//    }
    
    NSLog(@"completion done");
    
    dispatch_release(queue);
    dispatch_release(semaphore);
}



- (void)executeSemaphoreMultiple {
    long workerTasksCount = 20;
    
    dispatch_semaphore_t semaphore = dispatch_semaphore_create(workerTasksCount - 1);
    dispatch_queue_t queue = dispatch_queue_create("semaphore queue", DISPATCH_QUEUE_CONCURRENT);
    

    for (NSUInteger iterator = 0; iterator < 100; iterator++) {
        [self waitInQueue:queue withCompletion:^{
            NSLog(@"%lu - completion", iterator);
            sleep(10);
            
            
            dispatch_semaphore_signal(semaphore);
        }];
        
        NSLog(@"%lu - wait for", iterator);
        dispatch_semaphore_wait(semaphore, DISPATCH_TIME_FOREVER);
        NSLog(@"%lu - completion done", iterator);
    }
    
    dispatch_release(queue);
    dispatch_release(semaphore);
}

- (void)waitInQueue:(dispatch_queue_t)queue withCompletion:(void(^)(void))completion {
    if (completion) {
        dispatch_async(queue, ^{
            sleep(1);
            completion();
        });
    }
}

@end
