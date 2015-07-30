//
//  IDPBabyObject.h
//  IDPStudy
//
//  Created by Alexander Kradenkov on 7/30/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "IDPBabyDelegate.h"

@interface IDPBabyObject : NSObject
@property (nonatomic, retain)   NSObject            *pampers;
@property (nonatomic, assign)   id<IDPBabyDelegate> delegate;

- (void)startSleep;


@end
