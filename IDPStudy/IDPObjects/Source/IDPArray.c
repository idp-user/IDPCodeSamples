//
//  IDPArray.c
//  IDPStudy
//
//  Created by Alexander Kradenkov on 5/21/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#include <assert.h>
#include <string.h>

#include "IDPArray.h"

#pragma mark -
#pragma mark Private Declarations

static
void IDPArraySetCapacity(IDPArray *array, uint64_t capacity);

static
bool IDPArrayShouldResize(IDPArray *array);

static
void IDPArrayResize(IDPArray *array, uint64_t requiredCapacity);

static
void IDPArraySetCount(IDPArray *array, uint64_t count);

static
void IDPArraySetObjectAtIndex(IDPArray *array, void *object, uint64_t index);

#pragma mark -
#pragma mark Public Methods

void *IDPArrayCreateWithCapacity(uint64_t capacity) {
    IDPArray *result = IDPObjectCreateOfType(IDPArray);
    
    IDPArraySetCapacity(result, capacity);
    
    return result;
}

void __IDPArrayDeallocate(void *object) {
    IDPArray *array = object;
    
    IDPArrayRemoveAllObjects(array);
//    IDPArraySetCapacity(object, 0);
    if (NULL != array->_data) {
        free(array->_data);
        array->_data = NULL;
    }
    
    __IDPObjectDeallocate(object);
}

/// returns index of added object. Otherwise kIDPNotFound
void IDPArrayAddObject(IDPArray *array, void *object) {
    if (NULL != array && NULL != object) {
        uint64_t count = IDPArrayGetCount(array);

//  place this code in IDPArraySetCount()
//        if (true == IDPArrayShouldResize(array)) {
//            IDPArrayResize(array, count + 1);
//        }
        
        IDPArraySetCount(array, count + 1);
        IDPArraySetObjectAtIndex(array, object, count);
    }
}

uint64_t IDPArrayGetCount(IDPArray *array) {
    return NULL != array ? array->_count : 0;
}

bool IDPArrayContainsObject(IDPArray *array, void *object) {
    return (NULL != array) && (kIDPNotFound != IDPArrayGetIndexOfObject(array, object));
}

uint64_t IDPArrayGetIndexOfObject(IDPArray *array, void *object) {
    if (NULL == array) {
        return 0;
    }
    
    if (NULL == object) {
        return kIDPNotFound;
    }
    
    uint64_t result = kIDPNotFound;
    uint64_t count = IDPArrayGetCount(array);
    for (uint64_t index = 0; index < count; index++) {
        if (IDPArrayGetObjectAtIndex(array, index) == object) {
            result = index;
            break;
        }
    }
    
    return result;
}

void *IDPArrayGetObjectAtIndex(IDPArray *array, uint64_t index) {
    void *result = NULL;
    if (NULL != array) {

        assert(IDPArrayGetCount(array) > index);
        
        result = array->_data[index];
    }
    
    return result;
}


void IDPArrayRemoveObjectAtIndex(IDPArray *array, uint64_t index) {
    if (NULL != array) {
        IDPArraySetObjectAtIndex(array, NULL, index);
        uint64_t count = IDPArrayGetCount(array);
        
        void **data = array->_data;
        if (index < (count - 1)) {
            uint64_t elementsCount = count - (index + 1);
            
            memmove(&data[index], &data[index + 1], elementsCount * sizeof(*data));
        }
        data[count - 1] = NULL;
        
        IDPArraySetCount(array, count - 1);
    }
    
}

void IDPArrayRemoveAllObjects(IDPArray *array) {
    if (NULL != array) {
        uint64_t count = IDPArrayGetCount(array);
        for (uint64_t index = 0; index < count; index++) {
            IDPArraySetObjectAtIndex(array, NULL, index);
        }
        
        IDPArraySetCapacity(array, 0);
    }
}

#pragma mark -
#pragma mark Private Implementations

void IDPArraySetCapacity(IDPArray *array, uint64_t capacity) {
    
}

bool IDPArrayShouldResize(IDPArray *array) {
    return false;
}

void IDPArrayResize(IDPArray *array, uint64_t requiredCapacity) {
    
}

void IDPArraySetCount(IDPArray *array, uint64_t count) {
    if (NULL != array) {
        array->_count = count;
    }
}

void IDPArraySetObjectAtIndex(IDPArray *array, void *object, uint64_t index) {
    
}
