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

// global integer data field, accessible from any scope in whole program
int globalValue = 123;

// static constants are available only from current file
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
int IDPTernarTest(void);

static
int IDPAgrumentedFunctionCallTest(int value);

static
int IDPSumFunctionTest(int value1, int value2);

static
void IDPIncrementFunctionTest(int *value, int incrementValue);

static
void IDPReverseArray(char *array, uint64_t size);

static
void IDPReverseArrayTest(void);

#pragma mark -
#pragma mark Public Implementations

void IDPDeclarationsAndFunctionsTest() {
    int initialValue = globalValue; // |initialValue| is equal to |globalValue| which is equal to 123
    
    IDPVariablesTest();
    
    // |globalValue| is equal to 123
    globalValue = globalValue + 1; // is equal to expression 'globalValue++;' or 'globalValue += 1;'.
    
    // |globalValue| is equal to 124
    
    initialValue = globalValue++; // |initialValue| is equal to 124, |globalValue| is equal to 125
    
    initialValue = ++globalValue; // |initialValue| AND |globalValue| are equal to 126
    
    int result = IDPStaticVariableTest(); // result == 1
    result = IDPStaticVariableTest(); // result == 2
    result = IDPStaticVariableTest(); // result == 3
    
    int updatedResult = 0;
    updatedResult = IDPAgrumentedFunctionCallTest(result); // updatedResult == 3
    updatedResult = IDPAgrumentedFunctionCallTest(-123); // updatedResult == 0
    
    IDPSumFunctionTest(4, 8); // we do not use result. its OK. Example for no reason
    
    int sum = IDPSumFunctionTest(2, 5); // sum == 7
    int *sumPtr = &sum; // |sumPtr| is a pointer of |sum| data field which is integer
    
    IDPIncrementFunctionTest(sumPtr, 123); // sum == 130
    
    IDPStaticArrayTest();
    
    IDPReverseArrayTest();
}

#pragma mark -
#pragma mark Private Implementations

void IDPVariablesTest(void) {
    int firstValue; // complier, give me the data fieald of sizeof(int) bytes, named firstValue
    firstValue = globalValue;
    
    int secondValue = 2;
    int sum = 10; // equivalent of |int sum; sum = 10;|
    
    sum = firstValue + secondValue;
}

void IDPStaticArrayTest(void) {
    char surname[20] = {'B', 'A', 'A', 'A', 'A',
                        'A', 'A', 'A', 'A', 'A',
                        'A', 'A', 'A', 'A', 'A',
                        'A', 'A', 'A', 'A', 0}; // 20 char on stack. And |surname| is pointer to first element of this data ON STACK
    char *surnameString = "0123456789";
    size_t length = strlen(surnameString); // returns count of significant chars, without terminating zero
    
    // surname[index] is equal to expression *(surname + index)
    // surname[i] == |surname| pointer value shifted by (i * sizeof(char)) bytes
    
    for (int index = 0; index < length ; index++) {
        surname[index] = surnameString[index];
    }
    
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
    
    return value++; // returns not incremented |value|
    
    // never be executed because of return called before
    value += kIDPStaticConstant;
}

int IDPSumFunctionTest(int value1, int value2) {
    return value1 + value2;
}

void IDPIncrementFunctionTest(int *valuePointer, int incrementValue) {
    int value = *valuePointer;
    *valuePointer = value + incrementValue;
}

// value += expression; is equal to: value = value + expression

//value <<= expression; is equal to: value = value << expression

//    value = condition ? (var1) : (var2);
//    
//    is equal to:
//    
//    if (condition) {
//        value = var1;
//    } else {
//        value = var2;
//    }

void IDPReverseArrayTest(void) {
    char chars[5] = {'A', 'B', 'c', 'd', 'E'};
    
//    IDPReverseArray(chars, 5);
    IDPReverseArray(&chars[0], sizeof(chars));
    
}

void IDPReverseArray(char *array, uint64_t count) {
    for (uint64_t i = 0, j = count - 1; i < j; i++, j--) {
        char buffer = array[j];
        array[j] = array[i];
        array[i] = buffer;
    }
}
