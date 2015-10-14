//
//  M13TestHelpers.m
//  M13OrderedDictionary
//
//  Created by sodas on 10/13/15.
//  Copyright © 2015 M13OrderedDictionary. All rights reserved.
//

#import "M13TestHelpers.h"

extern NSArray<NSNumber *> *RandomNumbers(int upperBound, NSUInteger count) {
    NSMutableSet *result = [[NSMutableSet alloc] initWithCapacity:count];
    while (result.count < count) {
        [result addObject:@(arc4random_uniform(upperBound))];
    }
    return result.allObjects;
}

extern NSIndexSet *RandomIndexSet(int upperBound) {
    NSMutableIndexSet *result = [[NSMutableIndexSet alloc] init];
    NSUInteger count = arc4random_uniform(upperBound);
    while (result.count < count) {
        [result addIndex:arc4random_uniform(upperBound)];
    }
    return [[NSIndexSet alloc] initWithIndexSet:result];
}
