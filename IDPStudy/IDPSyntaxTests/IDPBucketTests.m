//
//  IDPBucketTests.m
//  IDPStudy
//
//  Created by Alexander Kradenkov on 7/30/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>

#import "IDPBucket.h"

@interface IDPBucketTests : XCTestCase <IDPBucketObserver>
@property (nonatomic, strong)   IDPBucket   *bucket;
@property (nonatomic, assign)   NSUInteger  expectedLiters;

@end

@implementation IDPBucketTests

#pragma mark -
#pragma mark Accessors

- (void)setBucket:(IDPBucket *)bucket {
    if (_bucket != bucket) {
        [_bucket removeObserver:self];
        
//        [bucket retain];
//        [_bucket release];
        
        _bucket = bucket;
        
        [bucket addObserver:self];
    }
}

#pragma mark -
#pragma mark Tests

- (void)setUp {
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
    self.bucket = [[IDPBucket alloc] initWithCapacity:10];
    self.expectedLiters = 0;
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void)testTenLitersBucket {
    IDPBucket *bucket = self.bucket;
    
    XCTAssertEqual(10, bucket.capacity);
    XCTAssertEqual(self.expectedLiters, bucket.litersContained);
    XCTAssertEqual(kIDPBucketStateEmpty, bucket.state);
    
    self.expectedLiters = 1;
    bucket.litersContained = 1;
    XCTAssertEqual(1, bucket.litersContained);
    XCTAssertEqual(kIDPBucketStateNotEmpty, bucket.state);
    
    self.expectedLiters = 10;
    bucket.litersContained = 300;
    XCTAssertEqual(bucket.capacity, bucket.litersContained);
    XCTAssertEqual(kIDPBucketStateFull, bucket.state);
    
    self.expectedLiters = 0;
    bucket.litersContained = 0;
    XCTAssertEqual(0, bucket.litersContained);
    XCTAssertEqual(kIDPBucketStateEmpty, bucket.state);    
}

#pragma mark -
#pragma mark IDPBucketObserver

- (void)bucketBecomeEmpty:(IDPBucket *)bucket {
    XCTAssertEqual(0, bucket.litersContained);
    XCTAssertEqual(kIDPBucketStateEmpty, bucket.state);
}

- (void)bucketBecomeFull:(IDPBucket *)bucket {
    XCTAssertEqual(bucket.capacity, bucket.litersContained);
    XCTAssertEqual(kIDPBucketStateFull, bucket.state);
}

- (void)bucketContentHasChanged:(IDPBucket *)bucket {
    NSUInteger expectation = self.expectedLiters;
    NSUInteger capacity = bucket.capacity;
    XCTAssertEqual(self.expectedLiters, bucket.litersContained);
    
    if (expectation == capacity) {
        XCTAssertEqual(kIDPBucketStateFull, bucket.state);
    } else if (0 == expectation) {
        XCTAssertEqual(kIDPBucketStateEmpty, bucket.state);
    } else {
        XCTAssertEqual(kIDPBucketStateNotEmpty, bucket.state);
    }
}

@end
