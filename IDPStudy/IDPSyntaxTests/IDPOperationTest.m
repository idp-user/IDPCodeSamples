//
//  IDPOperationTest.m
//  IDPStudy
//
//  Created by Alexander Kradenkov on 8/26/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>

#import "IDPNegativeValueCountingOperation.h"
#import "IDPAsyncNegativeValueCountingOperation.h"


@interface IDPOperationTest : XCTestCase
@property (nonatomic, assign)  volatile OSSpinLock spinLock;

@end

@implementation IDPOperationTest

- (void)setUp {
    [super setUp];
    
    self.spinLock = OS_SPINLOCK_INIT;
}

- (void)testSynchronousOperation {
    NSArray *data = @[@(-1), @(1), @(-3)];
    IDPNegativeValueCountingOperation *firstOperation = [[IDPNegativeValueCountingOperation alloc] initWithArray:data];
    
    __weak typeof(firstOperation) weakOperation = firstOperation;
    firstOperation.completionBlock = ^{
        __strong typeof(firstOperation) strongOperation = weakOperation;
        if (!strongOperation) {
            return;
        }
        
        NSLog(@"result %lu", strongOperation.result);
    };
    
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        [firstOperation cancel];
    });
    
    XCTestExpectation *expectation = [self expectationWithDescription:@"IDPNegativeValueCountingOperation"];
    
    dispatch_async(dispatch_get_global_queue(QOS_CLASS_BACKGROUND, 0), ^{
        [firstOperation start];
        
        [expectation fulfill];
    });
    
    [self waitForExpectationsWithTimeout:600 handler:^(NSError *error) {
        XCTAssert(nil == error);
        
        NSLog(@"operation cancelled  = %d", firstOperation.isCancelled);
    }];
}

- (void)testMultipleSynchronousOperation {
    NSArray *data = @[@(-1), @(1), @(-3)];
    
    NSOperationQueue *queue = [NSOperationQueue new];
    queue.maxConcurrentOperationCount = 10;
    
    queue.suspended = YES;
    
    
    for (NSUInteger iterator = 0; iterator < 10; iterator++) {
        IDPNegativeValueCountingOperation *operation = [[IDPNegativeValueCountingOperation alloc] initWithArray:data];
        
        __weak typeof(operation) weakOperation = operation;
        operation.completionBlock = ^{
            __strong typeof(operation) strongOperation = weakOperation;
            if (!strongOperation) {
                return;
            }
            
            NSLog(@"operation %lu result = %lu", iterator, strongOperation.result);
        };
        
        [queue addOperation:operation];
    }
    
    queue.suspended = NO;
    
    [queue waitUntilAllOperationsAreFinished];
}


- (void)testAsynchronousOperation {
    NSArray *data = @[@(-1), @(1), @(-3)];
    IDPAsyncNegativeValueCountingOperation *firstOperation = [[IDPAsyncNegativeValueCountingOperation alloc] initWithArray:data];
    XCTestExpectation *expectation = [self expectationWithDescription:@"IDPNegativeValueCountingOperation"];
    
    __weak typeof(firstOperation) weakOperation = firstOperation;
    firstOperation.completionBlock = ^{
        __strong typeof(firstOperation) strongOperation = weakOperation;
        if (!strongOperation) {
            return;
        }
        
        NSLog(@"result %lu", strongOperation.result);
        
        [expectation fulfill];
    };
    
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(3 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        [firstOperation start];
    });
    
    
    //    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(2 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
    //        [firstOperation cancel];
    //    });
    
    [self waitForExpectationsWithTimeout:10 handler:^(NSError *error) {
        XCTAssert(nil == error);
        NSLog(@"%@", error);
        
        NSLog(@"operation cancelled  = %d", firstOperation.isCancelled);
    }];
}

- (void)testMultipleAsynchronousOperation {
    NSArray *data = @[@(-1), @(1), @(-3)];
    
    NSOperationQueue *queue = [NSOperationQueue new];
    
    queue.maxConcurrentOperationCount = 1;
    
    queue.suspended = YES;
    
    for (NSUInteger iterator = 0; iterator < 10; iterator++) {
        IDPAsyncNegativeValueCountingOperation *operation = [[IDPAsyncNegativeValueCountingOperation alloc] initWithArray:data];
        
        __weak typeof(operation) weakOperation = operation;
        operation.completionBlock = ^{
            __strong typeof(operation) strongOperation = weakOperation;
            if (!strongOperation) {
                return;
            }
            
            NSLog(@"operation %lu result = %lu", iterator, strongOperation.result);
        };
        
        [queue addOperation:operation];
    }
    
    queue.suspended = NO;
    
    [queue waitUntilAllOperationsAreFinished];
}

- (void)testBlockOperation {
    NSMutableArray *array = [NSMutableArray arrayWithArray:@[@(0)]];
    NSLock *lock = [NSLock new];
    
    volatile __block int32_t value = 0;
    
    [self measureBlock:^{
        NSOperationQueue *queue = [NSOperationQueue new];
        
        queue.suspended = YES;

        
        for (NSUInteger iterator = 0; iterator < 10000; iterator++) {
            [queue addOperationWithBlock:^{
//                OSSpinLockLock(&_spinLock);
                
                
                OSAtomicIncrement32(&value);
//                value++;
//                usleep(10);
                OSAtomicDecrement32(&value);
//                value--;
                
                while (OSAtomicCompareAndSwap32(value, value++, &value)) {
                    NSLog(@"weeee");
                }
                
//                OSSpinLockUnlock(&_spinLock);
                
                
//                @autoreleasepool {
//                    NSNumber *number = [array firstObject];
//                    
//                    number = @([number integerValue] + 1);
//                    
//                    array[0] = number;
//
////                    @synchronized(array) {
////                    [lock lock];
//                    OSSpinLockLock(&_spinLock);
//                    usleep(1);
//                        [array addObject:number];
//                    OSSpinLockUnlock(&_spinLock);
////                    [lock unlock];
////                    }
//                }
            }];
        }
        
        queue.suspended = NO;
        
        [queue waitUntilAllOperationsAreFinished];
        NSLog(@"%lu", value);
    }];
}

@end
