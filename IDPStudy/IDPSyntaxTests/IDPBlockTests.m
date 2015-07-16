//
//  IDPBlockTests.m
//  IDPStudy
//
//  Created by Alexander Kradenkov on 7/15/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>

@interface IDPBlockTests : XCTestCase
@property (nonatomic, copy) void (^voidBlock)(void);
@end

@implementation IDPBlockTests

- (void)setUp {
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void)testStackBlock {
    void (^voidBlock)(void);
    NSLog(@"lambda\n\n\n");
    voidBlock = ^{
        NSLog(@"Hello!");
    };
    
    NSLog(@"%@", voidBlock);
    voidBlock();
    
    NSLog(@"property lambda\n\n\n");
    self.voidBlock = voidBlock;
    NSLog(@"%@", self.voidBlock);
    self.voidBlock();
    
    NSLog(@"\nclosure\n\n\n");
    
    int value = 13;
    
    NSString *string = [NSString stringWithFormat:@"str%d", value];
    string = [string mutableCopy];
    
    NSLog(@"%@ %lu", string, CFGetRetainCount((__bridge CFStringRef)string));
    
    voidBlock = ^{
        NSLog(@"%@ %lu", string, CFGetRetainCount((CFStringRef)string));
    };
    
    NSLog(@"%@ %lu", string, CFGetRetainCount((__bridge CFStringRef)string));
    
    NSLog(@"%@", voidBlock);
    
    voidBlock();

    voidBlock = nil;
    
    NSLog(@"\nproperty closure\n\n\n");
    NSLog(@"%@ %lu", string, CFGetRetainCount((__bridge CFStringRef)string));
    
    self.voidBlock = ^{
        NSLog(@"%@ %lu", string, CFGetRetainCount((CFStringRef)string));
    };
    NSLog(@"%@ %lu", string, CFGetRetainCount((CFStringRef)string));
    
    NSLog(@"%@", string);
    
    NSLog(@"%@", self.voidBlock);
    
    self.voidBlock();
    
    NSLog(@"\n__block used by closure\n\n\n");
    __block int blockValue = 43;
    
    voidBlock = ^ {
         NSLog(@"%d", blockValue);
    };
    
    NSLog(@"%@", voidBlock);
    voidBlock();
}

@end
