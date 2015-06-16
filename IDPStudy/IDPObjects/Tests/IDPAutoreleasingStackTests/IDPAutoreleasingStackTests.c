//
//  IDPAutoreleasingStackTests.c
//  IDPStudy
//
//  Created by Alexander Kradenkov on 6/16/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#include <assert.h>

#include "IDPAutoreleasingStackTests.h"

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
    //      stack must be empty
    //      stack must not be full
    //  after object was created
    //      after object pushed to stack
    //          object referenceCount must not change
    //          stack must not be empty
    //          stack must not be full
    //      after one object was popped
    //          pop type must be 'PoppedObject'
    //          object reference count must be decremented
    //          stack must be empty
    //          stack must not be full
}

void  IDPAutoreleasingStackOneNULLPushTest(void) {
    //  after stack was created for 64 objects
    //      stack must be empty
    //      stack must not be full
    //  after NULL pushed to stack
    //      stack must not be empty
    //      stack must not be full
    //  after one object was popped
    //      pop type must be 'PoppedNULL'
    //      stack must be empty
    //      stack must not be full
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



