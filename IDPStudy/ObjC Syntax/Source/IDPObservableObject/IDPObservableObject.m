//
//  IDPObservableObject.m
//  IDPStudy
//
//  Created by Alexander Kradenkov on 7/28/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import "IDPObservableObject.h"

#import "IDPWeakReference.h"

@interface IDPObservableObject ()
@property (nonatomic, retain)   NSMutableSet    *mutableObservers;

@end

@implementation IDPObservableObject

@dynamic observers;

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.mutableObservers = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.mutableObservers = [NSMutableSet set];
    }
    
    return self;
}


#pragma mark -
#pragma mark Accessors

- (NSArray *)observers {
//    return [self.mutableObservers allObjects];
    NSMutableSet *result = [NSMutableSet set];
    for (IDPReference *reference in self.mutableObservers) {
        id target = reference.target;
        if (target) {
            [result addObject:target];
        }
    }
    
    return [result allObjects];
}

#pragma mark -
#pragma mark Public Methods

- (void)addObserver:(id)observer {
    IDPWeakReference *reference = [[[IDPWeakReference alloc] initWithTarget:observer] autorelease];
    
    [self.mutableObservers addObject:reference];
}

- (void)removeObserver:(id)observer {
    NSArray *array = [self.mutableObservers allObjects];
    for (IDPWeakReference *reference in array) {
        if (reference.target == observer) {
            [self.mutableObservers removeObject:reference];
            
            break;
        }
    }
}

- (void)notifyObserversWithSelector:(SEL)selector {
    [self notifyObserversWithSelector:selector withObject:nil];
}

- (void)notifyObserversWithSelector:(SEL)selector withObject:(id)object {
    [self notifyObserversWithSelector:selector withObject:object withObject:nil];
}

- (void)notifyObserversWithSelector:(SEL)selector withObject:(id)object withObject:(id)object2 {
    NSArray *observers = self.observers;
    for (id observer in observers) {
        if ([observer respondsToSelector:selector]) {
            [observer performSelector:selector withObject:object withObject:object2];
        }
    }
}

@end
