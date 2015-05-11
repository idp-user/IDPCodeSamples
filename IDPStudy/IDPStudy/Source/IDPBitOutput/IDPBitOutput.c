//
//  IDPBitOutput.c
//  IDPStudy
//
//  Created by Alexander Kradenkov on 5/11/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#include "IDPBitOutput.h"

// Создать универсальный метод для вывода битов числа (различных типов) в консоль.

#pragma mark -
#pragma mark Private Declarations

static const uint8_t kIDPBitCount = 8;

#pragma mark -
#pragma mark Public

void IDPBitFieldValueOutput(void *byteAddress, size_t size) {
    printf("{");
    char *bitfieldAddress = (char *)byteAddress + size - 1;
    
    for (uint16_t index = 0; index < size; index++) {
        IDPByteValueOutput(bitfieldAddress);
        
        bitfieldAddress--;
        printf(", ");
    }
    
    printf("}");
}

void IDPByteValueOutput(char *byteAddress) {
    uint8_t value = *byteAddress;
    for (uint8_t shiftBitCount = kIDPBitCount; shiftBitCount > 0; shiftBitCount--) {
        uint8_t shiftedValue = value >> (shiftBitCount - 1);
        printf("%d", (shiftedValue & 1));
        if (shiftBitCount != 1) {
            printf(" ");
        }
    }
    
}