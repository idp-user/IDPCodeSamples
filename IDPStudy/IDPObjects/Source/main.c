//
//  main.c
//  IDPObjects
//
//  Created by Alexander Kradenkov on 5/12/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#include <stdio.h>

#include "IDPObjectTests.h"
#include "IDPTestMacros.h"

int main(int argc, const char * argv[]) {
    performTest(IDPObjectBehaviorTests);
    
    return 0;
}
