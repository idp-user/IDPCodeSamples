//
//  IDPAutoreleasingStack.h
//  IDPStudy
//
//  Created by Alexander Kradenkov on 6/16/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#ifndef __IDPStudy__IDPAutoreleasingStack__
#define __IDPStudy__IDPAutoreleasingStack__

#include <stdbool.h>

#include "IDPObject.h"

typedef struct IDPAutoreleasingStack IDPAutoreleasingStack;

struct IDPAutoreleasingStack {
    IDPObject _super;
    
    void **_data;
    void *_head;
    size_t _size;
};

typedef enum {
    kIDPAutoreleasingStackPoppedNULL,
    kIDPAutoreleasingStackPoppedObject
} IDPAutoreleasingStackPopType;

extern
IDPAutoreleasingStack *IDPAutoreleasingStackCreateWithSize(size_t size);

extern
bool IDPAutoreleasingStackIsEmpty(IDPAutoreleasingStack *stack);

extern
bool IDPAutoreleasingStackIsFull(IDPAutoreleasingStack *stack);

extern
void IDPAutoreleasingStackPushObject(IDPAutoreleasingStack *stack, void *object);

extern
IDPAutoreleasingStackPopType IDPAutoreleasingStackPopObject(IDPAutoreleasingStack *stack);

extern
IDPAutoreleasingStackPopType IDPAutoreleasingStackPopObjectsUntilNULL(IDPAutoreleasingStack *stack);

#endif /* defined(__IDPStudy__IDPAutoreleasingStack__) */
