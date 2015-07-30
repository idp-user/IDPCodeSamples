//
//  IDPBabyDelegate.h
//  IDPStudy
//
//  Created by Alexander Kradenkov on 7/30/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import <Foundation/Foundation.h>

@class IDPBabyObject;

@protocol IDPBabyDelegate <NSObject>



@optional
- (NSObject *)cleanPampersForBaby:(IDPBabyObject *)child;

@end
