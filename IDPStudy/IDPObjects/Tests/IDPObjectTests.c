//
//  IDPObjectTests.c
//  IDPStudy
//
//  Created by Alexander Kradenkov on 5/12/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#include <assert.h>

#include "IDPObjectTests.h"
#include "IDPObject.h"
#include "IDPTestMacros.h"

#pragma mark -
#pragma mark Private Declaration

static
void IDPObjectOneObjectCreationTest();

static
void IDPSingletonObjectTest();

#pragma mark -
#pragma mark Public Implementations

void IDPObjectBehaviorTests(void) {
    performTest(IDPObjectOneObjectCreationTest);
    performTest(IDPSingletonObjectTest);
}

#pragma mark -
#pragma mark Private Implementations

void IDPObjectOneObjectCreationTest() {
//  after IDPObject was created
    IDPObject *object = IDPObjectCreateOfType(IDPObject);
    
//      object should not be NULL
    assert(NULL != object);
    
//      object reference count must be equal to 1
    assert(1 == IDPObjectGetReferenceCount(object));
    
//      after object retaining
    IDPObject *retainedObject = IDPObjectRetain(object);
    
//          retained object must be equal to object
    assert(object == retainedObject);
    
//          object reference count must be equal to 2
    assert(2 == IDPObjectGetReferenceCount(object));
    
//      after releasing the object
    IDPObjectRelease(retainedObject);
    
//          object rerefence count must be equal to 1
    assert(1 == IDPObjectGetReferenceCount(object));
    
    IDPObjectRelease(object);    
}

void IDPSingletonObjectTest() {
    static IDPObject * sharedObject;
    
    // after singleton object was created
    IDPObject *object = IDPSingletonObjectCreateOfType(&sharedObject, IDPObject);
    
    //  it should not be NULL
    assert(NULL != object);
    
    //  it referenceCount must be 1
    assert(1 == IDPObjectGetReferenceCount(object));
    
    //  sharedObject must be equal to object
    assert(sharedObject == object);
    
    //      after singletonObject was released
    IDPObjectRelease(object);
    
    //          referenceCount must not change
    assert(1 == IDPObjectGetReferenceCount(object));
    
    // while singleton created 5 times
    //      it maust be equal to sharedObject
    for (uint8_t iterator = 0; iterator < 5; iterator++) {
        void *object2 = IDPSingletonObjectCreateOfType(&sharedObject, IDPObject);
        assert(sharedObject == object2);
    }
}

