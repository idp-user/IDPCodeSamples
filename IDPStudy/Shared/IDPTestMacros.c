//
//  IDPTestMacros.c
//  IDPStudy
//
//  Created by Alexander Kradenkov on 5/12/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#include "IDPTestMacros.h"

#pragma mark -
#pragma mark Private Declarations

static uint8_t kIDPTestLevel = 0;

static
void IDPPrintMinusSymbolCountOf(uint8_t count);

#pragma mark -
#pragma mark Public Implementations

void _IDPPrintTestHeader(void) {
    IDPPrintMinusSymbolCountOf(++kIDPTestLevel);
}

void _IDPPrintTestFooter(void) {
    IDPPrintMinusSymbolCountOf(kIDPTestLevel--);
}

#pragma mark -
#pragma mark Private Implementations

void IDPPrintMinusSymbolCountOf(uint8_t count) {
    printf("\n");
    for(uint8_t iterator = 0; iterator < count; iterator ++) {
        printf("-");
    }
}
