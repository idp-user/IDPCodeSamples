//
//  IDPEnumeratedString.m
//  IDPStudy
//
//  Created by Alexander Kradenkov on 7/23/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import <Kiwi/Kiwi.h>

#import "IDPEnumeratedString.h"


SPEC_BEGIN(IDPEnumeratedStringSpec)

describe(@"IDPEnumeratedString", ^{
    context(@"NSFastEnumeration", ^{
        __block IDPEnumeratedString *string = [IDPEnumeratedString new];
        string.string = @"123ABCabc";
        
        it(@"shouldn't raise while enumeration", ^{
            for(NSString *object in string) {
                NSLog(@"%@", object);
                
            }
            
        });
        
    });
    
    context(@"inherit", ^{
        __block IDPEnumeratedString *string = nil;
        
        beforeAll(^{
            string = [IDPEnumeratedString new];
            string.string = @"123ABCabc";
            
            NSLog(@"");
        });
        
        it(@"should be subclass of NSString", ^{
            [[string shouldNot] beKindOfClass:[NSString class]];
            
            NSLog(@"");
        });
    });
});

SPEC_END


