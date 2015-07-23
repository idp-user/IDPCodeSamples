//
//  IDPKiwiTestExample.m
//  IDPStudy
//
//  Created by Alexander Kradenkov on 7/22/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import <Kiwi/Kiwi.h>


SPEC_BEGIN(IDPKiwiExampleSpec)

describe(@"Example description", ^{
    context(@"NSObject", ^{
        NSObject *object = [NSObject new];
        it(@"should be of NSObject class", ^{
            [[object should] beKindOfClass:[NSObject class]];
        });
        
        it(@"shouldn't be nil", ^{
            [[object should] beNonNil];
        });
    });
});

SPEC_END