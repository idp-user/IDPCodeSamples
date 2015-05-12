//
//  IDPTestMacros.h
//  IDPStudy
//
//  Created by Alexander Kradenkov on 5/12/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#ifndef IDPStudy_IDPTestMacros_h
#define IDPStudy_IDPTestMacros_h

#include <stdio.h>

extern
void _IDPPrintTestHeader(void);

extern
void _IDPPrintTestFooter(void);

#define performTest(testFunction) \
do { \
    _IDPPrintTestHeader(); \
    printf(" %s started...\n", #testFunction); \
    testFunction(); \
    _IDPPrintTestFooter(); \
    printf(" %s finished.\n", #testFunction); \
} while(0)

#endif
