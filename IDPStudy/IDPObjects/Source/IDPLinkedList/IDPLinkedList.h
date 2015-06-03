//
//  IDPLinkedList.h
//  IDPStudy
//
//  Created by Alexander Kradenkov on 5/27/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#ifndef __IDPStudy__IDPLinkedList__
#define __IDPStudy__IDPLinkedList__

#include <stdbool.h>

#include "IDPObject.h"

typedef struct IDPLinkedListNode IDPLinkedListNode;
typedef struct IDPLinkedListEnumerator IDPLinkedListEnumerator;

typedef struct IDPLinkedList IDPLinkedList;

struct IDPLinkedList {
    IDPObject _super;
    
    IDPLinkedListNode *_head;    
    uint64_t _count;
    uint64_t _mutationsCount;
};


extern
IDPLinkedListEnumerator *IDPLinkedListEnumeratorFromList(IDPLinkedList *list);

extern
IDPObject *IDPLinkedListGetFirstObject(IDPLinkedList *list);

extern
void IDPLinkedListRemoveFirstObject(IDPLinkedList *list);

extern
IDPObject *IDPLinkedListGetObjectBeforeObject(IDPLinkedList *list, IDPObject *object);

extern
bool IDPLinkedListIsEmpty(IDPLinkedList *list);

extern
void IDPLinkedListAddObject(IDPLinkedList *list, void *object);

extern
void IDPLinkedListRemoveObject(IDPLinkedList *list, void *object);

extern
void IDPLinkedListRemoveAllObjects(IDPLinkedList *list);

extern
bool IDPLinkedListContainsObject(IDPLinkedList *list, void *object);

extern
uint64_t IDPLinkedListGetCount(IDPLinkedList *list);

extern
void __IDPLinkedListDeallocate(void *object);


#endif /* defined(__IDPStudy__IDPLinkedList__) */
