//
//  IDPLinkedListEnumerator.h
//  IDPStudy
//
//  Created by Alexander Kradenkov on 6/3/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#ifndef __IDPStudy__IDPLinkedListEnumerator__
#define __IDPStudy__IDPLinkedListEnumerator__

#include <stdbool.h>

#include "IDPObject.h"

typedef struct IDPLinkedListEnumerator IDPLinkedListEnumerator;
typedef struct IDPLinkedListNode IDPLinkedListNode;
typedef struct IDPLinkedList IDPLinkedList;

struct IDPLinkedListEnumerator{
    IDPObject _super;
    
    void *_list;
    IDPLinkedListNode *_node;
    uint64_t _mutationsCount;
    
    bool _isValid;
};


extern
IDPLinkedListEnumerator *IDPLinkedListEnumeratorCreateWithList(IDPLinkedList *list);

extern
void *IDPLinkedListEnumeratorGetNextObject(IDPLinkedListEnumerator *enumerator);

extern
bool IDPLinkedListEnumeratorIsValid(IDPLinkedListEnumerator *enumerator);

extern
void __IDPLinkedListEnumeratorDeallocate(void *object);


#endif /* defined(__IDPStudy__IDPLinkedListEnumerator__) */
