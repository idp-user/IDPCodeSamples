//
//  IDPBabyObject.m
//  IDPStudy
//
//  Created by Alexander Kradenkov on 7/30/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import "IDPBabyObject.h"

@implementation IDPBabyObject

#pragma mark -
#pragma mark Public

- (void)startSleep {
    id<IDPBabyDelegate> delegate = self.delegate;
    
    if (delegate && [delegate respondsToSelector:@selector(cleanPampersForBaby:)]) {
        NSObject *pampers = [delegate cleanPampersForBaby:self];
        
        self.pampers = pampers;
    }
}

@end
