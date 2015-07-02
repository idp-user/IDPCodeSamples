//
//  IDPObject.c
//  IDPStudy
//
//  Created by Alexander Kradenkov on 5/12/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#include <assert.h>

#include "IDPObject.h"

#pragma mark -
#pragma mark Private Declarations

void __IDPObjectRelease(void *object);

#pragma mark -
#pragma mark Public Impl

void *__IDPObjectCreate(size_t objectSize, IDPObjectProcedurePointer deallocateCallback) {
    assert(0 != objectSize);
    
    IDPObject *object = calloc(1, objectSize);
    
    assert(NULL != object);
    
    object->_releaseFunction = __IDPObjectRelease;
    object->_referenceCount = 1;
    object->_deallocator = deallocateCallback;
    
    return object;
}

void *__IDPSingletonObjectCreate(void **singletonPointer, size_t objectSize, IDPObjectProcedurePointer deallocateCallback) {
    if (NULL != *singletonPointer) {
        return *singletonPointer;
    }
    
    assert(NULL != singletonPointer);
    
    IDPObject *object = (IDPObject *)__IDPObjectCreate(objectSize, deallocateCallback);
    object->_releaseFunction = NULL;
    
    *singletonPointer = object;
    
    return object;
}

void *IDPObjectRetain(void *object) {
    if (NULL != object) {
        ((IDPObject *)object)->_referenceCount++;
    }
    
    return object;
}

void IDPObjectRelease(void *object) {
    if (NULL != object) {
        IDPObjectProcedurePointer releaseMethod = ((IDPObject *)object)->_releaseFunction;
        if (releaseMethod) {
            releaseMethod(object);
        }
    }
}

uint64_t IDPObjectGetReferenceCount(void *object) {
    return object ? ((IDPObject*)object)->_referenceCount : 0;
}

void __IDPObjectDeallocate(void *object) {
    free(object);
}

#pragma mark -
#pragma mark Private Methods

void __IDPObjectRelease(void *object) {
    if (NULL != object) {
        uint64_t count = ((IDPObject *)object)->_referenceCount - 1;
        ((IDPObject *)object)->_referenceCount = count;
        
        if (0 == count) {
            ((IDPObject *)object)->_deallocator(object);
        }
    }
}
