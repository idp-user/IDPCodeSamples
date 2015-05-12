//
//  IDPObject.h
//  IDPStudy
//
//  Created by Alexander Kradenkov on 5/12/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#ifndef __IDPStudy__IDPObject__
#define __IDPStudy__IDPObject__

#include <stdlib.h>

typedef void (*IDPObjectDeallocatorCallback)(void *);

typedef struct {
    uint64_t _referenceCount;
    IDPObjectDeallocatorCallback _deallocator;
} IDPObject;

extern
void *__IDPObjectCreate(size_t objectSize, IDPObjectDeallocatorCallback deallocateCallback);

#define IDPObjectCreateOfType(type) \
__IDPObjectCreate(sizeof(type), (IDPObjectDeallocatorCallback)__##type##Deallocate)

extern
void *IDPObjectRetain(void *object);

extern
void IDPObjectRelease(void *object);

extern
uint64_t IDPObjectGetReferenceCount(void *object);

extern
void __IDPObjectDeallocate(void *object);

#endif /* defined(__IDPStudy__IDPObject__) */
