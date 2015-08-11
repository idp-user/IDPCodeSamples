//
//  IDPMessagingObject.h
//  IDPStudy
//
//  Created by Alexander Kradenkov on 8/11/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import <Foundation/Foundation.h>

#define kIDPMessagingVirtualSelector @selector(foo:)
#define kIDPMessagingActualSelector     @selector(privateFoo:)

@interface IDPMessagingObject : NSObject

// removes warning messages
- (void)foo:(id)object;
- (void)privateFoo:(id)object;

@end
