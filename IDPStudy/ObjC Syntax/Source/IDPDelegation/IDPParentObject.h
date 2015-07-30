//
//  IDPParentObject.h
//  IDPStudy
//
//  Created by Alexander Kradenkov on 7/30/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "IDPBabyObject.h"

@interface IDPParentObject : NSObject <IDPBabyDelegate>
@property (nonatomic, retain)   IDPBabyObject   *child;


@end
