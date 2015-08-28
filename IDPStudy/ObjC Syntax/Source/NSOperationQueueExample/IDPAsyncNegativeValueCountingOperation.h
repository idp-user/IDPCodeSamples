//
//  IDPAsyncNegativeValueCountingOperation.h
//  IDPStudy
//
//  Created by Alexander Kradenkov on 8/27/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import "IDPAsynchronousOperation.h"

@interface IDPAsyncNegativeValueCountingOperation : IDPAsynchronousOperation
@property (nonatomic, readonly) NSArray     *array;
@property (nonatomic, readonly) NSUInteger  result;

- (instancetype)initWithArray:(NSArray *)array;

@end
