//
//  IDPPrimitiveTypeOutputTests.c
//  IDPStudy
//
//  Created by Alexander Kradenkov on 5/6/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#include "IDPPrimitiveTypeOutputTests.h"

#include "IDPPrimitiveTypeOutput.h"

IDPValueOutput(int, %d)
IDPValueOutput(short, %d)
IDPValueOutput(char, %c)
IDPValueOutput(float, %5.4f)

#define performTest(testName) \
    printf(#testName " started...\n"); \
    testName(); \
    printf(#testName " finished\n");

#pragma mark -
#pragma mark Private Declarations

static
void IDPPrimitiveTypeOutputMethodTests(void);

static
void IDPPrimitiveTypeCallingMacroTests(void);

#pragma mark -
#pragma mark Public

void IDPPrimitiveTypeOutputTests(void) {
    performTest(IDPPrimitiveTypeOutputMethodTests);
    performTest(IDPPrimitiveTypeCallingMacroTests);
    
//    IDPPrimitiveTypeOutputMethodTests();
//    IDPPrimitiveTypeCallingMacroTests();
}

#pragma mark -
#pragma mark Private Impl

void IDPPrimitiveTypeOutputMethodTests(void) {
    output_int(50);
    output_char('B');
    output_short(12);
}

void IDPPrimitiveTypeCallingMacroTests(void) {
    IDPTypeOutput(short, 15);
    IDPTypeOutput(float, 12.23f);
}
