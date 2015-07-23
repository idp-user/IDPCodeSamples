//
//  IDPEnumeratedString.m
//  IDPStudy
//
//  Created by Alexander Kradenkov on 7/23/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import "IDPEnumeratedString.h"


@implementation IDPEnumeratedString

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.string = nil;
    
    [super dealloc];
}

#pragma mark -
#pragma mark NSFastEnumeration

- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state
                                  objects:(id [])buffer
                                    count:(NSUInteger)len
{
    NSString *string = self.string;
    state->mutationsPtr = (unsigned long *)self; //(unsigned long *)string;
    
    NSUInteger currentOffset = state->extra[0];
    
    NSUInteger result = MIN(currentOffset + len, string.length);
    result -= currentOffset;
    
    for (NSUInteger index = 0; index < result; index++) {
        unichar symbol = [string characterAtIndex:(currentOffset + index)];
        
        NSString *symbolString = [NSString stringWithFormat:@"%C", symbol];
        buffer[index] = symbolString;
        
    }
    
    state->itemsPtr = buffer;
    state->extra[0] += result;
    
    return result;
}

@end
