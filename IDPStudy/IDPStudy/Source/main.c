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

int main(int argc, const char * argv[]) {
    // insert code here...
//    printf("Hello, World!\n");
    
    // one line macro
    IDPNoArgOneLineMacro;
    
    // multi line macro
    IDPNoArgMultiLineMacro;
    
    // agrumented macro
    IDPArgumentedMacro(text1, text2, int 1234);
    
    IDPPrimitiveTypeOutputTests();
    
    return 0;
}
