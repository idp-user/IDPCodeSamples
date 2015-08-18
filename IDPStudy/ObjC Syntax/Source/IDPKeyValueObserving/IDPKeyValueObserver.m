//
//  IDPKeyValueObserver.m
//  IDPStudy
//
//  Created by Alexander Kradenkov on 8/18/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import "IDPKeyValueObserver.h"


@interface IDPKeyValueObserver ()

- (void)onObservableObjectChange;

@end

@implementation IDPKeyValueObserver

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.observableObject = nil;
    
    [super dealloc];
}


#pragma mark -
#pragma mark  Accessors

- (void)setObservableObject:(IDPKeyValueObservableObject *)observableObject {
    if (_observableObject != observableObject) {
        NSArray *keyPaths = @[NSStringFromSelector(@selector(name)),
                              NSStringFromSelector(@selector(age)),
                              NSStringFromSelector(@selector(isMarried))];
        
        for (NSString *key in keyPaths) {
            [_observableObject removeObserver:self forKeyPath:key];
        }
        
        [_observableObject release];
        _observableObject = [observableObject retain];
        
        [self onObservableObjectChange];
    }
}


- (void)onObservableObjectChange {
    IDPKeyValueObservableObject *object = self.observableObject;
    
    NSArray *keyPaths = @[NSStringFromSelector(@selector(name)),
                          NSStringFromSelector(@selector(age)),
                          NSStringFromSelector(@selector(isMarried))];
    
    NSKeyValueObservingOptions observerOptions = (NSKeyValueObservingOptionNew
                                                  | NSKeyValueObservingOptionOld
                                                  | NSKeyValueObservingOptionInitial);
    
    for (NSString *key in keyPaths) {
        [object addObserver:self
                 forKeyPath:key
                    options:observerOptions
                    context:nil];
    }
}


- (void)observeValueForKeyPath:(NSString *)keyPath
                      ofObject:(id)object
                        change:(NSDictionary *)change
                       context:(void *)context
{
    NSLog(@"%@ %@ %@ %@", self, object, keyPath, change);
}


@end
