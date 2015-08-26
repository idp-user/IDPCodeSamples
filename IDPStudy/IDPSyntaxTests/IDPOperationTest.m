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

@interface IDPOperationTest : XCTestCase

@end

@implementation IDPOperationTest

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
    queue.maxConcurrentOperationCount = 2;
    
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

@end
