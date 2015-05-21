//
//  IDPArrayTests.c
//  IDPStudy
//
//  Created by Alexander Kradenkov on 5/21/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#include "IDPArrayTests.h"

#include "IDPTestMacros.h"

#pragma mark -
#pragma mark Private Declarations

static
void IDPArrayOneObjectBehaviourTest(void);

static
void IDPArrayMultipleObjectBehaviourTest(void);

static
void IDPArrayBehaviourTest(void);

#pragma mark -
#pragma mark Public

void IDPArrayTestsPerform() {
    performTest(IDPArrayOneObjectBehaviourTest);
    performTest(IDPArrayMultipleObjectBehaviourTest);
}

#pragma mark -
#pragma mark Private Implementations

void IDPArrayOneObjectBehaviourTest(void) {
    //  after array was created
    //      array must not be NULL
    //      array retain count must be equal 1
    //      array objects count muts be equal 0
    // after object was created
    //      object must not be NULL
    //      object reference count must be equal to 1
    //      object index in array must be invalid (object not found)
    // after object was added to array
    //      array count must be equal to 1
    //      array reference count must not change
    //      object index in array must be 0
    //      object reference count must be incremented by 1
    //      array object at index 0 must be equal to added object
    //      array must contain an object
    // after object was removed from array
    //      array count must be equal to 0
    //      array reference count must not change
    //      object index in array must be invalid (object not found)
    //      object reference count must be decremented by 1
    //      array must not contain an object
}

void IDPArrayMultipleObjectBehaviourTest(void) {
    //  after one origin object was added 5 times in array
    //      array count must be equal to 5
    //      objects at indices 0 - 4 must be equal to object
    //  after added another object2 (not equal to origin object)
    //      array count must be equal to 6
    //      objects at indices 0 - 4 must be equal to origin object
    //      added object2 must be at index 5
    // after object at index 3 was removed
    //      array count must be equal to 5
    //      objects at indices 0 - 3 must be equal to origin object
    //      added object2 must be at index 4
    // after removing all object from array
    //      array must be empty
    //      array must no contain origin object ang object2
}

