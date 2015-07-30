//
//  IDPObservableObjectSpec.m
//  IDPStudy
//
//  Created by Alexander Kradenkov on 7/28/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import <Kiwi/Kiwi.h>

#import "IDPObservableObject.h"
#import "IDPWeakReference.h"

SPEC_BEGIN(IDPObservableObjectSpec)

describe(@"IDPObservableObject", ^{
    context(@"after was created", ^{
        __block IDPObservableObject *object = nil;
        beforeAll(^{
            object = [IDPObservableObject new];
            NSLog (@"%@", object);
        });
        
        it(@"object must not be nil", ^{
            [[object should] beNonNil];
        });
        
        it(@"observer count must be 0", ^{
            [[theValue([object.observers count]) should] equal:theValue(0)];
        });
        
        context(@"after observer added", ^{
            id observer = [NSObject new];
            beforeAll(^{
                [object addObserver:observer];
            });
            
            it(@"observer must be equal to object", ^{
                id observerObject = [object.observers firstObject];
                [[observerObject should] beIdenticalTo:observer];
            });
            
            it(@"contain 1 observer", ^{
                [[theValue([object.observers count]) should] equal:theValue(1)];
            });
            
            afterAll(^{
                [object removeObserver:observer];
            });
        });
        
        context(@"after observer added twice", ^{
            id observer2 = [NSObject new];
            
            beforeAll(^{
                [object addObserver:observer2];
                [object addObserver:observer2];
            });
            
            it(@"contain 1 observer", ^{
                NSArray *observers = object.observers;
                
                [[theValue([observers count]) should] equal:theValue(1)];
            });
            
            it(@"observer must be equal to object", ^{
                id observerObject = [object.observers firstObject];
                [[observerObject should] beIdenticalTo:observer2];
            });
            
            it(@"observers should receive (SEL)description", ^{
                SEL selector = @selector(description);
                [[observer2 should] receive:selector];
                
                [object notifyObserversWithSelector:selector];
            });
            
            afterAll(^{
                [object removeObserver:observer2];
            });
        });
    });
    
    context(@"after observer added and removed", ^{
        IDPObservableObject *object2 = [IDPObservableObject new];
        id observer3 = [NSObject new];
        
        beforeAll(^{
            [object2 addObserver:observer3];
            [object2 removeObserver:observer3];
        });
        
        it(@"contain 0 observer", ^{
            NSArray *observers = object2.observers;
            [[theValue([observers count]) should] equal:theValue(0)];
        });
        
        it(@"observer shouldn't receive (SEL)description", ^{
            SEL selector = @selector(description);
            [[observer3 shouldNot] receive:selector];
            
            [object2 notifyObserversWithSelector:selector];
        });
    });
});

SPEC_END