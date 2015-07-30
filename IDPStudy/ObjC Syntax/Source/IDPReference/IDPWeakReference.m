//
//  IDPWeakReference.m
//  IDPStudy
//
//  Created by Alexander Kradenkov on 7/28/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import "IDPWeakReference.h"

@interface IDPWeakReference ()
@property (nonatomic, assign) id target;

@end

@implementation IDPWeakReference

@synthesize target = _target;

- (void)setTarget:(id)target {
    _target = target;
}

@end
