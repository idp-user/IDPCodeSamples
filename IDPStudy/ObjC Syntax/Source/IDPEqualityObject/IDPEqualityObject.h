//
//  IDPEqualityObject.h
//  IDPStudy
//
//  Created by Alexander Kradenkov on 7/9/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface IDPEqualityObject : NSObject <NSCopying>
@property (nonatomic, copy)     NSString    *valueName;
@property (nonatomic, assign)   uint64_t    value;

- (BOOL)isEqualToObject:(IDPEqualityObject *)object;

@end
