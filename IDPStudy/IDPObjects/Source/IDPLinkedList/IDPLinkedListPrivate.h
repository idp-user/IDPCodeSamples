//
//  IDPLinkedListPrivate.h
//  IDPStudy
//
//  Created by Alexander Kradenkov on 6/3/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#ifndef IDPStudy_IDPLinkedListPrivate_h
#define IDPStudy_IDPLinkedListPrivate_h

typedef struct IDPLinkedList IDPLinkedList;

extern
void IDPLinkedListSetMutationsCount(IDPLinkedList *list, uint64_t count);

extern
uint64_t IDPLinkedListGetMutationsCount(IDPLinkedList *list);

#endif
