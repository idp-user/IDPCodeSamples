//
//  IDPStructures.h
//  IDPStudy
//
//  Created by Alexander Kradenkov on 5/11/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#ifndef __IDPStudy__IDPStructures__
#define __IDPStudy__IDPStructures__

#include <stdio.h>
#include <stdbool.h>

typedef struct IDPHuman IDPHuman;

struct IDPHuman {
    char *_name; // 8 byte for pointer
    bool _isAlive; // 1 byte for bool
    // char span[7];
    IDPHuman *_friend; // 8 byte for pointer
    bool _isMarried; // 1 byte for bool
    // char span[7];
};

typedef struct IDPHumanCompressed IDPHumanCompressed;
typedef struct IDPHumanUnioned IDPHumanUnioned;

struct IDPHumanCompressed {
    char *_name; // 8 byte for pointer
    bool _isAlive; // 1 byte for bool
    bool _isMarried1; // 1 byte for bool
    bool _isMarried2; // 1 byte for bool
    bool _isMarried3; // 1 byte for bool
    bool _isMarried4; // 1 byte for bool
    bool _isMarried5; // 1 byte for bool
    bool _isMarried6; // 1 byte for bool
    bool _isMarried7; // 1 byte for bool
    // char span[6];
    IDPHuman *_friend; // 8 byte for pointer
};

struct IDPHumanUnioned {
    char *_name; // 8 byte for pointer
    int _charValue; // 7 bit of _charValue and _isAlive one bit
    union {
        struct {
            bool _isAlive:1; // 1 byte for bool
            bool _isMarried1:1; // 1 byte for bool
            bool _isMarried2:1; // 1 byte for bool
            bool _isMarried3:1; // 1 byte for bool
            bool _isMarried4:1; // 1 byte for bool
            bool _isMarried5:1; // 1 byte for bool
            bool _isMarried6:1; // 1 byte for bool
        } flags;
        uint16_t bitFields;
    };
    // char span[6];
    IDPHuman *_friend; // 8 byte for pointer
};

#endif /* defined(__IDPStudy__IDPStructures__) */
