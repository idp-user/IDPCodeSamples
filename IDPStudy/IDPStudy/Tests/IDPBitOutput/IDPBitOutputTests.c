//
//  IDPBitOutput.c
//  IDPStudy
//
//  Created by Alexander Kradenkov on 5/11/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#include "IDPBitOutputTests.h"

#include "IDPBitOutput.h"

static
void IDPByteOutputTest(void);

static
void IDPBitFieldOutputTest(void);

#pragma mark -
#pragma mark Public

void IDPBitOutputPerformTests() {
    IDPByteOutputTest();
    IDPBitFieldOutputTest();
}


#pragma mark -
#pragma mark Private Impl

void IDPByteOutputTest(void) {
    char testValue = 5;
    
    IDPByteValueOutput(&testValue);
    printf(".\n");

    testValue <<= 6;
    IDPByteValueOutput(&testValue);
    printf(".\n");
    
    testValue = UINT8_MAX;
    IDPByteValueOutput(&testValue);
    printf(".\n");
    
    testValue = UINT8_MAX >> 4;
    IDPByteValueOutput(&testValue);
    printf(".\n");
    
    testValue = 0;
    IDPByteValueOutput(&testValue);
    printf(".\n");
}

void IDPBitFieldOutputTest(void) {
    
    int value1 = 1;

    printf("value 1\n");
    IDPBitFieldValueOutput(&value1, sizeof(value1));
    
    printf("value 1\n");
    value1 = 0x7fFFF;
    IDPBitFieldValueOutput(&value1, sizeof(value1));
    
    uint64_t value = UINT64_MAX;
    printf("value \n");
    IDPBitFieldValueOutput(&value, sizeof(value));

    value = value & 0x70F;
    printf("value \n");
    IDPBitFieldValueOutput(&value, sizeof(value));
    
}