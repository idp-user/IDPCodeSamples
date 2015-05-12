//
//  main.c
//  IDPStudy
//
//  Created by Alexander Kradenkov on 5/6/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#include <stdio.h>

#include "IDPDefineSamples.h"
#include "IDPPrimitiveTypeOutputTests.h"
#include "IDPDeclarationsAndFunctions.h"
#include "IDPStructuresTest.h"
#include "IDPBitOutputTests.h"
#include "IDPHeapUsageTests.h"

#include "IDPTestMacros.h"

int main(int argc, const char * argv[]) {
//    // one line macro
//    IDPNoArgOneLineMacro;
//    
//    // multi line macro
//    IDPNoArgMultiLineMacro;
//    
//    // agrumented macro
//    IDPArgumentedMacro(text1, text2, int 1234);
//    
//    performTest(IDPPrimitiveTypeOutputTests);
//    performTest(IDPDeclarationsAndFunctionsTest);
//    performTest(IDPHumanStructuresTest);

    performTest(IDPBitOutputPerformTests);
    
    performTest(IDPPerformHeapUsageTests);
    
    return 0; // program will finish execution
}

/***********
 
 "Method" declaration syntax examples
 
 ***********/

// function syntax
char fuction(int value) {    
    return '\0'; // must return value of declared type (char)
}

// procedure syntax
void procedure(int value) {
    if (0 == value) {
        return;
    }
    
    // code will not be executed if value is zero
    value++;
    
    return; // may be ommited because |procedure| doesn't return result (because of |void|)
}
