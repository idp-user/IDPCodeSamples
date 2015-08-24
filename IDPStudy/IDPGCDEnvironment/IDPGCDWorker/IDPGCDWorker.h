//
//  IDPGCDWorker.h
//  IDPStudy
//
//  Created by Alexander Kradenkov on 8/19/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface IDPGCDWorker : NSObject

@property (nonatomic, copy) dispatch_block_t    backgroundBlock;
@property (nonatomic, copy) dispatch_block_t    completionBlock;

- (void)executeBarrier;

- (void)executeWithNotificationOnMainQueue;

- (void)executeOnce;

- (void)executeApply;

- (void)executeGroup;
@end
