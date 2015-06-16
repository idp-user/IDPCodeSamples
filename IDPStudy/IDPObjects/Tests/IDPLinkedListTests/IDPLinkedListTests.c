//
//  IDPLinkedListTests.c
//  IDPStudy
//
//  Created by Alexander Kradenkov on 5/27/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#include <assert.h>
#include <string.h>

#include "IDPLinkedListTests.h"

#include "IDPLinkedList.h"
#include "IDPLinkedListEnumerator.h"

#include "IDPTestMacros.h"

#pragma mark -
#pragma mark Private Declarations

static
void IDPLinkedListEnumeratorBehaviorTest(void);

static
void IDPLinkedListOneObjectTest(void);

#pragma mark -
#pragma mark Public Implementations

void IDPLinkedListBehaviorTest(void) {
    performTest(IDPLinkedListEnumeratorBehaviorTest);
    performTest(IDPLinkedListOneObjectTest);
}

#pragma mark -
#pragma mark Private Implementations

void IDPLinkedListEnumeratorBehaviorTest(void) {
    IDPObject *originObjects[5];

    memset(originObjects, 0, sizeof(originObjects));
    
    //  after list was created with 5 objects
    IDPLinkedList *list = IDPObjectCreateOfType(IDPLinkedList);
    for (uint index = 0; index < 5; index++) {
        IDPObject *object = IDPObjectCreateOfType(IDPObject);
        
        IDPLinkedListAddObject(list, object);
        // place object in originObject in reverse order
        originObjects[4 - index] = object;
        
        IDPObjectRelease(object);
    }
    
    // list reference count should be 1
    assert(1 == IDPObjectGetReferenceCount(list));
    
    // list count should be 5
    assert(5 == IDPLinkedListGetCount(list));
    
    //  after enumerator was created
    IDPLinkedListEnumerator *enumerator = IDPLinkedListEnumeratorFromList(list);
    //      list reference count should be 2
    assert(2 == IDPObjectGetReferenceCount(list));
    
    //      enumerator reference count should be 1
    assert(1 == IDPObjectGetReferenceCount(enumerator));
    
    //      enumerator iterations count should be 5
    uint64_t iterationsCount = 0;
    IDPObject *object = IDPLinkedListEnumeratorGetNextObject(enumerator);
    while (true == IDPLinkedListEnumeratorIsValid(enumerator)) {
        assert(originObjects[iterationsCount] == object);
        
        iterationsCount++;
        
//        IDPLinkedListAddObject(list, object); // WILL CRASH
        
        object = IDPLinkedListEnumeratorGetNextObject(enumerator);
    }
    
    assert(5 == iterationsCount);
    
    IDPObjectRelease(enumerator);
    IDPObjectRelease(list);
}

void IDPLinkedListOneObjectTest(void) {
    //  after list was created
    IDPLinkedList *list = IDPObjectCreateOfType(IDPLinkedList);
    
    //      list should be empty
    assert(true == IDPLinkedListIsEmpty(list));
    
    //  after object was created
    IDPObject *object = IDPObjectCreateOfType(IDPObject);
    
    //      list must contain object
    assert(false == IDPLinkedListContainsObject(list, object));
    
    //  after object was added to list
    IDPLinkedListAddObject(list, object);
    
    //      object referenceCount must be 2
    assert(2 == IDPObjectGetReferenceCount(object));
    
    //      list must not be empty
    assert(false == IDPLinkedListIsEmpty(list));
    
    //      list must contain object
    assert(true == IDPLinkedListContainsObject(list, object));
    
    //  after object was removed from list
    IDPLinkedListRemoveObject(list, object);
    
    //      list should be empty
    assert(true == IDPLinkedListIsEmpty(list));
    
    //      list must not contain object
    assert(false == IDPLinkedListContainsObject(list, object));
    
    //      object referenceCount must be 1
    assert(1 == IDPObjectGetReferenceCount(object));
    
    // after object was added 2000 times
    for (uint64_t iterator = 0; iterator < 2000; iterator++) {
        IDPLinkedListAddObject(list, object);
    }
    
    //      list must not be empty
    assert(false == IDPLinkedListIsEmpty(list));
    
    //      list must contain object
    assert(true == IDPLinkedListContainsObject(list, object));
    
    //      object referenceCount must be 2001
    assert(2001 == IDPObjectGetReferenceCount(object));
    
    // after object was removed from list
    IDPLinkedListRemoveFirstObject(list);
    
    //      object referenceCount must be 2000
    assert(2000 == IDPObjectGetReferenceCount(object));
    
    // after object was removed from list
    IDPLinkedListRemoveObject(list, object);
    
    
    //      object referenceCount must be 1
    assert(1 == IDPObjectGetReferenceCount(object));
    
    //      list should be empty
    assert(true == IDPLinkedListIsEmpty(list));
    
    //      list must not contain object
    assert(false == IDPLinkedListContainsObject(list, object));
    
    IDPObjectRelease(object);
    IDPObjectRelease(list);
}
