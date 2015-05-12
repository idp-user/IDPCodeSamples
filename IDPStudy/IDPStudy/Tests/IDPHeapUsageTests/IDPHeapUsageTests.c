//
//  IDPHeapUsageTests.c
//  IDPStudy
//
//  Created by Alexander Kradenkov on 5/12/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#include <stdlib.h>
#include <assert.h>

#include "IDPHeapUsageTests.h"

#pragma mark -
#pragma mark Private

static
void IDPMultipleAllocationsTest(void);

#pragma mark -
#pragma mark Public

void IDPPerformHeapUsageTests() {
    IDPMultipleAllocationsTest();
}


#pragma mark -
#pragma mark Private Impl

void IDPMultipleAllocationsTest(void) {
    const int count = 100000;
    
    void *allocatedDataPointers[count];
    size_t objectSize = 10000;
    
    // allocations
    for (uint64_t index = 0; index < count; index++) {
        void *currentObject = malloc(objectSize);

        assert(NULL != currentObject); // is malloc return data field pointer?
        
        allocatedDataPointers[index] = currentObject;
        
        printf("%p\n", allocatedDataPointers[index]);
    }
    
    // deallocations
    for (uint64_t index = 0; index < count; index++) {
        free(allocatedDataPointers[index]);
    }
}
