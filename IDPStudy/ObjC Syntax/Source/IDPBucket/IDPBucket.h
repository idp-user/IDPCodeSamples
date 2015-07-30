//
//  IDPBucket.h
//  IDPStudy
//
//  Created by Alexander Kradenkov on 7/29/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import "IDPObservableObject.h"

#import "IDPBucketObserver.h"

typedef NS_ENUM(NSUInteger, IDPBucketState) {
    kIDPBucketStateEmpty,
    kIDPBucketStateNotEmpty,
    kIDPBucketStateFull
};


@interface IDPBucket : IDPObservableObject
@property (nonatomic, readonly) IDPBucketState  state;
@property (nonatomic, readonly) NSUInteger      capacity;

@property (nonatomic, assign)   NSUInteger      litersContained;

- (instancetype)initWithCapacity:(NSUInteger)capacity;

- (SEL)selectorForState:(IDPBucketState)state;

@end
