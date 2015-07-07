//
//  main.m
//  ObjC Syntax
//
//  Created by Alexander Kradenkov on 7/6/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <objc/objc-runtime.h>

#import "IDPSyntax.h"
#import "IDPSyntaxSubclass.h"
#import "IDPSyntax+IDPExtensions.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        
        id object = [IDPSyntax object];
        
        IDPSyntaxSubclass *subclass = [IDPSyntaxSubclass syntax];
        
        
        SEL fooSelector = @selector(foo);

        [object foo];
        [object performSelector:fooSelector withObject:nil];

        
        objc_msgSend(object, fooSelector, nil);
        
        
//        ((IDPSyntax *)object)->_name = "name0";
        
        IDPSyntax *syntax = object;

        NSArray *array = @[@"1", @(3)];
        [syntax protocolFoo];
        [syntax protocolFooWithArgument:@"NSSTRING_VALUE"
                         secondArgument:@{@"floatValue" : @(1.2f),
                                          @"intValue" : @(2)}
                                  count:[array count]];
        
        if (YES == [syntax respondsToSelector:@selector(protocolFooWithArgument:)]) {
            [syntax protocolFooWithArgument:array];
        }
        
        [IDPSyntax syntaxTest];
    }
    
    BOOL boolValue = YES; boolValue = NO;
    /*
    
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
    {
        // insert code here...
        NSLog(@"Hello, World!");
    }
    
    [pool drain];
    */
    

   
    return 0;
}
