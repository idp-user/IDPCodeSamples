//
//  main.m
//  ObjC Syntax
//
//  Created by Alexander Kradenkov on 7/6/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "IDPSyntax.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
    }
    /*
    
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
    {
        // insert code here...
        NSLog(@"Hello, World!");
    }
    
    [pool drain];
    */
    
    id object = [[IDPSyntax alloc] init];
    ((IDPSyntax *)object)->_name = "name0";
   
    return 0;
}
