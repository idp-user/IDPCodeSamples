//
//  IDPBitOutput.h
//  IDPStudy
//
//  Created by Alexander Kradenkov on 5/11/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#ifndef __IDPStudy__IDPBitOutput__
#define __IDPStudy__IDPBitOutput__

#include <stdio.h>

typedef enum {
    kIDPByteOrderTypeBigEndian,
    kIDPByteOrderTypeLittleEndian,
} IDPByteOrderType;

extern
IDPByteOrderType IDPByteOrderGetCurrentType(void);

extern
void IDPPrintValueBits(void *value, size_t valueSize, IDPByteOrderType order);

extern
void IDPByteOutput(unsigned char byteValue);

#endif /* defined(__IDPStudy__IDPBitOutput__) */
