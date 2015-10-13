//
//  QueryingTests.m
//  M13OrderedDictionary
//
//  Created by sodas on 10/13/15.
//  Copyright © 2015 M13OrderedDictionary. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "M13OrderedDictionary.h"
#import "M13TestHelpers.h"

@interface QueryingTests : XCTestCase

@property (nonatomic, strong, readonly) NSArray<NSString *> *expectedKeys;
@property (nonatomic, strong, readonly) NSArray<NSNumber *> *expectedObjects;
@property (nonatomic, assign, readonly) NSUInteger expectedCount;

@property (nonatomic, strong, readonly) NSDictionary<NSString *, NSNumber *> *expectedContainedEntry;
@property (nonatomic, strong, readonly) NSString *expectedContainedKey;
@property (nonatomic, strong, readonly) NSNumber *expectedContainedObject;

@property (nonatomic, strong, readonly) NSDictionary<NSString *, NSNumber *> *expectedNotContainedEntry;
@property (nonatomic, strong, readonly) NSString *expectedNotContainedKey;
@property (nonatomic, strong, readonly) NSNumber *expectedNotContainedObject;

@property (nonatomic, strong, readonly) M13OrderedDictionary<NSString *, NSNumber *> *orderedDictionary;

@end

@implementation QueryingTests

- (void)setUp {
    [super setUp];

    NSArray<NSString *> *keys = @[@"A", @"B", @"C", @"D", @"E", @"F", @"G", @"H", @"I", @"J", @"K", @"L"];
    NSArray<NSNumber *> *objects = @[@1, @2, @3, @4, @5, @6, @7, @8, @9, @10, @11, @12];
    NSAssert(keys.count == objects.count, @"The number of keys and objects are not the same.");

    NSIndexSet *indexSetOfExpectedItems;
    while ((indexSetOfExpectedItems = RandomIndexSet((int)keys.count-1)).count == 0);
    _expectedCount = indexSetOfExpectedItems.count;
    _expectedKeys = [keys objectsAtIndexes:indexSetOfExpectedItems];
    _expectedObjects = [objects objectsAtIndexes:indexSetOfExpectedItems];

    {
        NSUInteger i = arc4random_uniform((int)_expectedCount);
        _expectedContainedKey = _expectedKeys[i];
        _expectedContainedObject = _expectedObjects[i];
        _expectedContainedEntry = @{_expectedContainedKey: _expectedContainedObject};
    }

    {
        NSUInteger i = 0;
        while ([indexSetOfExpectedItems containsIndex:(i = arc4random_uniform((int)keys.count))]);
        _expectedNotContainedKey = keys[i];
        _expectedNotContainedObject = objects[i];
        _expectedNotContainedEntry = @{_expectedNotContainedKey: _expectedNotContainedObject};
    }

    _orderedDictionary = [[M13OrderedDictionary alloc] initWithObjects:self.expectedObjects
                                                        pairedWithKeys:self.expectedKeys];
}

- (void)testContainsObject {
    XCTAssertTrue([self.orderedDictionary containsObject:self.expectedContainedObject]);
    XCTAssertFalse([self.orderedDictionary containsObject:self.expectedNotContainedObject]);
}

- (void)testContainsObjectPairedWithKey {
    XCTAssertTrue([self.orderedDictionary containsObject:self.expectedContainedObject
                                           pairedWithKey:self.expectedContainedKey]);
    XCTAssertFalse([self.orderedDictionary containsObject:self.expectedContainedObject
                                            pairedWithKey:self.expectedNotContainedKey]);
    XCTAssertFalse([self.orderedDictionary containsObject:self.expectedNotContainedObject
                                            pairedWithKey:self.expectedContainedKey]);
}

- (void)testContainsEntry {
    XCTAssertTrue([self.orderedDictionary containsEntry:self.expectedContainedEntry]);
    XCTAssertFalse([self.orderedDictionary containsEntry:self.expectedNotContainedEntry]);
}

- (void)testCount {
    XCTAssertEqual(self.orderedDictionary.count, self.expectedCount);
}

- (void)testLastObject {
    XCTAssertEqualObjects(self.orderedDictionary.lastObject, self.expectedObjects.lastObject);
}

@end
