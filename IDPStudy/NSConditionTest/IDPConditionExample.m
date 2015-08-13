//
//  IDPConditionExample.m
//  IDPStudy
//
//  Created by Alexander Kradenkov on 8/13/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import "IDPConditionExample.h"

static NSUInteger   kIDPEnumeratedObjectsCount = 10;

@interface IDPConditionExample ()
@property (nonatomic, retain)   NSArray *array;
@property (nonatomic, retain)   NSCondition *condition;

@property (nonatomic, assign, getter=isCountDone)   volatile BOOL  countDone;
@property (nonatomic, assign)   NSUInteger  negativeCount;


- (NSUInteger)negativeNumbersCountInRange:(NSRange)range;

@end

@implementation IDPConditionExample

#pragma mark -
#pragma mark Class Methods

+ (void)performSynchronousTest {
    NSArray *origin = @[@(-1), @(2), @(3), @(-4), @(5), @(-1), @(2), @(3), @(-4), @(5), @(-1), @(2), @(3), @(-4), @(5)];
    
    NSUInteger originNegativeCount = 0;
    for (NSNumber *number in origin) {
        if ([number integerValue] < 0) {
            originNegativeCount++;
        }
    }
    
    IDPConditionExample *object = [[[self alloc] initWithArray:origin] autorelease];
    NSUInteger result = [object negativeNumberCount];

    NSAssert(result == originNegativeCount, @"counts not equal");
}

+ (void)performAsynchronousTest {
    NSArray *origin = @[@(-1), @(2), @(3), @(-4), @(5), @(-1), @(2), @(3), @(-4), @(5), @(-1), @(2), @(3), @(-4), @(5)];
    
    NSUInteger originNegativeCount = 0;
    for (NSNumber *number in origin) {
        if ([number integerValue] < 0) {
            originNegativeCount++;
        }
    }
    
    IDPConditionExample *object = [[[self alloc] initWithArray:origin] autorelease];
    NSUInteger result = [object negativeNumberCountAsynch];
    
    NSAssert(result == originNegativeCount, @"counts not equal");
}

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.array = nil;
    self.condition = nil;
    
    [super dealloc];
}

- (instancetype)initWithArray:(NSArray *)array {
    self = [super init];
    self.array = array;
    self.condition = [[[NSCondition alloc] init] autorelease];
    
    return self;
}

#pragma mark -
#pragma mark Public

- (NSUInteger)negativeNumberCount {
    NSUInteger result = 0;
    NSUInteger offset = 0;
    NSRange arrayRange = NSMakeRange(0, self.array.count);
    
    NSRange range = NSIntersectionRange(arrayRange, NSMakeRange(offset, kIDPEnumeratedObjectsCount));
    
    while (range.length) {
        result += [self negativeNumbersCountInRange:range];
        offset += range.length;
        
        range = NSIntersectionRange(arrayRange, NSMakeRange(offset, kIDPEnumeratedObjectsCount));
    }

    return result;
}

- (NSUInteger)negativeNumberCountAsynch  {
    NSUInteger result = 0;
    NSUInteger offset = 0;
    NSRange arrayRange = NSMakeRange(0, self.array.count);
    
    NSRange range = NSIntersectionRange(arrayRange, NSMakeRange(offset, kIDPEnumeratedObjectsCount));
    
    NSMutableArray *ranges = [NSMutableArray array];
    
    while (range.length) {
        [ranges addObject:[NSValue valueWithRange:range]];
        
        offset += range.length;
        range = NSIntersectionRange(arrayRange, NSMakeRange(offset, kIDPEnumeratedObjectsCount));
    }
    
    NSCondition *condition = self.condition;
    
    for (NSValue *rangeValue in ranges) {
        self.countDone = NO;
        [self performSelectorInBackground:@selector(negativeNumbersCountInRangeValue:) withObject:rangeValue];
        
        [condition lock];
        while (self.isCountDone == NO) {
            [condition wait];
        }
        
        result += self.negativeCount;
        
        [condition unlock];
    }
    
    return result;
}

#pragma mark -
#pragma mark Private

- (NSUInteger)negativeNumbersCountInRangeValue:(NSValue *)range {
    NSCondition *condition = self.condition;
    [condition lock];
    
    NSUInteger result = [self negativeNumbersCountInRange:[range rangeValue]];
    
    self.negativeCount = result;
    
    self.countDone = YES;
    [condition signal];
    
    
    [condition unlock];
    
    return result;
}

- (NSUInteger)negativeNumbersCountInRange:(NSRange)range {
    NSUInteger result = 0;
    NSArray *array = self.array;
    
    for (NSUInteger index = range.location; index < NSMaxRange(range); index++) {
        result += ([array[index] integerValue] < 0) ? 1 : 0;
    }
    
    return result;
}

@end
