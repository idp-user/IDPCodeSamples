//
//  IDPLinkedListNode.h
//  IDPStudy
//
//  Created by Alexander Kradenkov on 5/18/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#ifndef __IDPStudy__IDPLinkedListNode__
#define __IDPStudy__IDPLinkedListNode__

#include <stdio.h>

#include "IDPObject.h"

typedef struct IDPLinkedListNode IDPLinkedListNode;

struct IDPLinkedListNode {
    IDPObject _super;
    
    IDPLinkedListNode *_nextNode;
    void *_object; // must be of IDPObject
};

extern
IDPLinkedListNode *IDPLinkedListNodeCreateWithObject(void *object);

extern
IDPLinkedListNode *IDPLinkedListNodeGetNextNode(IDPLinkedListNode *node);

extern
void IDPLinkedListNodeSetNextNode(IDPLinkedListNode *node, IDPLinkedListNode *nextNode);

extern
IDPObject *IDPLinkedListNodeGetObject(IDPLinkedListNode *node);

extern
void IDPLinkedListNodeSetObject(IDPLinkedListNode *node, void *object);

extern
void __IDPLinkedListNodeDeallocate(void *object);

#endif /* defined(__IDPStudy__IDPLinkedListNode__) */
