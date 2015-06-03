//
//  IDPLinkedListEnumerator.c
//  IDPStudy
//
//  Created by Alexander Kradenkov on 6/3/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#include "IDPLinkedListEnumeratorPrivate.h"
#include "IDPLinkedListNode.h"
#include "IDPLinkedListPrivate.h"

#include "IDPObjectMacros.h"

#pragma mark -
#pragma mark Private Declarations

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

#pragma mark -
#pragma mark Piblic Implementations

void __IDPLinkedListEnumeratorDeallocate(void *object) {
    IDPLinkedListEnumeratorSetNode(object, NULL);
    IDPLinkedListEnumeratorSetList(object, NULL);
    
    __IDPObjectDeallocate(object);
}

IDPLinkedListEnumerator *IDPLinkedListEnumeratorCreateWithList(IDPLinkedList *list) {
    if (NULL == list) {
        return NULL;
    }
    
    IDPLinkedListEnumerator *enumerator = IDPObjectCreateOfType(IDPLinkedListEnumerator);
    IDPLinkedListEnumeratorSetList(enumerator, list);
    IDPLinkedListEnumeratorSetMutationsCount(enumerator, IDPLinkedListGetMutationsCount(list));
    
    return enumerator;
}

void *IDPLinkedListEnumeratorGetNextObject(IDPLinkedListEnumerator *enumerator) {
    if (NULL != enumerator) {
//        <#statements#>
    }
    
    return NULL;
}

bool IDPLinkedListEnumeratorIsValid(IDPLinkedListEnumerator *enumerator) {
    return NULL != enumerator && enumerator->_isValid;
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
