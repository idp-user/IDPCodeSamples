//
//  IDPConditionExample.h
//  IDPStudy
//
//  Created by Alexander Kradenkov on 8/13/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface IDPConditionExample : NSObject

+ (void)performSynchronousTest;
+ (void)performAsynchronousTest;

- (instancetype)initWithArray:(NSArray *)array;

- (NSUInteger)negativeNumberCount;

- (NSUInteger)negativeNumberCountAsynch;

@end
