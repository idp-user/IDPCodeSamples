//
//  IDPLinkedListNode.c
//  IDPStudy
//
//  Created by Alexander Kradenkov on 5/18/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#include <assert.h>

#include "IDPLinkedListNode.h"

#pragma mark -
#pragma mark Public

void __IDPLinkedListNodeDeallocate(void *object) {
    IDPLinkedListNodeSetObject(object, NULL);
//    IDPObjectRelease(((IDPLinkedListNode *)object)->_object);
    
    IDPLinkedListNodeSetNextNode(object, NULL);
//    IDPObjectRelease(((IDPLinkedListNode *)object)->_nextNode);
    
    __IDPObjectDeallocate(object);
}

IDPLinkedListNode *IDPLinkedListNodeCreateWithObject(void *object) {
    IDPLinkedListNode *result = IDPObjectCreateOfType(IDPLinkedListNode);
    IDPLinkedListNodeSetObject(result, object);
    
    return result;
}

IDPLinkedListNode *IDPLinkedListNodeGetNextNode(IDPLinkedListNode *node) {
    return NULL != node ? node->_nextNode : NULL;
}

void IDPLinkedListNodeSetNextNode(IDPLinkedListNode *node, IDPLinkedListNode *nextNode) {
    if (NULL != node && (node->_nextNode != nextNode)) {
        IDPObjectRetain(nextNode);
        IDPObjectRelease(node->_nextNode);
        
        node->_nextNode = nextNode;
    }
}

IDPObject *IDPLinkedListNodeGetObject(IDPLinkedListNode *node) {
    return NULL != node ? node->_object : NULL;
}


void IDPLinkedListNodeSetObject(IDPLinkedListNode *node, void *object) {
    if (NULL != node) {
        
        assert(node != object);
        
        void *previousObject = node->_object;
        if (previousObject != object) {
            IDPObjectRetain(object);
            IDPObjectRelease(previousObject);
            
            node->_object = object;
        }
    }
}
