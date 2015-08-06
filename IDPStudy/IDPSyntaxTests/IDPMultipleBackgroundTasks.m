//
//  IDPMultipleBackgroundTasks.m
//  IDPStudy
//
//  Created by Alexander Kradenkov on 8/6/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>

#import "IDPBucket.h"

@interface IDPMultipleBackgroundTasks : XCTestCase < IDPBucketObserver>
@property (nonatomic, assign)   NSUInteger liters;

@end

@implementation IDPMultipleBackgroundTasks

- (void)testExample {
    // This is an example of a functional test case.
    XCTAssert(YES, @"Pass");
    
    NSMutableArray *buckets = [NSMutableArray array];
    
    // create 10 empty buckets
    for (NSUInteger iterator = 0; iterator < 10; iterator++) {
        IDPBucket *bucket = [[IDPBucket alloc] initWithCapacity:200];
        [bucket addObserver:self];
        [buckets addObject:bucket];
        
    }

    // fill buckets in main thread
    self.liters = 10;
    
    
    for (IDPBucket *bucket in buckets) {
        [self performSelector:@selector(performBucketLitersSetter:) withObject:bucket];
    }
    
    NSLog(@"MAIN THREAD EXECUTION FINISH");
    
    self.liters = 11;
    // fill buckets in background
    
    
    for (IDPBucket *bucket in buckets) {
//                usleep(10 * 1000);
        self.liters++;
        [self performSelectorInBackground:@selector(performBucketLitersSetter:)
                               withObject:bucket];

    }
    
    NSLog(@"TEST FINISH");
    [[NSRunLoop currentRunLoop] run];
}


- (void)performBucketLitersSetter:(IDPBucket *)bucket {
//    if ([NSThread isMainThread]) {
        bucket.litersContained = self.liters;
//    } else {
//
//        [self performSelectorOnMainThread:@selector(performBucketLitersSetter:)
//                               withObject:bucket
//                            waitUntilDone:NO];
//    }

}

#pragma mark -
#pragma mark IDPBucketObserver

- (void)bucketContentHasChanged:(IDPBucket *)bucket {
    NSLog(@"%@, %lu", bucket, bucket.litersContained);
}

- (void)bucketBecomeEmpty:(IDPBucket *)bucket {
    NSLog(@"%@, empty %lu", bucket, bucket.litersContained);
}

- (void)bucketBecomeFull:(IDPBucket *)bucket {
    NSLog(@"%@, full %lu", bucket, bucket.litersContained);
}

@end
