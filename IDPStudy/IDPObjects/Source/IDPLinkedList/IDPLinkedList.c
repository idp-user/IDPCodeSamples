//
//  IDPLinkedList.c
//  IDPStudy
//
//  Created by Alexander Kradenkov on 5/27/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#include "IDPLinkedList.h"

#include "IDPLinkedListNode.h"

#pragma mark -
#pragma mark Private Declarations

static
void IDPLinkedListSetHead(IDPLinkedList *list, IDPLinkedListNode *head);

static
IDPLinkedListNode *IDPLinkedListGetHead(IDPLinkedList *list);

#pragma mark -
#pragma mark Public Implementations

void __IDPLinkedListDeallocate(void *object) {
    IDPLinkedListSetHead(object, NULL);
    
    __IDPObjectDeallocate(object);
}

IDPObject *IDPLinkedListGetFirstObject(IDPLinkedList *list) {
    IDPLinkedListNode *node =  IDPLinkedListGetHead(list);
    
    return IDPLinkedListNodeGetObject(node);
}

void IDPLinkedListRemoveFirstObject(IDPLinkedList *list) {
    IDPLinkedListNode *node =  IDPLinkedListGetHead(list);
    
    IDPLinkedListSetHead(list, IDPLinkedListNodeGetNextNode(node));
}

IDPObject *IDPLinkedListGetObjectBeforeObject(IDPLinkedList *list, IDPObject *object) {
    IDPObject *result = NULL;
    if (NULL != list) {
        // enumerate until object and remember previous on each iteration

    }
    
    return result;
}

bool IDPLinkedListIsEmpty(IDPLinkedList *list) {
    return (NULL != list) && (0 == list->_count);
}

void IDPLinkedListAddObject(IDPLinkedList *list, void *object) {
    if (NULL != list) {
        IDPLinkedListNode *node = IDPLinkedListNodeCreateWithObject(object);
        IDPLinkedListNodeSetNextNode(node, IDPLinkedListGetHead(list));
        
        IDPLinkedListSetHead(list, node);
        
        list->_count++;
        
        IDPObjectRelease(node);
    }
}

void IDPLinkedListRemoveObject(IDPLinkedList *list, void *object) {
    // find node with object
}

void IDPLinkedListRemoveAllObjects(IDPLinkedList *list) {
    if (NULL != list) {
        IDPLinkedListSetHead(list, NULL);
        list->_count = 0;
    }
}

bool IDPLinkedListContainsObject(IDPLinkedList *list, void *object) {
    bool result = false;
    if (NULL != list) {
        // enumerate all nodes to find node with object
    }
    
    return result;
}

uint64_t IDPLinkedListGetCount(IDPLinkedList *list) {
    return NULL != list ? list->_count : 0;
}

#pragma mark -
#pragma mark Private Implementations

void IDPLinkedListSetHead(IDPLinkedList *list, IDPLinkedListNode *head) {
    if (NULL != list && list->_head != head) {
        IDPObjectRetain(head);
        IDPObjectRelease(list->_head);
        
        list->_head = head;
    }
}

IDPLinkedListNode *IDPLinkedListGetHead(IDPLinkedList *list) {
    return NULL != list ? list->_head : NULL;
}
