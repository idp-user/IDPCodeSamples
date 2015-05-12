//
//  IDPBitOutput.c
//  IDPStudy
//
//  Created by Alexander Kradenkov on 5/11/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#include "IDPBitOutputTests.h"

#include "IDPBitOutput.h"

#define performTest(testName) \
printf(#testName " started...\n"); \
testName(); \
printf(#testName " finished\n");

static
void IDPByteOutputTest(void);

static
void IDPBitOutputPerformCurrentEndianTest();

static
void IDPBitOutputPerformBigEndianTest();

static
void IDPBitOutputPerformLittleEndianTest();

#pragma mark -
#pragma mark Public Implementations

void IDPBitOutputPerformTests() {
    IDPByteOutputTest();
    performTest(IDPBitOutputPerformCurrentEndianTest);
    performTest(IDPBitOutputPerformBigEndianTest);
    performTest(IDPBitOutputPerformLittleEndianTest);
}

#pragma mark -
#pragma mark Private Implementations

void IDPByteOutputTest(void) {
    char testValue = 5;
    
    IDPByteOutput(testValue);
    
    printf(".\n");
    
    testValue <<= 6;
    IDPByteOutput(testValue);
    printf(".\n");
    
    testValue = UINT8_MAX;
    IDPByteOutput(testValue);
    printf(".\n");
    
    testValue = UINT8_MAX >> 4;
    IDPByteOutput(testValue);
    printf(".\n");
    
    testValue = 0;
    IDPByteOutput(testValue);
    printf(".\n");
}

void IDPBitOutputPerformCurrentEndianTest() {
    printf("current byte order type: %s\n",
           (kIDPByteOrderTypeBigEndian == IDPByteOrderGetCurrentType()
            ? "kIDPByteOrderTypeBigEndian"
            : "kIDPByteOrderTypeLittleEndian"));
}

void IDPBitOutputPerformBigEndianTest(void) {
    short value = 0x7F51;
    
    printf("Big Endian\t\t0x%x = ", value);
    IDPPrintValueBits(&value, sizeof(value), kIDPByteOrderTypeBigEndian);
}

void IDPBitOutputPerformLittleEndianTest() {
    short value = 0x7F51;
    
    printf("Little Endian\t0x%x = ", value);
    IDPPrintValueBits(&value, sizeof(value), kIDPByteOrderTypeLittleEndian);
}
