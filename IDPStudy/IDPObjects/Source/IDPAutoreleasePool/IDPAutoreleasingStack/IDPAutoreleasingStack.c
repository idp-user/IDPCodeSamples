//
//  IDPAutoreleasingStack.c
//  IDPStudy
//
//  Created by Alexander Kradenkov on 6/16/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#include <assert.h>

#include "IDPAutoreleasingStack.h"

#include "IDPObjectMacros.h"

#pragma mark -
#pragma mark Private Declarations

static
void **IDPAutoreleasingStackGetData(IDPAutoreleasingStack *stack);

static
void *IDPAutoreleasingStackGetHead(IDPAutoreleasingStack *stack);

static
void IDPAutoreleasingStackSetHead(IDPAutoreleasingStack *stack, void *head);

static
size_t IDPAutoreleasingStackGetSize(IDPAutoreleasingStack *stack);

static
void IDPAutoreleasingStackSetSize(IDPAutoreleasingStack *stack, size_t size);

#pragma mark -
#pragma mark Public Impl

void __IDPAutoreleasingStackDeallocate(void *object) {
    IDPAutoreleasingStackSetSize(object, 0);
    
    __IDPObjectDeallocate(object);
}

IDPAutoreleasingStack *IDPAutoreleasingStackCreateWithSize(size_t size) {
    assert(0 != size);
    
    IDPAutoreleasingStack *stack = IDPObjectCreateOfType(IDPAutoreleasingStack);
    IDPAutoreleasingStackSetSize(stack, size);
    IDPAutoreleasingStackSetHead(stack, IDPAutoreleasingStackGetData(stack));
    
    return stack;
}

bool IDPAutoreleasingStackIsEmpty(IDPAutoreleasingStack *stack) {
    return NULL != stack && IDPAutoreleasingStackGetHead(stack) == IDPAutoreleasingStackGetData(stack);
}

bool IDPAutoreleasingStackIsFull(IDPAutoreleasingStack *stack) {
    if (NULL == stack) {
        return false;
    }
    
    void **data = IDPAutoreleasingStackGetData(stack);
    void *head = IDPAutoreleasingStackGetHead(stack);
    
    uint64_t count = IDPAutoreleasingStackGetSize(stack) / sizeof(*data);
    
    return data[count - 1] <= head;
//    return data[count - 1] == head;
//    return (*data - head) >= count;
}

void IDPAutoreleasingStackPushObject(IDPAutoreleasingStack *stack, void *object);

IDPAutoreleasingStackPopType IDPAutoreleasingStackPopObject(IDPAutoreleasingStack *stack);

IDPAutoreleasingStackPopType IDPAutoreleasingStackPopObjectsUntilNULL(IDPAutoreleasingStack *stack);

#pragma mark -
#pragma mark Private Impl


void **IDPAutoreleasingStackGetData(IDPAutoreleasingStack *stack) {
    IDPPointerValueGetter(stack, data);
}

void *IDPAutoreleasingStackGetHead(IDPAutoreleasingStack *stack) {
    IDPPointerValueGetter(stack, head);
}

void IDPAutoreleasingStackSetHead(IDPAutoreleasingStack *stack, void *head) {
    IDPAssignSetter(stack, _head, head);
}

size_t IDPAutoreleasingStackGetSize(IDPAutoreleasingStack *stack) {
    IDPPrimitiveGetter(stack, size);
}

void IDPAutoreleasingStackSetSize(IDPAutoreleasingStack *stack, size_t size) {
    
}