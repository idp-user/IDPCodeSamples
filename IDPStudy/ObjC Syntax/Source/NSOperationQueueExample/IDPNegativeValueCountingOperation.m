//
//  IDPNegativeValueCountingOperation.m
//  IDPStudy
//
//  Created by Alexander Kradenkov on 8/26/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import "IDPNegativeValueCountingOperation.h"

@interface IDPNegativeValueCountingOperation ()
@property (nonatomic, retain)               NSArray     *array;
@property (nonatomic, assign, readwrite)    NSUInteger  result;

@end

@implementation IDPNegativeValueCountingOperation

#pragma mark -
#pragma mark Initalizations a nd Deallocations

- (void)dealloc {
    self.array = nil;
    
    [super dealloc];
}

- (instancetype)initWithArray:(NSArray *)array {
    self = [super init];
    self.array = array;
    
    return self;
}

#pragma mark -
#pragma mark Public

- (void)main {
    NSArray *array = self.array;
    NSUInteger result = 0;
    
    for (NSNumber *value in array) {
        if (self.isCancelled) {
            break;
        }
        sleep(1);
        
        if (NSOrderedAscending == [value compare:@(0)]) {
            result++;
        }
    }
    
    if (NO == [self isCancelled]) {
        self.result = result;
    }
}

@end
