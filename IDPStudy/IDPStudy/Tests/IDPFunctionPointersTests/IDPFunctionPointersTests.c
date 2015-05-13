//
//  IDPFunctionPointersTests.c
//  IDPStudy
//
//  Created by Alexander Kradenkov on 5/13/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#include "IDPFunctionPointersTests.h"

#include "IDPTestMacros.h"

//int arithmeticFunction(int argument1, int argument2);

typedef int (*IDPArithmeticFunction)(int argument1, int argument2);

static
void IDPOriginTaskPerform(void);

static
void IDPOriginTaskWithFunctionPointersTestPerform(void);

static
int sum(int a, int b);

static
int sub(int a, int b);

static
int incrementWithAbs(int value, int increment);

static
int multiply(int a, int b);

#pragma mark -
#pragma mark Public

void IDPFunctionPointersTestsPerform(void) {
    performTest(IDPOriginTaskPerform);
    performTest(IDPOriginTaskWithFunctionPointersTestPerform);
}

#pragma mark -
#pragma mark Private Impl

void IDPOriginTaskPerform(void) {
    int currentValue = 0;
    printf("currentValue %d\n", currentValue);
    
    currentValue = sum(currentValue, 42);
    printf("currentValue %d\n", currentValue);
    
    currentValue = sub(currentValue, 40);
    printf("currentValue %d\n", currentValue);
    
    currentValue = incrementWithAbs(currentValue, -5);
    printf("currentValue %d\n", currentValue);
    
    currentValue = multiply(currentValue, 3);
    printf("currentValue %d\n", currentValue);
}

void IDPOriginTaskWithFunctionPointersTestPerform(void) {
    const int operationsCount = 4;
    IDPArithmeticFunction operations[operationsCount] = {sum, sub, incrementWithAbs, multiply};
    
    int operands[operationsCount] = {42, 40, -5, 3};
    
    int currentValue = 0;
    printf("currentValue %d\n", currentValue);
    
    for (uint8_t index = 0; index < operationsCount; index++) {
        IDPArithmeticFunction function = operations[index];
        int currentOperand = operands[index];
        
        currentValue = function(currentValue, currentOperand);
        printf("currentValue %d\n", currentValue);
    }
}


int sum(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int incrementWithAbs(int value, int increment) {
    return sum(value, increment < 0 ? -increment : increment);
}

int multiply(int a, int b) {
    return a * b;
}

