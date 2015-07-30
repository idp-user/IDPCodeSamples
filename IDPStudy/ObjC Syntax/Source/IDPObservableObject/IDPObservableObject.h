//
//  IDPObservableObject.h
//  IDPStudy
//
//  Created by Alexander Kradenkov on 7/28/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface IDPObservableObject : NSObject
@property (nonatomic, readonly) NSArray     *observers;

- (void)addObserver:(id)observer;
- (void)removeObserver:(id)observer;

- (void)notifyObserversWithSelector:(SEL)selector;
- (void)notifyObserversWithSelector:(SEL)selector withObject:(id)object;
- (void)notifyObserversWithSelector:(SEL)selector withObject:(id)object withObject:(id)object2;

@end
