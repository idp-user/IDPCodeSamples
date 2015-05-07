//
//  IDPDeclarationsAndFunctions.c
//  IDPStudy
//
//  Created by Alexander Kradenkov on 5/7/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#include <string.h>

#include "IDPDeclarationsAndFunctions.h"

#pragma mark -
#pragma mark Private Declarations

int globalValue = 123;

static const int kIDPStaticConstant = 42;
static const char *kIDPMamaString = "mama";
static const char *kIDPPapaString = "papa";

static
void IDPVariablesTest(void);


static
void IDPStaticArrayTest(void);


static
int IDPStaticVariableTest(void);

static
int IDPAgrumentedFunctionCallTest(int value);

static
int IDPSumFunctionTest(int value1, int value2);

static
void IDPIncrementFunctionTest(int *value, int incrementValue);


#pragma mark -
#pragma mark Public


void IDPDeclarationsAndFunctionsTest() {
    int initialValue = globalValue;
    
    IDPVariablesTest();
    
    globalValue = globalValue + 1; // globalValue++;

    initialValue =  globalValue++;
    
    initialValue = ++globalValue;
    
    int result = IDPStaticVariableTest();
    result = IDPStaticVariableTest();
    result = IDPStaticVariableTest();
    
    int updatedResult = 0;
    updatedResult = IDPAgrumentedFunctionCallTest(result);
    
    updatedResult = IDPAgrumentedFunctionCallTest(-123);
    
    IDPSumFunctionTest(4, 8); // we do not use result. its OK. example for no reason
    
    
    int sum = IDPSumFunctionTest(2, 5);
    
    int *sumPtr = &sum;
    
    IDPIncrementFunctionTest(sumPtr, 123);
    
    IDPStaticArrayTest();
}

#pragma mark -
#pragma mark Private Implementations

void IDPVariablesTest(void) {
    int firstValue; // complier, give me sizeof(int) bytes field named filerstValue
    firstValue = globalValue;
    
    int secondValue = 2;
    
    int sum = 10; // equal to - int sum; sum = 10;
    
    sum = firstValue + secondValue;
}

void IDPStaticArrayTest(void) {
    char surname[20] = {'B', 'A', 'A', 'A', 'A',
                        'A', 'A', 'A', 'A', 'A',
                        'A', 'A', 'A', 'A', 'A',
                        'A', 'A', 'A', 'A', 0}; // 20 char on stack. And |surname| is pointer to first element of this data ON STACK
    char *surnameString = "0123456789";
    
    uint64_t length = strlen(surnameString);
    
    // surname[index] = *(surname + index)
    // surname[i] = surname plus (i * sizeof(char)) bytes
    
    
    for (int index = 0; index < length ; index++) {
        surname[index] = surnameString[index];
    }
    
//    surname[length] = 0;
    
    printf("\n%s \n", surname);
    
    surname[2] = 0;
    printf("\n%s \n", surname);

    
}

int IDPStaticVariableTest(void) {
    static int someStaticVar = 0;
    
    someStaticVar++;
    
    return someStaticVar;
}

int IDPAgrumentedFunctionCallTest(int value) {
    if (-123 == value) {
        return 0;
    }
    
    return (value++);
    
    // neved
    value += kIDPStaticConstant;
}

int IDPSumFunctionTest(int value1, int value2) {
    return value1 + value2;
}

void IDPIncrementFunctionTest(int *valuePointer, int incrementValue) {
    int value = *valuePointer;
    
    *valuePointer = value + incrementValue;
}
