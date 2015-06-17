//
//  IDPAutoreleasingStackTests.c
//  IDPStudy
//
//  Created by Alexander Kradenkov on 6/16/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#include <assert.h>

#include "IDPAutoreleasingStackTests.h"
#include "IDPAutoreleasingStack.h"

#include "IDPTestMacros.h"

#pragma mark -
#pragma mark Private Declarations

static
void IDPAutoreleasingStackOneObjectPushTest(void);

static
void  IDPAutoreleasingStackOneNULLPushTest(void);

static
void  IDPAutoreleasingStackIsFullTest(void);

#pragma mark -
#pragma mark Public Implementations

void IDPAutoreleasingStackPerformTests(void) {
    performTest(IDPAutoreleasingStackOneObjectPushTest);
    performTest(IDPAutoreleasingStackOneNULLPushTest);
    performTest(IDPAutoreleasingStackIsFullTest);
}

#pragma mark -
#pragma mark Private Impl

void IDPAutoreleasingStackOneObjectPushTest(void) {
    //  after stack was created with size 512 (64 pointers in it)
    IDPAutoreleasingStack *stack = IDPAutoreleasingStackCreateWithSize(64 * sizeof(IDPObject*));
    //      stack must be empty
    assert(true == IDPAutoreleasingStackIsEmpty(stack));
    
    //      stack must not be full
    assert(false == IDPAutoreleasingStackIsFull(stack));
    
    //  after object was created
    IDPObject *object = IDPObjectRetain(IDPObjectCreateOfType(IDPObject));
    assert(2 == IDPObjectGetReferenceCount(object));
    
    //      after object pushed to stack
    IDPAutoreleasingStackPushObject(stack, object);
    
    //          object referenceCount must not change
    assert(2 == IDPObjectGetReferenceCount(object));
    
    //          stack must not be empty
    assert(false == IDPAutoreleasingStackIsEmpty(stack));
    
    //          stack must not be full
    assert(false == IDPAutoreleasingStackIsFull(stack));
    
    //      after one object was popped
    IDPAutoreleasingStackPopType type = IDPAutoreleasingStackPopObject(stack);
    
    //          pop type must be 'PoppedObject'
    assert(kIDPAutoreleasingStackPoppedObject == type);
    
    //          object reference count must be decremented
    assert(1 == IDPObjectGetReferenceCount(object));
   
    //          stack must be empty
    assert(true == IDPAutoreleasingStackIsEmpty(stack));
    
    //          stack must not be full
    assert(false == IDPAutoreleasingStackIsFull(stack));

    IDPObjectRelease(object);
    IDPObjectRelease(stack);
}

void  IDPAutoreleasingStackOneNULLPushTest(void) {
    //  after stack was created with size 512 (64 pointers in it)
    IDPAutoreleasingStack *stack = IDPAutoreleasingStackCreateWithSize(64 * sizeof(IDPObject*));
    //      stack must be empty
    assert(true == IDPAutoreleasingStackIsEmpty(stack));
    
    //      stack must not be full
    assert(false == IDPAutoreleasingStackIsFull(stack));
    //  after NULL pushed to stack
    IDPAutoreleasingStackPushObject(stack, NULL);
    
    //          stack must not be empty
    assert(false == IDPAutoreleasingStackIsEmpty(stack));
    
    //          stack must not be full
    assert(false == IDPAutoreleasingStackIsFull(stack));
    
    //  after one object was popped
    IDPAutoreleasingStackPopType type = IDPAutoreleasingStackPopObject(stack);
    
    //      pop type must be 'PoppedNULL'
    assert(kIDPAutoreleasingStackPoppedNULL == type);
    
    //          stack must be empty
    assert(true == IDPAutoreleasingStackIsEmpty(stack));
    
    //          stack must not be full
    assert(false == IDPAutoreleasingStackIsFull(stack));
}

void  IDPAutoreleasingStackIsFullTest(void) {
    //  after stack was created for 64 objects
    //      stack must be empty
    //      stack must not be full
    //  after object was created
    //      after object pushed to stack 64 times
    //          object referenceCount must not change
    //          stack must not be empty
    //          stack must be full
    //      after one object was popped
    //          pop type must be 'PoppedObject'
    //          object reference count must be decremented
    //          stack must not be empty
    //          stack must not be full
    //      after all object wass popped
    //          pop type must be 'PoppedObject'
    //          object reference count must be decremented 63 times
    //          stack must be empty
    //          stack must not be full
}



