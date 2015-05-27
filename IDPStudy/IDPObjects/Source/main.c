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
#include "IDPLinkedListNodeTests.h"
#include "IDPLinkedListTests.h"
#include "IDPArrayTests.h"

int main(int argc, const char * argv[]) {
    performTest(IDPObjectBehaviorTests);
    
    performTest(IDPArrayTestsPerform);
    
    performTest(IDPLinkedListNodePerformTests);
    performTest(IDPLinkedListBehaviorTest);
    
    return 0;
}
