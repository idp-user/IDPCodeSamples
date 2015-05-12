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
#pragma mark Public Implementations

IDPByteOrderType IDPByteOrderGetCurrentType(void) {
    int value = 1;
    
    return 0 == (value & 1) ? kIDPByteOrderTypeLittleEndian : kIDPByteOrderTypeBigEndian;
}

void IDPPrintValueBits(void *value, size_t valueSize, IDPByteOrderType order) {
    printf("{ ");
    for (ptrdiff_t offset = 0; offset < valueSize; offset++) {
        uint8_t byte = *((uint8_t *)value + (kIDPByteOrderTypeBigEndian != order
                                             ? offset
                                             : (valueSize - 1) - offset));
        
        IDPByteOutput(byte);
        printf(" ");
    }
    
    printf("}");
}

#pragma mark -
#pragma mark Private Implementations

void IDPByteOutput(unsigned char byteValue) {
    uint8_t bitCount = 8;
    
    for (int bitShift = (bitCount - 1); bitShift >= 0; bitShift-- ) {
        uint8_t bitValue = ((byteValue >> bitShift) & 1);
        
        printf("%0d", bitValue);
    };
}
