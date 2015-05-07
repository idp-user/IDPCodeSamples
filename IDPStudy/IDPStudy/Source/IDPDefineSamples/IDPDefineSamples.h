//
//  IDPDefineSamples.h
//  IDPStudy
//
//  Created by Alexander Kradenkov on 5/6/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#ifndef IDPStudy_IDPDefineSamples_h
#define IDPStudy_IDPDefineSamples_h

// header body

#define IDPStringify(arg) \
    #arg

#define IDPNoArgOneLineMacro printf("no arg macro called\n")

#define IDPNoArgMultiLineMacro \
    printf("no arg macro called 1st line\n"); \
    printf("no arg macro called 2nd line\n")

#define IDPArgumentedMacro(arg1, arg2, arg3) \
    printf("no arg macro called " IDPStringify(arg1) "\n"); \
    printf("no arg macro called " IDPStringify(arg2) "\n"); \
    printf("no arg macro called " IDPStringify(arg3) "\n")

#endif
