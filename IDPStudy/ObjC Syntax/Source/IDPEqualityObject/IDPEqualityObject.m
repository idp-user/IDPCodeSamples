//
//  IDPEqualityObject.m
//  IDPStudy
//
//  Created by Alexander Kradenkov on 7/9/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import "IDPEqualityObject.h"

@implementation IDPEqualityObject

#pragma mark -
#pragma mark Public

- (BOOL)isEqualToObject:(IDPEqualityObject *)object {
    if([object isMemberOfClass:[self class]]) {
        NSString *valueName = self.valueName;
        NSString *objectValueName = object.valueName;
        
        if (valueName) {
            return ([valueName isEqualToString:objectValueName]
                    && self.value == object.value);
        } else {
            return object.valueName == nil && self.value == object.value;
        }
    }
    
    return NO;
}

#pragma mark -
#pragma mark NSObject

- (NSUInteger)hash {
    return ([self.valueName hash] ^ self.value);
}

- (BOOL)isEqual:(id)object {
    return [self isEqualToObject:object];
}

#pragma mark -
#pragma mark NSCopying

- (id)copyWithZone:(NSZone *)zone {
    IDPEqualityObject *object = [[[self class] alloc] init];
    object.valueName = self.valueName;
    object.value = self.value;
    
    
    return object;
}

@end
