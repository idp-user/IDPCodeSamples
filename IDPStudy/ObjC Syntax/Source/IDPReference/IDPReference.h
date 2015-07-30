//
//  IDPReference.h
//  IDPStudy
//
//  Created by Alexander Kradenkov on 7/28/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface IDPReference : NSObject <NSCopying>
@property (nonatomic, retain)   id  target;

/// override in subclass
- (instancetype)initWithTarget:(id)object;

@end
