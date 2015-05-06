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
     See IDPStudyPlan, lecture 2 task
 */

#define IDPValueOutput(type, specifier) \
    void output_##type(type value) { \
    printf(#type " value = " #specifier "\n", value); \
    }


#define IDPTypeOutput(type, value) \
 output_##type(value)

#endif
