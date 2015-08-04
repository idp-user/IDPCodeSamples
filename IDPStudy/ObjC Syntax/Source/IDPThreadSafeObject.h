//
//  IDPThreadSafeObject.h
//  IDPStudy
//
//  Created by Alexander Kradenkov on 8/4/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import "IDPThreadUnsafeObject.h"

@interface IDPThreadSafeObject : IDPThreadUnsafeObject
@property (nonatomic, readonly)   NSArray  *objects;

- (void)addObject:(id)object;

- (void)addObjectWhileSelfSynchronized:(id)object;

@end
