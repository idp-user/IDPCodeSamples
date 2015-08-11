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
    SEL selectors[] = { @selector(description),
                        kIDPMessagingVirtualSelector,
                        kIDPMessagingActualSelector};
    NSUInteger selectorsCount = sizeof(selectors) / sizeof(SEL);
    
    NSLog(@"\n\nFirst attempt\n\n");
    [self object:object performTestSelectors:selectors count:selectorsCount withObject:parameter];

    NSLog(@"\n\nSecond attempt\n\n");
    [self object:object performTestSelectors:selectors count:selectorsCount withObject:parameter];
    
    // This is an example of a functional test case.
    XCTAssert(YES, @"Pass");
}

#pragma mark -
#pragma mark Private

- (void)        object:(id)object
  performTestSelectors:(SEL[])selectors
                 count:(NSUInteger)selectorsCount
            withObject:(id)parameter
{
    for (NSUInteger index = 0; index < selectorsCount; index++) {
        SEL selector = selectors[index];
        NSString *selectorString = [NSString stringWithFormat:@"@selector(%@)", NSStringFromSelector(selector)];
        NSLog(@"\n\nPerforming %@\n[object respondsToSelector:%@] %@\n\n",
              selectorString,
              selectorString,
              [object respondsToSelector:selector] ? @"YES" : @"NO");
        
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Warc-performSelector-leaks"
        
        [object performSelector:selector withObject:parameter];
        
#pragma clang diagnostic pop

        
    }
}


@end
