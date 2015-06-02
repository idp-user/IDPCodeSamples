//
//  IDPLinkedListTests.c
//  IDPStudy
//
//  Created by Alexander Kradenkov on 5/27/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#include <assert.h>

#include "IDPLinkedListTests.h"

#include "IDPLinkedList.h"
#include "IDPTestMacros.h"

#pragma mark -
#pragma mark Private Declarations

static
void IDPLinkedListOneObjectTest(void);

#pragma mark -
#pragma mark Public Implementations

void IDPLinkedListBehaviorTest(void) {
    performTest(IDPLinkedListOneObjectTest);
}

#pragma mark -
#pragma mark Private Implementations

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
    
    IDPObjectRelease(object);
    IDPObjectRelease(list);
}
