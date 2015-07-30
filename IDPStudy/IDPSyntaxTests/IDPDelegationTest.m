//
//  IDPDelegationTest.m
//  IDPStudy
//
//  Created by Alexander Kradenkov on 7/30/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>

#import "IDPParentObject.h"
#import "IDPBabyObject.h"

@interface IDPDelegationTest : XCTestCase

@end

@implementation IDPDelegationTest

- (void)testDelegation {
    IDPBabyObject *child = [IDPBabyObject new];
    IDPParentObject *parent = [IDPParentObject new];
    
    parent.child = child;
    
    child.pampers = [NSObject new];
    
    XCTAssertEqual(parent, child.delegate);
    
    id pampers = child.pampers;
    
    [child startSleep];
    
    XCTAssertNotEqual(pampers, child.pampers);

}

@end
