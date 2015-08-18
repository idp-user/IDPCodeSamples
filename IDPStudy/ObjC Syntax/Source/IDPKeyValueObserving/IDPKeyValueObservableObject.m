//
//  IDPKeyValueObservableObject.m
//  IDPStudy
//
//  Created by Alexander Kradenkov on 8/18/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import "IDPKeyValueObservableObject.h"

@implementation IDPKeyValueObservableObject

#pragma mark -
#pragma mark Class Methods

//
//+ (BOOL)automaticallyNotifiesObserversForKey:(NSString *)key {
//    return NO == [key isEqualToString:@"name"];
//}

+ (BOOL)automaticallyNotifiesObserversOfName {
    return NO;
}

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.name = nil;
    
    [super dealloc];
}

#pragma mark -
#pragma mark Accessors

- (void)setName:(NSString *)name {
    if (_name != name) {
        [self willChangeValueForKey:NSStringFromSelector(@selector(name))];
        
        [_name release];
        _name = [name copy];
        
        [self didChangeValueForKey:NSStringFromSelector(@selector(name))];
    }
}

@end
