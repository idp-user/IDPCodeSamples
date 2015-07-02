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

typedef void (*IDPObjectProcedurePointer)(void *);

typedef struct {
    uint64_t _referenceCount;
    IDPObjectProcedurePointer _releaseFunction;
    IDPObjectProcedurePointer _deallocator;
} IDPObject;

extern
void *__IDPObjectCreate(size_t objectSize, IDPObjectProcedurePointer deallocateCallback);

extern
void *__IDPSingletonObjectCreate(void **singletonPointer, size_t objectSize, IDPObjectProcedurePointer deallocateCallback);

#define IDPObjectCreateOfType(type) \
__IDPObjectCreate(sizeof(type), (IDPObjectProcedurePointer)__##type##Deallocate)

#define IDPSingletonObjectCreateOfType(singletonPointer, type) \
__IDPSingletonObjectCreate((void **)singletonPointer, sizeof(type), (IDPObjectProcedurePointer)__##type##Deallocate)

extern
void *IDPObjectRetain(void *object);

extern
void IDPObjectRelease(void *object);

extern
uint64_t IDPObjectGetReferenceCount(void *object);

extern
void __IDPObjectDeallocate(void *object);

#endif /* defined(__IDPStudy__IDPObject__) */
