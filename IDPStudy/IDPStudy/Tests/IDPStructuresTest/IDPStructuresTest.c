//
//  IDPStructuresTest.c
//  IDPStudy
//
//  Created by Alexander Kradenkov on 5/11/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#include <stddef.h>

#include "IDPStructuresTest.h"

#include "IDPStructures.h"

#pragma mark -
#pragma mark Private

static
void IDPHumanStructuresSizeofTest(void);

static
void IDPHumanStructuresOffsetofTest(void);

#pragma mark -
#pragma mark Public

void IDPHumanStructuresTest(void) {
    IDPHumanStructuresSizeofTest();
    IDPHumanStructuresOffsetofTest();
}

#pragma mark -
#pragma mark Private Implementations

void IDPHumanStructuresSizeofTest(void) {
    IDPHuman human;
    
    printf("human %lu\n", sizeof(human));
    printf("IDPHuman %lu\n", sizeof(IDPHuman));

    printf("_name %lu\n", sizeof(human._name));
    printf("_isAlive %lu\n", sizeof(human._isAlive));
    printf("_friend %lu\n", sizeof(human._friend));
    
    
    printf("IDPHumanCompressed %lu\n", sizeof(IDPHumanCompressed));
    
    IDPHumanUnioned compactHuman;
    
    compactHuman.flags._isMarried1 = true;
    
    compactHuman.bitFields = UINT16_MAX;
    
    
    
    printf("IDPHumanUnioned %lu\n", sizeof(IDPHumanUnioned));
}

void IDPHumanStructuresOffsetofTest(void) {
    printf("IDPHuman offsetof\n");
    printf("_name %lu\n", offsetof(IDPHuman, _name));
    printf("_isAlive %lu\n", offsetof(IDPHuman, _isAlive));
    printf("_friend %lu\n", offsetof(IDPHuman, _friend));
    
    printf("bitFields %lu\n", offsetof(IDPHumanUnioned, bitFields));
    printf("flags %lu\n", offsetof(IDPHumanUnioned, flags));
    
}
