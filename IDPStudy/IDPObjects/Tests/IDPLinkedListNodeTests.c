//
//  IDPLinkedListNodeTests.c
//  IDPStudy
//
//  Created by Alexander Kradenkov on 5/18/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#include "IDPLinkedListNodeTests.h"

#include "IDPLinkedListNode.h"

void IDPLinkedListNodePerformTests() {
    IDPObject *object = IDPObjectCreateOfType(IDPObject);
    IDPLinkedListNode *node = IDPLinkedListNodeCreateWithObject(object);
    
    
    
    IDPObjectRelease(node);
    IDPObjectRelease(object);
}
