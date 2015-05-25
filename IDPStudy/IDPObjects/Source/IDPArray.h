//
//  IDPArray.h
//  IDPStudy
//
//  Created by Alexander Kradenkov on 5/21/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#ifndef __IDPStudy__IDPArray__
#define __IDPStudy__IDPArray__

#include <stdbool.h>

#include "IDPObject.h"

static const uint64_t kIDPNotFound = UINT64_MAX;

typedef struct {
    IDPObject _super;
    
    void **_data;
    uint64_t _count;
    uint64_t _capacity;
} IDPArray;

extern
void *IDPArrayCreateWithCapacity(uint64_t capacity);

/// returns index of added object. Otherwise kIDPNotFound
extern
void IDPArrayAddObject(IDPArray *array, void *object);

extern
uint64_t IDPArrayGetCount(IDPArray *array);

extern
bool IDPArrayContainsObject(IDPArray *array, void *object);

extern
uint64_t IDPArrayGetIndexOfObject(IDPArray *array, void *object);

extern
void *IDPArrayGetObjectAtIndex(IDPArray *array, uint64_t index);

extern
void IDPArrayRemoveObjectAtIndex(IDPArray *array, uint64_t index);

extern
void IDPArrayRemoveAllObjects(IDPArray *array);

extern
void __IDPArrayDeallocate(void *object);

#endif /* defined(__IDPStudy__IDPArray__) */
