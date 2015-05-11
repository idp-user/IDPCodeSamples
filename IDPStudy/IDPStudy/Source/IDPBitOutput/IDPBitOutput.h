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

extern
void IDPBitFieldValueOutput(void *byteAddress, size_t size);

extern
void IDPByteValueOutput(char *byteAddress);

#endif /* defined(__IDPStudy__IDPBitOutput__) */
