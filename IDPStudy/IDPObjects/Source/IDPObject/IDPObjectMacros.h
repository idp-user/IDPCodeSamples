//
//  IDPObjectMacros.h
//  IDPStudy
//
//  Created by Alexander Kradenkov on 6/3/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#ifndef __IDPStudy__IDPObjectMacros__
#define __IDPStudy__IDPObjectMacros__

#define IDPAssignSetter(object, ivar, newIvar) \
    if(NULL != object) { \
        object->ivar = newIvar; \
    }

#define IDPRetainSetter(object, ivar, newIvar) \
    if(NULL != object && object->ivar != newIvar) { \
        IDPObjectRetain(newIvar); \
        IDPObjectRelease(object->ivar); \
        object->ivar = newIvar; \
    }


#endif /* defined(__IDPStudy__IDPObjectMacros__) */
