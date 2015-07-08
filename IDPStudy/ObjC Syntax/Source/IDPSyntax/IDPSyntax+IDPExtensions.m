//
//  IDPSyntax+IDPExtensions.m
//  IDPStudy
//
//  Created by Alexander Kradenkov on 7/7/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import "IDPSyntax+IDPExtensions.h"

@implementation IDPSyntax (IDPExtensions)

@dynamic myClassName;

#pragma mark -
#pragma mark Class Methods

+ (id)object {
    return [[[self alloc] init] autorelease];
}

#pragma mark -
#pragma mark Accessors

- (NSString *)myClassName {
    return NSStringFromClass([self class]);
}

@end
