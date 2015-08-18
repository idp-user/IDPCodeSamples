//
//  IDPKeyValueObservableObject.h
//  IDPStudy
//
//  Created by Alexander Kradenkov on 8/18/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface IDPKeyValueObservableObject : NSObject
@property (nonatomic, copy)     NSString    *name;
@property (nonatomic, assign)   NSUInteger  age;

@property (nonatomic, assign, getter=isMarried)   BOOL        married;

@end
