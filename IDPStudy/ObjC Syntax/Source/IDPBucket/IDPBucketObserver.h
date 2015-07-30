//
//  IDPBucketObserver.h
//  IDPStudy
//
//  Created by Alexander Kradenkov on 7/29/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import <Foundation/Foundation.h>

@class IDPBucket;

@protocol IDPBucketObserver <NSObject>

@optional

- (void)bucketBecomeEmpty:(IDPBucket *)bucket;
- (void)bucketContentHasChanged:(IDPBucket *)bucket;
- (void)bucketBecomeFull:(IDPBucket *)bucket;

@end
