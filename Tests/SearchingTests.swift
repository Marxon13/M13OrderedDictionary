//
//  SearchingTests.swift
//  M13OrderedDictionaryTests
//
//  Created by sodas on 10/13/15.
//  Copyright © 2015 M13OrderedDictionary. All rights reserved.
//

import XCTest

class SearchingTests: XCTestCase {

    var data: NSData!

    var orderedDictionary: M13OrderedDictionary!

    func newIncludedData() -> NSData {
        // Base64 of `M13OrderedDictionary`
        return NSData(base64EncodedString: "TTEzT3JkZXJlZERpY3Rpb25hcnk=",
            options: NSDataBase64DecodingOptions(rawValue: 0)) as NSData!
    }

    override func setUp() {
        super.setUp()

        self.data = self.newIncludedData()
        assert(self.data !== self.newIncludedData(),
            "Failed to setup test ... cannot generate different NSData instances.")

        self.orderedDictionary =
            M13OrderedDictionary(objects: [1, 2, 3, 4, 5, data], pairedWithKeys: ["A", "B", "C", "D", "E", "data"])
    }

    func testIndexOfObject() {
        XCTAssertEqual(self.orderedDictionary.indexOfObject(3), 2)
        XCTAssertEqual(Int(self.orderedDictionary.indexOfObject(40)), NSNotFound)
        XCTAssertEqual(self.orderedDictionary.indexOfObject(self.newIncludedData()), 5)
        XCTAssertEqual(self.orderedDictionary.indexOfObject(self.data), 5)
    }

    func testIndexOfKey() {
        XCTAssertEqual(self.orderedDictionary.indexOfKey("D"), 3)
        XCTAssertEqual(Int(self.orderedDictionary.indexOfKey("X")), NSNotFound)
    }

    func testIndexOfEntryWithObjectPairedWithKey() {
        XCTAssertEqual(self.orderedDictionary.indexOfEntryWithObject(2, pairedWithKey: "B"), 1)
        XCTAssertEqual(Int(self.orderedDictionary.indexOfEntryWithObject(2, pairedWithKey: "C")), NSNotFound)
        XCTAssertEqual(Int(self.orderedDictionary.indexOfEntryWithObject(5, pairedWithKey: "C")), NSNotFound)
        XCTAssertEqual(Int(self.orderedDictionary.indexOfEntryWithObject(14, pairedWithKey: "X")), NSNotFound)
    }

    func testIndexOfEntry() {
        XCTAssertEqual(self.orderedDictionary.indexOfEntry(["A": 1]), 0)
        XCTAssertEqual(Int(self.orderedDictionary.indexOfEntry(["A": 42])), NSNotFound)
        XCTAssertEqual(Int(self.orderedDictionary.indexOfEntry(["X": 1])), NSNotFound)
        XCTAssertEqual(Int(self.orderedDictionary.indexOfEntry(["X": 42])), NSNotFound)
    }

    func testIndexOfObjectInRange() {
        XCTAssertEqual(self.orderedDictionary.indexOfObject(4, inRange: NSMakeRange(2, 2)), 3)
        XCTAssertEqual(Int(self.orderedDictionary.indexOfObject(4, inRange: NSMakeRange(0, 2))), NSNotFound)
        XCTAssertEqual(Int(self.orderedDictionary.indexOfObject(40, inRange: NSMakeRange(0, 2))), NSNotFound)
    }

    func testIndexOfKeyInRange() {
        XCTAssertEqual(self.orderedDictionary.indexOfKey("C", inRange: NSMakeRange(2, 2)), 2)
        XCTAssertEqual(Int(self.orderedDictionary.indexOfKey("E", inRange: NSMakeRange(0, 2))), NSNotFound)
        XCTAssertEqual(Int(self.orderedDictionary.indexOfKey("X", inRange: NSMakeRange(0, 2))), NSNotFound)
    }

    func testIndexOfEntryWithObjectPairedWithKeyInRange() {
        XCTAssertEqual(
            self.orderedDictionary.indexOfEntryWithObject(2, pairedWithKey: "B", inRange: NSMakeRange(0, 3)),
            1)
        XCTAssertEqual(
            Int(self.orderedDictionary.indexOfEntryWithObject(2, pairedWithKey: "B", inRange: NSMakeRange(3, 2))),
            NSNotFound)
        XCTAssertEqual(
            Int(self.orderedDictionary.indexOfEntryWithObject(2, pairedWithKey: "C", inRange: NSMakeRange(0, 4))),
            NSNotFound)
    }

    func testIndexOfEntryInRange() {
        XCTAssertEqual(self.orderedDictionary.indexOfEntry(["A": 1], inRange: NSMakeRange(0, 1)), 0)
        XCTAssertEqual(Int(self.orderedDictionary.indexOfEntry(["A": 1], inRange: NSMakeRange(1, 2))), NSNotFound)
        XCTAssertEqual(Int(self.orderedDictionary.indexOfEntry(["A": 42], inRange: NSMakeRange(2, 3))), NSNotFound)
    }

    func testIndexOfObjectIdenticalTo() {
        XCTAssertEqual(self.orderedDictionary.indexOfObjectIdenticalTo(self.data), 5)
        XCTAssertEqual(Int(self.orderedDictionary.indexOfObjectIdenticalTo(self.newIncludedData())), NSNotFound)
    }

    func testKeyOfObjectIdenticalTo() {
        if let key = self.orderedDictionary.keyOfObjectIdenticalTo(self.data) {
            XCTAssertEqual(key as? String, "data")
        } else {
            XCTFail("Get unexpected nil value")
        }
        XCTAssertNil(self.orderedDictionary.keyOfObjectIdenticalTo(self.newIncludedData()))
    }

}
