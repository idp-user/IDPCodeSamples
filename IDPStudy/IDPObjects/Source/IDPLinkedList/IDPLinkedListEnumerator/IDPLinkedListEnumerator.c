//
//  IDPLinkedListEnumerator.c
//  IDPStudy
//
//  Created by Alexander Kradenkov on 6/3/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#include <assert.h>

#include "IDPLinkedListEnumeratorPrivate.h"
#include "IDPLinkedListNode.h"
#include "IDPLinkedListPrivate.h"

#include "IDPObjectMacros.h"


#pragma mark -
#pragma mark Private Declarations

static
void IDPLinkedListEnumeratorSetValid(IDPLinkedListEnumerator *enumerator, bool valid);

static
void IDPLinkedListEnumeratorSetList(IDPLinkedListEnumerator *enumerator, IDPLinkedList *list);

static
IDPLinkedList *IDPLinkedListEnumeratorGetList(IDPLinkedListEnumerator *enumerator);

static
void IDPLinkedListEnumeratorSetNode(IDPLinkedListEnumerator *enumerator, IDPLinkedListNode *node);

static
IDPLinkedListNode *IDPLinkedListEnumeratorGetNode(IDPLinkedListEnumerator *enumerator);

static
void IDPLinkedListEnumeratorSetMutationsCount(IDPLinkedListEnumerator *enumerator, uint64_t mutationsCount);

static
uint64_t IDPLinkedListEnumeratorGetMutationsCount(IDPLinkedListEnumerator *enumerator);

static
bool IDPLinkedListEnumeratorMutationsValidate(IDPLinkedListEnumerator *enumerator);


#pragma mark -
#pragma mark Piblic Implementations

void __IDPLinkedListEnumeratorDeallocate(void *object) {
    IDPLinkedListEnumeratorSetNode(object, NULL);
    IDPLinkedListEnumeratorSetList(object, NULL);
    
    __IDPObjectDeallocate(object);
}

IDPLinkedListEnumerator *IDPLinkedListEnumeratorCreateWithList(IDPLinkedList *list) {
    if (NULL == list || NULL == IDPLinkedListGetHead(list)) {
        return NULL;
    }
    
    IDPLinkedListEnumerator *enumerator = IDPObjectCreateOfType(IDPLinkedListEnumerator);
    IDPLinkedListEnumeratorSetList(enumerator, list);
    IDPLinkedListEnumeratorSetMutationsCount(enumerator, IDPLinkedListGetMutationsCount(list));
    IDPLinkedListEnumeratorSetValid(enumerator, true);
    
    return enumerator;
}

void *IDPLinkedListEnumeratorGetNextObject(IDPLinkedListEnumerator *enumerator) {
    if (NULL != enumerator) {
//      validations
        if (true == IDPLinkedListEnumeratorMutationsValidate(enumerator)) {
            // get current node
            IDPLinkedListNode *node = IDPLinkedListEnumeratorGetNode(enumerator);
            IDPLinkedList *list = IDPLinkedListEnumeratorGetList(enumerator);
            // find next node or get list head while first enumeration
            node = (NULL != node) ? IDPLinkedListNodeGetNextNode(node) : IDPLinkedListGetHead(list);
            // set current node
            IDPLinkedListEnumeratorSetNode(enumerator, node);

            if (NULL == node) {
                IDPLinkedListEnumeratorSetValid(enumerator, false);
            }
            
            return IDPLinkedListNodeGetObject(node);
        }
    }
    
    return NULL;
}

void IDPLinkedListEnumeratorSetValid(IDPLinkedListEnumerator *enumerator, bool valid) {
    IDPAssignSetter(enumerator, _valid, valid);
}

bool IDPLinkedListEnumeratorIsValid(IDPLinkedListEnumerator *enumerator) {
    return NULL != enumerator && enumerator->_valid;
}

#pragma mark -
#pragma mark Private Implementations

void IDPLinkedListEnumeratorSetList(IDPLinkedListEnumerator *enumerator, IDPLinkedList *list) {
    IDPRetainSetter(enumerator, _list, list);
}

IDPLinkedList *IDPLinkedListEnumeratorGetList(IDPLinkedListEnumerator *enumerator) {
    return NULL != enumerator ? enumerator->_list : NULL;
}

void IDPLinkedListEnumeratorSetNode(IDPLinkedListEnumerator *enumerator, IDPLinkedListNode *node) {
    IDPRetainSetter(enumerator, _node, node);
}

IDPLinkedListNode *IDPLinkedListEnumeratorGetNode(IDPLinkedListEnumerator *enumerator) {
    return NULL != enumerator ? enumerator->_node : NULL;
}

void IDPLinkedListEnumeratorSetMutationsCount(IDPLinkedListEnumerator *enumerator, uint64_t mutationsCount) {
    IDPAssignSetter(enumerator, _mutationsCount, mutationsCount);
}

uint64_t IDPLinkedListEnumeratorGetMutationsCount(IDPLinkedListEnumerator *enumerator) {
    return NULL != enumerator ? enumerator->_mutationsCount : 0;
}


bool IDPLinkedListEnumeratorMutationsValidate(IDPLinkedListEnumerator *enumerator) {
    if (true == IDPLinkedListEnumeratorIsValid(enumerator)) {
        IDPLinkedList *list = IDPLinkedListEnumeratorGetList(enumerator);
        assert(IDPLinkedListGetMutationsCount(list) == IDPLinkedListEnumeratorGetMutationsCount(enumerator));
        
        return true;
    }
    
    return false;
}
