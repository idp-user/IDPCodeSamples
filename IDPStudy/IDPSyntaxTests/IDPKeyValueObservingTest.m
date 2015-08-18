//
//  IDPKeyValueObservingTest.m
//  IDPStudy
//
//  Created by Alexander Kradenkov on 8/18/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>

#import "IDPKeyValueObserver.h"

@interface IDPKeyValueObservingTest : XCTestCase

@end

@implementation IDPKeyValueObservingTest

- (void)setUp {
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void)testObserving {
    IDPKeyValueObserver *observer = [IDPKeyValueObserver new];
    @autoreleasepool {
        IDPKeyValueObservableObject *observableObject = [IDPKeyValueObservableObject new];
        
        observer.observableObject = observableObject;
        
        NSLog(@"start change");
        
        NSString *originName = @"NAME#1";
        
        observableObject.name = originName;
        observableObject.name = originName;
        
        observableObject.age = 1;
        observableObject.name = @"NAME#2";
        observableObject.married = YES;
        observableObject.name = @"MARRIED";
        observableObject.married = NO;
        
        observableObject.name = nil;
        
        observableObject = nil;
    }
    
    observer.observableObject.age = 10;
    
    observer.observableObject = nil;
    
    
    // This is an example of a functional test case.
    XCTAssert(YES, @"Pass");
}

@end
