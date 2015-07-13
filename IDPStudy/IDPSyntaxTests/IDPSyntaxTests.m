//
//  IDPSyntaxTests.m
//  IDPSyntaxTests
//
//  Created by Alexander Kradenkov on 7/8/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>

#import "IDPEqualityObject.h"

@interface IDPSyntaxTests : XCTestCase

@end

@implementation IDPSyntaxTests

- (void)setUp {
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void)testEqualityObject {
    IDPEqualityObject *object = [IDPEqualityObject new];
    IDPEqualityObject *object2 = [IDPEqualityObject new];
    
    NSString *string =  @"some string";
    object.valueName = string;
    object2.valueName = string;
    
    XCTAssertNotEqual(object, object2);
    XCTAssertTrue([object isEqualToObject:object2]);
    XCTAssertTrue([object isEqual:object2]);
    XCTAssertEqual([object hash], [object2 hash]);
    
    NSSet *set = [NSSet setWithObjects:object, object2, nil];
    
    XCTAssertEqual(1, [set count]);
}

- (void)testCopying {
    IDPEqualityObject *object = [[IDPEqualityObject alloc] init];
    
    XCTAssertTrue([object conformsToProtocol:@protocol(NSCopying)]);
    
    IDPEqualityObject *object2 = [object copy];
    
    XCTAssertNotEqual(object, object2);
    XCTAssertTrue([object isEqual:object2]);
    
    object.valueName = @"Text";
    object.value = 123;
    
    object2 = [object copy];
    
    XCTAssertTrue([@"Text" isEqualTo:object2.valueName]);
    XCTAssertTrue(123 == object2.value);
    
    XCTAssertNotEqual(object, object2);
    XCTAssertTrue([object isEqual:object2]);
}

- (void)testTollFreeBridging {
    
    NSDictionary *dictionary = @{@"key" : @"value"};

    NSLog(@"%lu", CFGetRetainCount((CFDictionaryRef)dictionary));
    
    CFDictionaryRef cfDictionary = CFBridgingRetain(dictionary);
    NSLog(@"%lu", CFGetRetainCount(cfDictionary));
    dictionary = nil;
    
    NSLog(@"%lu", CFGetRetainCount(cfDictionary));
    
    CFRelease(cfDictionary);
}

@end
