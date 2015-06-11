//
//  IDPLinkedList.c
//  IDPStudy
//
//  Created by Alexander Kradenkov on 5/27/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#include <assert.h>
#include <strings.h>

#include "IDPLinkedListPrivate.h"
#include "IDPLinkedListEnumeratorPrivate.h"
#include "IDPLinkedListNode.h"

#include "IDPObjectMacros.h"

#pragma mark -
#pragma mark Private Declarations

static
void IDPLinkedListSetCount(IDPLinkedList *list, uint64_t count);


static
void IDPLinkedListMutate(IDPLinkedList *list);



#pragma mark -
#pragma mark Public Implementations

void __IDPLinkedListDeallocate(void *object) {
    IDPLinkedListSetHead(object, NULL);
    
    __IDPObjectDeallocate(object);
}

IDPLinkedListEnumerator *IDPLinkedListEnumeratorFromList(IDPLinkedList *list) {
    return IDPLinkedListEnumeratorCreateWithList(list);
}

IDPObject *IDPLinkedListGetFirstObject(IDPLinkedList *list) {
    IDPLinkedListNode *node =  IDPLinkedListGetHead(list);
    
    return IDPLinkedListNodeGetObject(node);
}

void IDPLinkedListRemoveFirstObject(IDPLinkedList *list) {
    if (NULL != list && false == IDPLinkedListIsEmpty(list)) {
        IDPLinkedListNode *node =  IDPLinkedListGetHead(list);
        IDPLinkedListSetHead(list, IDPLinkedListNodeGetNextNode(node));
        IDPLinkedListSetCount(list, IDPLinkedListGetCount(list) - 1);
    }
}

IDPObject *IDPLinkedListGetObjectBeforeObject(IDPLinkedList *list, IDPObject *object) {
    if (NULL != list && false == IDPLinkedListIsEmpty(list)) {
        // enumerate until object and remember previous on each iteration
        IDPLinkedListNode *currentNode = IDPLinkedListGetHead(list);
        IDPObject *previousObject = NULL;
        
        do {
            IDPObject *currentObject = IDPLinkedListNodeGetObject(currentNode);
            if (object == currentObject) {
                
                return previousObject;
            }
            
            previousObject = currentObject;
        } while (NULL != (currentNode = IDPLinkedListNodeGetNextNode(currentNode)));

    }
    
    return NULL;
}

bool IDPLinkedListIsEmpty(IDPLinkedList *list) {
    return (NULL != list) && (0 == list->_count);
}

void IDPLinkedListAddObject(IDPLinkedList *list, void *object) {
    if (NULL != list) {
        IDPLinkedListNode *node = IDPLinkedListNodeCreateWithObject(object);
        IDPLinkedListNodeSetNextNode(node, IDPLinkedListGetHead(list));
        
        IDPLinkedListSetHead(list, node);
        IDPLinkedListSetCount(list, IDPLinkedListGetCount(list) + 1);
        
        IDPObjectRelease(node);
    }
}

void IDPLinkedListRemoveObject(IDPLinkedList *list, void *object) {
    IDPLinkedListNodeContext context;
    
    memset(&context, 0, sizeof(context));
    context.object = object;
    
    IDPLinkedListNode *node;
    while (NULL != (node = IDPLinkedListFindNodeWithContext(list,
                                                            IDPLinkedListNodeContainsObject,
                                                            &context)))
    {
        if (NULL != node) {
            IDPLinkedListNodeSetNextNode(context.previousNode, IDPLinkedListNodeGetNextNode(context.node));
            IDPLinkedListSetCount(list, IDPLinkedListGetCount(list) - 1);
        }
    }
}

void IDPLinkedListRemoveAllObjects(IDPLinkedList *list) {
    if (NULL != list) {
        IDPLinkedListSetCount(list, 0);
    }
}

bool IDPLinkedListContainsObject(IDPLinkedList *list, void *object) {
    bool result = false;
    if (NULL != list) {
        IDPLinkedListNodeContext context;
        
        memset(&context, 0, sizeof(context)); // context = {NULL, NULL, NULL};

        context.object = object;
        
        result = NULL != IDPLinkedListFindNodeWithContext(list, IDPLinkedListNodeContainsObject, &context);
    }

    return result;
}

uint64_t IDPLinkedListGetCount(IDPLinkedList *list) {
    return NULL != list ? list->_count : 0;
}

#pragma mark -
#pragma mark Private Implementations

void IDPLinkedListSetCount(IDPLinkedList *list, uint64_t count) {
    if (NULL != list) {
        if (0 == count) {
            IDPLinkedListSetHead(list, NULL);
        }
        
        list->_count = count;
        IDPLinkedListMutate(list);
    }
}

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

void IDPLinkedListSetMutationsCount(IDPLinkedList *list, uint64_t count) {
    IDPAssignSetter(list, _mutationsCount, count);
}

uint64_t IDPLinkedListGetMutationsCount(IDPLinkedList *list) {
    return NULL != list ? list->_mutationsCount : 0;
}

void IDPLinkedListMutate(IDPLinkedList *list) {
    IDPLinkedListSetMutationsCount(list, IDPLinkedListGetMutationsCount(list) + 1);
}

IDPLinkedListNode *IDPLinkedListFindNodeWithContext(IDPLinkedList *list,
                                                   IDPLinkedListNodeComparisonFunction comparator,
                                                   IDPLinkedListNodeContext *context)
{
    IDPLinkedListNode *result = NULL;
    if (NULL != list) {
        IDPLinkedListEnumerator *enumerator = IDPLinkedListEnumeratorCreateWithList(list);
        
        while (true == IDPLinkedListEnumeratorIsValid(enumerator)
               && (NULL != IDPLinkedListEnumeratorGetNextObject(enumerator)))
        {
            IDPLinkedListNode *node = IDPLinkedListEnumeratorGetNode(enumerator);
            
            context->node = node;
            
            if (true == IDPLinkedListNodeContainsObject(node, *context)) {
                result = node;
                break;
            }
            
            context->previousNode = node;
        }
        
        IDPObjectRelease(enumerator);
    }
    
    return result;
}

bool IDPLinkedListNodeContainsObject(IDPLinkedListNode *node, IDPLinkedListNodeContext context) {
    return (NULL != node) && context.object == IDPLinkedListNodeGetObject(node);
}
