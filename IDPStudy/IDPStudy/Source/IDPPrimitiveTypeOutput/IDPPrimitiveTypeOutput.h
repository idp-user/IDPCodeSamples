//
//  IDPPrimitiveTypeOutput.h
//  IDPStudy
//
//  Created by Alexander Kradenkov on 5/6/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#ifndef IDPStudy_IDPPrimitiveTypeOutput_h
#define IDPStudy_IDPPrimitiveTypeOutput_h

#include <stdio.h>

/*
 Задачи:
 1. Создать макрос, который бы генерировал метод для вывода в консоль значения любого примитивного типа. 
 У макроса должно быть 2 параметра: тип, спецификатор вывода. 
 При препроцессинге макрос должен создавать метод output_type, где вместо type должен быть подставлен тип, который мы выводим данным сгенерированным методом. Создать второй макрос, который бы занимался вызовом сгенерированного первым макросом метода, на вход должен получать тип метода.
 Требования:
 - создать тестовые методы для проверки того, как работает генерация на всех примитивных типах.

 */

#define IDPValueOutput(type, specifier) \
    void output_##type(type value) { \
    printf(#type " value = " #specifier "\n", value); \
    }


#define IDPTypeOutput(type, value) \
 output_##type(value)

#endif
