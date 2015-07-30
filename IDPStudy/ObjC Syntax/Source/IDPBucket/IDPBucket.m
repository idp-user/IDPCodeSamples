//
//  IDPBucket.m
//  IDPStudy
//
//  Created by Alexander Kradenkov on 7/29/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import "IDPBucket.h"

#define kIDPStateSelectors  @{@(kIDPBucketStateEmpty)     : NSStringFromSelector(@selector(bucketBecomeEmpty:)), \
                              @(kIDPBucketStateNotEmpty)  : NSStringFromSelector(@selector(bucketContentHasChanged:)), \
                              @(kIDPBucketStateFull)      : NSStringFromSelector(@selector(bucketBecomeFull:))}

@interface IDPBucket ()
@property (nonatomic, assign)   IDPBucketState  state;

@property (nonatomic, assign, readwrite)   NSUInteger      capacity;

- (void)onLitersChange;


@end

@implementation IDPBucket

#pragma mark -
#pragma mark Initializaqtions and Deallocations

- (instancetype)init {
    return [self initWithCapacity:0];
}

- (instancetype)initWithCapacity:(NSUInteger)capacity {
    self = [super init];
    if (self) {
        self.capacity = capacity;
        
        [self onLitersChange];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (void)setLitersContained:(NSUInteger)litersContained {
    if (_litersContained != litersContained) {
        _litersContained = MIN(litersContained, _capacity);
        
        [self onLitersChange];
    }
}

- (void)setState:(IDPBucketState)state {
    if (_state != state) {
        _state = state;
        
        [self notifyObserversWithSelector:[self selectorForState:state] withObject:self];
    }
}

#pragma mark -
#pragma mark Public

- (SEL)selectorForState:(IDPBucketState)state {
    NSDictionary *dictionary = kIDPStateSelectors;
    
    return NSSelectorFromString(dictionary[@(state)]);
}

- (void)addObserver:(id<IDPBucketObserver>)observer {
    [super addObserver:observer];
}

- (void)removeObserver:(id<IDPBucketObserver>)observer {
    [super removeObserver:observer];
}

#pragma mark -
#pragma mark Private

- (void)onLitersChange {
    NSUInteger capacity = self.capacity;
    NSUInteger liters = self.litersContained;
    
    if (capacity == liters) {
        self.state = kIDPBucketStateFull;
    } else if (0 == liters) {
        self.state = kIDPBucketStateEmpty;
    } else {
        self.state = kIDPBucketStateNotEmpty;
    }
    
    [self notifyObserversWithSelector:@selector(bucketContentHasChanged:) withObject:self];
    
//    self.state = (capacity == liters
//                  ? kIDPBucketStateFull
//                  : (0 == liters ? kIDPBucketStateEmpty : kIDPBucketStateNotEmpty));
}

@end
