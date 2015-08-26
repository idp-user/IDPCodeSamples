//
//  IDPNegativeValueCountingOperation.h
//  IDPStudy
//
//  Created by Alexander Kradenkov on 8/26/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface IDPNegativeValueCountingOperation : NSOperation
@property (nonatomic, readonly) NSArray     *array;
@property (nonatomic, readonly) NSUInteger  result;

- (instancetype)initWithArray:(NSArray *)array;

@end
