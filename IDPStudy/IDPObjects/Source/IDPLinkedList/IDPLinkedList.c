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
void IDPLinkedListSetCount(IDPLinkedList *list, uint64_t count);

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
    // find node with object
    IDPLinkedListNode *node = IDPLinkedListGetHead(list);
    IDPLinkedListNode *previousNode = NULL;
    
    while (NULL != node) {
        IDPObject *currentObject = IDPLinkedListNodeGetObject(node);
        IDPLinkedListNode *nextNode = IDPLinkedListNodeGetNextNode(node);
        
        if (object == currentObject) {
            if (node == IDPLinkedListGetHead(list)) {
                IDPLinkedListSetHead(list, nextNode);
            } else {
                IDPLinkedListNodeSetNextNode(previousNode, nextNode);
            }            

            IDPLinkedListSetCount(list, IDPLinkedListGetCount(list) - 1);
        }
        
        previousNode = node;
        node = nextNode;
    }
}

void IDPLinkedListRemoveAllObjects(IDPLinkedList *list) {
    if (NULL != list) {
        IDPLinkedListSetCount(list, 0);
//        
//        IDPLinkedListSetHead(list, NULL);
//        list->_count = 0;
    }
}

bool IDPLinkedListContainsObject(IDPLinkedList *list, void *object) {
    bool result = false;
    if (NULL != list) {
        // enumerate all nodes to find node with object
        IDPLinkedListNode *node = IDPLinkedListGetHead(list);
        while (NULL != node) {
            if (object == IDPLinkedListNodeGetObject(node)) {
                result = true;
                
                break;
            }
            
            node = IDPLinkedListNodeGetNextNode(node);
        }
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
