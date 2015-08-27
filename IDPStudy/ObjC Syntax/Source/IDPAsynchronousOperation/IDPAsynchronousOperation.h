//
//  IDPAsynchronousOperation.h
//  IDPStudy
//
//  Created by Alexander Kradenkov on 8/27/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * @brief The IDPAsynchronousOperation class is an abstract subclass of NSOperation you use to encapsulate the code and data associated with a single asynchronous task.
 * @discussion The IDPBackgroundOperation class implementation extends NSOperation to perform \c main on background and finish the operation by calling \c complete method inside.
 * @note In general, you should override |main| and/or |complete| methods in your sublasses. The implementation of |main| just calls |complete| method.
 */
@interface IDPAsynchronousOperation : NSOperation

/**
 * @brief Completes the operation.
 * @discussion Call this method at any time when operation should be finished.
 * @note Call super method in your subclass method implementation
 */
- (void)complete;

@end
