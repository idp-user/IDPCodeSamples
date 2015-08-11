//
//  IDPMEssagingTest.m
//  IDPStudy
//
//  Created by Alexander Kradenkov on 8/11/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#import "IDPMessagingObject.h"

@interface IDPMEssagingTest : XCTestCase
@property (nonatomic, strong)   IDPMessagingObject    *object;
@end

@implementation IDPMEssagingTest

- (void)setUp {
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
    self.object = [IDPMessagingObject new];
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void)testForwarding {
    NSObject *parameter = [NSObject new];
    
    id object = self.object;
    SEL selectors[] = { kIDPMessagingVirtualSelector, kIDPMessagingActualSelector};
    
    NSUInteger selectorsCount = sizeof(selectors) / sizeof(SEL);
    for (NSUInteger index = 0; index < selectorsCount; index++) {
        SEL selector = selectors[index];
        NSLog(@"\n\nperforming %@\n\n", NSStringFromSelector(selector));
        [object performSelector:selector withObject:parameter];
    }
    
    NSLog(@"\n\nSecond attempt\n\n");
    for (NSUInteger index = 0; index < selectorsCount; index++) {
        SEL selector = selectors[index];
        NSLog(@"\n\nperforming %@\n\n", NSStringFromSelector(selector));
        [object performSelector:selector withObject:parameter];
    }
    // This is an example of a functional test case.
    XCTAssert(YES, @"Pass");
}



@end
