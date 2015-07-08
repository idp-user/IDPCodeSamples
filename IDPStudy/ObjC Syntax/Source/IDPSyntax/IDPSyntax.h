//
//  IDPSyntax.h
//  IDPStudy
//
//  Created by Alexander Kradenkov on 7/6/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol IDPObjectSyntax

@required
+ (id)objectForClass:(Class)objectClass;

- (void)protocolFoo; // "protocolFoo"

@optional
- (void)protocolFooWithArgument:(id)argument; // SEL: "protocolFooWithArgument:"
- (void)protocolFooWithArgument:(id)argument secondArgument:(id)argumant2; // SEL: "protocolFooWithArgument:secondArgument:"

@required
- (uint64_t)protocolFooWithArgument:(id)argument secondArgument:(id)argumant2 count:(uint64_t)count; // SEL: "protocolFooWithArgument:secondArgument:count:"

@end

@interface IDPSyntax : NSObject <IDPObjectSyntax> {
    @private
    id _ivar;
}
@property (nonatomic, assign)   int     nonatomicAssignValue;
@property (atomic, assign)      id      atomicAssignValue;
@property (nonatomic, retain)   id      retainedObject;
@property (nonatomic, copy)     id      copiedObject;
@property (nonatomic, assign)   id      nonretainedObject;
@property (nonatomic, assign, getter=isMarried)     BOOL    married;
@property (nonatomic, assign, getter=isValid, setter=makeInvalid:)  BOOL    valid;
@property (nonatomic, assign, readonly) int publicReadonlyValue;

@property (nonatomic, retain) id value;
@property (nonatomic, retain) IDPSyntax *nextValue;

// @property (atomic/nonatomic, readwrite/readonly, retain/assign/copy, setter=setterName, getter=GetterName) ivarType ivar;
//
// generates:
// -(ivarType)ivar,
// -(void)setIvar; // if readwrite

+ (void)syntaxTest;

+ (id)syntax;

- (void)foo;


@end
