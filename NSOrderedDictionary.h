/*
 Copyright (c) 2012 Brandon McQuilkin
 
 Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 One does not claim this software as ones own.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#import <Foundation/Foundation.h>

@interface NSOrderedDictionary : NSObject <NSCopying, NSFastEnumeration, NSCoding>
{
    NSMutableArray *keys;
    NSMutableArray *objects;
    NSMutableDictionary *pairs;
}
/************ Terminology ************/
/*
 Entry - refers to an object-key pair.
 Object - refers to (id), with an index, and an assocoated key.
 Key - refers to <(id)NSCopying>, with an associated object.
 
 Each method at the end of its corresponding description will indicate what object (NSArray, NSDictionary) which that method is drawn from, so it is easier to find a longer description of what the method does. 
*/
/************ Creating a NSOrderedDictionary ************/
//Creates a new NSOrderedDictionary <NSArray> <NSDictionary>
+ (id)orderedDictionary;
//Duplicates the NSOrderedDictionary, which will refrence the same objects <NSArray> <NSDictionary>
+ (id)orderedDictionaryWithOrderedDictionary:(NSOrderedDictionary *)orderedDictionary;
//Loads from file <NSArray> <NSDictionary>
+ (id)orderedDictionaryWithContentsOfFile:(NSString *)path;
//Loads from URL <NSArray> <NSDictionary>
+ (id)orderedDictionaryWithContentsOfURL:(NSURL *)URL;
//Create with single entry <NSArray> <NSDictionary>
+ (id)orderedDictionaryWithObject:(id)anObject pairedWithKey:(id<NSCopying>)aKey;
//Create with a NSDictionary with multiple object-key pairs<NSArray> <NSDicitonary>
+ (id)orderedDictionaryWithDictionary:(NSDictionary *)entrys;

/************ Initializing an NSOrderedDictionary **************/
//Initializes NSOrderedDictionary <NSArray> <NSDictionary>
- (id)init;
//Initializes with another orderedDictionary, placing in itself the entrys from the given orderedDictionary <NSArray> <NSDictionary>
- (id)initWithOrderedDictionary:(NSOrderedDictionary *)orderedDictionary;
//Initializes with another orderedDictionary, optionally placing in itself copied entrys from the given orderedDictionary <NSArray> <NSDictionary>
- (id)initWithOrderedDictionary:(NSOrderedDictionary *)orderedDictionary copyEntrys:(BOOL)flag;
//Initializes a newly allocated orderedDictionary with the contents of the file at the given path <NSArray> <NSDictionary>
- (id)initWithContentsOfFile:(NSString *)path;
//Initializes with the contents of the given URL <NSArray> <NSDictionary>
- (id)initWithContentsOfURL:(NSURL *)URL;
//Initalizes with the contents of an NSDictionary
- (id)initWithContentsOfDictionary:(NSDictionary *)entrys;
//Initalizes with the given ordered objects and keys <NSArray> <NSDictionary>
- (id)initWithObjects:(NSArray *)orderedObjects pairedWithKeys:(NSArray *)orderedKeys;

/************ Querying an NSOrderedDictionary ************/
//Returns YES if orderedDictionary contains the given object <NSArray>
- (BOOL)containsObject:(id)object;
//Returns YES if the orderedDictionary conains the given entry <NSArray>
- (BOOL)containsObject:(id)object pairedWithKey:(id<NSCopying>)key;
//same as above, but the entry is a NSDictionary with a single object-key pair <NSArray>
- (BOOL)containsEntry:(NSDictionary *)entry;

//returns number of entrys in the orderedDictionary <NSArray> <NSDictionary>
- (NSUInteger)count;

//Returns the object with the highest index value <NSArray>
- (id)lastObject;
//Returns the key with the highest index value <NSArray>
- (id<NSCopying>)lastKey;
//Returns the entry with the highest index value <NSArray>
- (NSDictionary *)lastEntry;

//Returns the object located at index <NSArray>
- (id)objectAtIndex:(NSUInteger)index;
//Returns the key located at index <NSArray>
- (id<NSCopying>)keyAtIndex:(NSUInteger)index;
//returns the entry located at index <NSArray>
- (NSDictionary *)entryAtIndex:(NSUInteger)index;

//Returns an array with objects at the given index set <NSArray>
- (NSArray *)objectsAtIndexes:(NSIndexSet *)indexes;
//Returns an array with keys at the given index set <NSArray>
- (NSArray *)keysAtIndexes:(NSIndexSet *)indexes;
//Returns an orderedDictionary with objects and keys at the given index set <NSArray>
- (NSOrderedDictionary *)entrysAtIndexes:(NSIndexSet *)indexes;
//Returns an unordered NSDictionary with the entrys at the given index set <NSArray>
- (NSDictionary *)unorderedEntrysAtIndexes:(NSIndexSet *)indexes;

//Returns an ordered array of all keys in the ordered dictionary <NSDictionary>
- (NSArray *)allKeys;
//Returns an ordered array of all objects in the ordered dictionary <NSDictionary>
- (NSArray *)allObjects;
//Returns an array containing the keys corresponding to all occurrences of a given object in the dictionary. <NSDictionary>
- (NSArray *)allKeysForObject:(id)anObject;
//Returns the value associated with a given key <NSDictionary>
- (id)objectForKey:(id<NSCopying>)key;
//Returns the set of objects from the orderedDictionary that corresponds to the specified keys as an NSArray. <NSDictionary>
- (NSArray *)objectForKeys:(NSArray *)keys notFoundMarker:(id)anObject;

/************ Enumerating NSOrderedDictionary ************/
//returns an enumerator that lets you acces each object in the ordered dictionary <NSArray> <NSDictionary>
- (NSEnumerator *)objectEnumerator;
//returns an enumerator that lets you access each key in the ordered dictionary <NSArray> <NSDictionary>
- (NSEnumerator *)keyEnumerator;
//returns an enumerator that lets you access each entry in the ordered dictionary <NSArray> <NSDictionary>
//enumerator goes through an ordered array of dictionarys with one key-value pair.
- (NSEnumerator *)entryEnumerator;
//returns an enumerator that lets you acces each object in the ordered dictionary in reverse <NSArray>
- (NSEnumerator *)reverseObjectEnumerator;
//returns an enumerator that lets you access each key in the ordered dictionary in reverse <NSArray>
- (NSEnumerator *)reverseKeyEnumerator;
//returns an enumerator that lets you access each entry in the ordered dictionary in reverse <NSArray>
//enumerator goes through an ordered array of dictionarys with one key-value pair.
- (NSEnumerator *)reverseEntryEnumerator;

/************ Finding Entrys in the NSOrderedDictionary ************/
//Returns the lowest index whose object is equal to the given object <NSArray>
- (NSUInteger)indexOfObject:(id)object;
//Returns the lowest index whose key is equal to the given key <NSArray>
- (NSUInteger)indexOfKey:(id<NSCopying>)key;
//Returns the lowest index of the entry where the object and key are equal to the given object and key <NSArray>
- (NSUInteger)indexOfEntryWithObject:(id)object pairedWithKey:(id<NSCopying>)key;
//Same as above, but the object and key are a single object and key NSDictionary <NSArray>
- (NSUInteger)indexOfEntry:(NSDictionary *)entry;

//Returns the lowest index whose object is equal to the given object in the specified range <NSArray>
- (NSUInteger)indexOfObject:(id)object inRange:(NSRange)range;
//Returns the lowest index whose key is equal to the given key in the specified range <NSArray>
- (NSUInteger)indexOfKey:(id<NSCopying>)key inRange:(NSRange)range;
//Returns the lowest index of the entry where the object and key are equal to the given object and key in the specified range <NSArray>
- (NSUInteger)indexOfEntryWithObject:(id)object pairedWithKey:(id<NSCopying>)key inRange:(NSRange)range;
//Same as above, but the object and key are a single object and key NSDictionary in the specified range <NSArray>
- (NSUInteger)indexOfEntry:(NSDictionary *)entry inRange:(NSRange)range;

//Returns the lowest index whose corresponding object value is identical to a given object. (If their memory addresses are the same) <NSArray>
- (NSUInteger)indexOfObjectIdenticalTo:(id)object;
- (id<NSCopying>)keyOfObjectIdenticalTo:(id)object;

//Returns the lowest index whose corresponding object value is identical to a given object in the specified range. (If their memory addresses are the same) <NSArray>
- (NSUInteger)indexOfObjectIdenticalTo:(id)object inRange:(NSRange)range;
- (id<NSCopying>)keyOfObjectIdenticalTo:(id)object inRange:(NSRange)range;

//Returns the index of the first object in the orderedDictionary that passes the test in the given block
- (NSUInteger)indexOfObjectPassingTest:(BOOL (^)(id obj, NSUInteger idx, BOOL *stop))predicate;
- (id<NSCopying>)keyOfObjectPassingTest:(BOOL (^)(id obj, NSUInteger idx, BOOL *stop))predicate;

//Returns the index of an object in the orderedDictionary that passes a test in a given Block for a given set of enumeration options.
- (NSUInteger)indexOfObjectWithOptions:(NSEnumerationOptions)opts passingTest:(BOOL (^)(id obj, NSUInteger idx, BOOL *stop))predicate;
- (id<NSCopying>)keyOfObjectWithOptions:(NSEnumerationOptions)opts passingTest:(BOOL (^)(id obj, NSUInteger idx, BOOL *stop))predicate;

//Returns the index, from a given set of indexes, of the first object in the orderedDictionary that passes a test in a given Block for a given set of enumeration options. <NSArray>
- (NSUInteger)indexOfObjectAtIndexes:(NSIndexSet *)indexSet options:(NSEnumerationOptions)opts passingTest:(BOOL (^)(id obj, NSUInteger idx, BOOL *stop))predicate;
- (id<NSCopying>)keyOfObjectAtIndexes:(NSIndexSet *)indexSet options:(NSEnumerationOptions)opts passingTest:(BOOL (^)(id obj, NSUInteger idx, BOOL *stop))predicate;

//Returns the index, within a specified range, of an object compared with elements in the orderedDictionary using a given NSComparator block. <NSArray>
- (NSUInteger)indexOfObject:(id)object inSortedRange:(NSRange)r options:(NSBinarySearchingOptions)opts usingComparator:(NSComparator)cmp;
- (id<NSCopying>)keyOfObject:(id)object inSortedRange:(NSRange)r options:(NSBinarySearchingOptions)opts usingComparator:(NSComparator)cmp;

//Returns the indexes of objects in the orderedDictionary that pass a test in a given block. <NSArray>
- (NSIndexSet *)indexesOfObjectsPassingTest:(BOOL (^)(id obj, NSUInteger idx, BOOL *stop))predicate;
- (NSArray *)keysOfObjectsPassingTest:(BOOL (^)(id obj, NSUInteger idx, BOOL *stop))predicate;

//Returns the indexes of objects in the orderedDictionary that pass a test in a given Block for a given set of enumeration options <NSArray>
- (NSIndexSet *)indexesOfObjectsWithOptions:(NSEnumerationOptions)opts passingTest:(BOOL (^)(id obj, NSUInteger idx, BOOL *stop))predicate;
- (NSArray *)keysOfObjectsWithOptions:(NSEnumerationOptions)opts passingTest:(BOOL (^)(id obj, NSUInteger idx, BOOL *stop))predicate;

//Returns the indexes, from a given set of indexes, of objects in the objectDictionary that pass a test in a given Block for a given set of enumeration options. <NSArray>
- (NSIndexSet *)indexesOfObjectsAtIndexes:(NSIndexSet *)indexSet options:(NSEnumerationOptions)opts passingTest:(BOOL (^)(id obj, NSUInteger idx, BOOL *stop))predicate;
- (NSArray *)keysOfObjectsAtIndexes:(NSIndexSet *)indexSet options:(NSEnumerationOptions)opts passingTest:(BOOL (^)(id obj, NSUInteger idx, BOOL *stop))predicate;

/************ Making Objects Preform Selectors ************/
//Sends to each object in the orderedDictionary the message identified by a given selector, starting with the first object and continuing through the array to the last object. <NSArray>
- (void)makeObjectsPreformSelector:(SEL)aSelector;

//Sends the aSelector message to each object in the orderedDictionary, starting with the first object and continuing through the array to the last object. <NSArray>
- (void)makeObjectsPerformSelector:(SEL)aSelector withObject:(id)anObject;

//Executes a given block using each object in the orderedDictionary, starting with the first object and continuing through the orderedDictionary to the last object. <NSArray> <NSDictionary>
- (void)enumerateObjectsUsingBlock:(void (^)(id obj, NSUInteger idx, BOOL *stop))block;

//Executes a given block using each object in the orderedDictionary <NSArray> <NSDictionary>
- (void)enumerateObjectsWithOptions:(NSEnumerationOptions)opts usingBlock:(void (^)(id obj, NSUInteger idx, BOOL *stop))block;

//Executes a given block using the objects in the orderedDictionary at the specified indexes. <NSArray>
- (void)enumerateObjectsAtIndexes:(NSIndexSet *)indexSet options:(NSEnumerationOptions)opts usingBlock:(void (^)(id obj, NSUInteger idx, BOOL *stop))block;

/************ Comparing Ordered Dictionarys ************/
//Returns the first object contained in the receiving orderedDictionary that’s equal to an object in another given array. <NSArray>
- (id)firstObjectInCommonWithOrderedDictionary:(NSOrderedDictionary *)otherOrderedDictionary;
//Returns the first key contained in the receiving orderedDictionary that’s equal to an key in another given array. <NSArray>
- (id)firstKeyInCommonWithOrderedDictionary:(NSOrderedDictionary *)otherOrderedDictionary;
//Returns the first Entry contained in the receiving orderedDictionary that’s equal to an Entry in another given array. <NSArray>
- (id)firstEntryInCommonWithOrderedDictionary:(NSOrderedDictionary *)otherOrderedDictionary;

//Two orderedDictionarys have equal contents if they each hold the same number of objects and objects and keys at a given index in each array satisfy the isEqual: test. <NSArray>
- (BOOL)isEqualToOrderedDictionary:(NSOrderedDictionary *)otherOrderedDictionary;

/************ Deriving New NSOrderedDictionarys ************/
//Duplicate and add an entry <NSArray>
- (NSOrderedDictionary *)orderedDictionaryByAddingObject:(id)object pairedWithKey:(id<NSCopying>)aKey;
//Duplicate and add an entry <NSArray>
- (NSOrderedDictionary *)orderedDictionaryByAddingEntry:(NSDictionary *)entry;
//Duplicate and add objects <NSArray>
- (NSOrderedDictionary *)orderedDictionaryByAddingObjects:(NSArray *)orderedObjects pairedWithKeys:(NSArray *)orderedKeys;

//Evaluates a given predicate against each object in the receiving orderedDictionary and returns a new orderedDictionary containing the objects for which the predicate returns true. <NSArray>
- (NSOrderedDictionary *)filteredOrderDictionarysUsingPredicateForObjects:(NSPredicate *)predicate;
//Returns a new orderedDictionary containing the receiving orderedDictionary's elements that fall within the limits specified by a given range. <NSArray>
- (NSOrderedDictionary *)subOrderedDictionaryWithRange:(NSRange)range;

/************ Sorting ************/
//Analyzes the ordered Dictionary and returns a "hint that speeds the sorting of the objects when the hint is supplied to sorted______UsingFunction:context:hint:.
- (NSData *)sortedObjectsHint;
- (NSData *)sortedKeysHint;

//Returns a new orderedDictionary that lists the receiving orderedDictionary objects in ascending order as defined by the comparison function comparator.
- (NSOrderedDictionary *)sortedByObjectsUsingFunction:(NSInteger (*)(id, id, void *))comparator context:(void *)context;
//Returns a new orderedDictionary that lists the receiving orderedDictionary keys in ascending order as defined by the comparison function comparator.
- (NSOrderedDictionary *)sortedByKeysUsingFunction:(NSInteger (*)(id<NSCopying>, id<NSCopying>, void *))comparator context:(void *)context;

//Returns a new orderedDictionary that lists the receiving orderedDictionary objects in ascending order as defined by the comparison function comparator.
- (NSOrderedDictionary *)sortedByObjectsUsingFunction:(NSInteger (*)(id, id, void *))comparator context:(void *)context hint:(NSData *)hint;
//Returns a new orderedDictionary that lists the receiving orderedDictionary keys in ascending order as defined by the comparison function comparator.
- (NSOrderedDictionary *)sortedByKeysUsingFunction:(NSInteger (*)(id<NSCopying>, id<NSCopying>, void *))comparator context:(void *)context hint:(NSData *)hint;

//Returns a copy of the receiving orderedDicitionary's objects sorted as specified by a given array of sort descriptors
- (NSOrderedDictionary *)sortedByObjectsUsingDescriptors:(NSArray *)descriptors;
//Returns a copy of the receiving orderedDicitionary's keys sorted as specified by a given array of sort descriptors
- (NSOrderedDictionary *)sortedByKeysUsingDescriptors:(NSArray *)descriptors;

//Returns an orderedDictionary that lists the receiving orderedDictionary's objects in ascending order, as determined by the comparison method specified by a given selector.
- (NSOrderedDictionary *)sortedByObjectsUsingSelector:(SEL)comparator;
//Returns an orderedDictionary that lists the receiving orderedDictionary's keys in ascending order, as determined by the comparison method specified by a given selector.
- (NSOrderedDictionary *)sortedByKeysUsingSelector:(SEL)comparator;

//Returns an orderedDictionary that lists the receiving orderedDictionary's objects in ascending order, as determined by the comparison method specified by a given NSComparator Block.
- (NSOrderedDictionary *)sortedByObjectsUsingComparator:(NSComparator)cmptr;
//Returns an orderedDictionary that lists the receiving orderedDictionary's keys in ascending order, as determined by the comparison method specified by a given NSComparator Block.
- (NSOrderedDictionary *)sortedByKeysUsingComparator:(NSComparator)cmptr;

//Returns an orderedDictionary that lists the receiving orderedDictionary's objects in ascending order, as determined by the comparison method specified by a given NSComparator Block.
- (NSOrderedDictionary *)sortedByObjectsWithOptions:(NSSortOptions)opts usingComparator:(NSComparator)cmptr;
//Returns an orderedDictionary that lists the receiving orderedDictionary's keys in ascending order, as determined by the comparison method specified by a given NSComparator Block.
- (NSOrderedDictionary *)sortedByKeysWithOptions:(NSSortOptions)opts usingComparator:(NSComparator)cmptr;


/************ Creating a description ************/
//returns the contents formatted as a property list <NSArray>
- (NSString *)description;
//returns the contents formatted as a property list <NSArray>
- (NSString *)descriptionWithLocale:(id)locale;
//returns the contents formatted as a property list <NSArray>
- (NSString *)descriptionWithLocale:(id)locale indent:(NSUInteger)level;
//Writes contents to file at a given path <NSArray>
- (BOOL)writeToFile:(NSString *)path atomically:(BOOL)flag;
//writes to file at a given URL <NSArray>
- (BOOL)writeToURL:(NSURL *)aURL atomically:(BOOL)flag;

/************ KVO ************/
//Registers an observer to receive key value observer notifications for the specified key-path relative to the objects at the indexes. <NSArray>
- (void)addObserver:(NSObject *)anObserver toObjectsAtIndexes:(NSIndexSet *)indexes forKeyPath:(NSString *)keyPath options:(NSKeyValueObservingOptions)options context:(void *)context;
//Registers an observer to receive key value observer notifications for the specified key-path relative to the objects at the first key value. <NSDictionary>
- (void)addObserver:(NSObject *)observer forKeyPath:(NSString *)keyPath options:(NSKeyValueObservingOptions)options context:(void *)context;
//Removes anObserver from all key value observer notifications associated with the specified keyPath relative to the array’s objects at indexes. <NSArray>
- (void)removeObserver:(NSObject *)anObserver fromObjectsAtIndexes:(NSIndexSet *)indexes forKeyPath:(NSString *)keyPath;
//Removes an observer to receive key value observer notifications for the specified key-path relative to the objects at the first key value. <NSDictionary>
- (void)removeObserver:(NSObject *)observer forKeyPath:(NSString *)keyPath context:(void *)context;
//Invokes setValue:forKey: on each of the orderedDictionary's entrys using the specified value and key. <NSArray>
- (void)setValue:(id)value forKey:(NSString *)key;
//Sets a value to the object whos key is the first key in the key path
- (void)setValue:(id)value forKeyPath:(NSString *)keyPath;
//Returns an NSArray containing the results of invoking valueForKey: using key on each of the array's objects.
- (id)valueForKey:(NSString *)key;
//returns a value to the object whos key is the first key in the key path
- (id)valueForKeyPath:(NSString *)keyPath;

/************ NSCoding ************/
- (void)encodeWithCoder:(NSCoder *)aCoder;
- (id)initWithCoder:(NSCoder *)decoder;

/************ NSCopying *************/
- (id)copy;
- (id)copyWithZone:(NSZone *)zone;
- (id)mutableCopy;
- (id)mutableCopyWithZone:(NSZone *)zone;

/************ NSFastEnumeration ************/
//Cannot figure out how to implement this, in this way without incuring excessive overhead by creating the array of dictionarys each time. Not sure where to put code to create array on the first run, and delete on the last run.
//- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state objects:(id *)stackbuf count:(NSUInteger)len; //Will only produce NSDictionarys with single object-key pairs. If you need to iterate over only the objects and keys, use "allKeys" and "allObjects".

/************ Indexed Subscripts ************/
//These only retreive objects, not keys
- (id)objectAtIndexedSubscript:(NSUInteger)index;
- (id)objectForKeyedSubscript:(id)key;

@end

/*********************************************************************************
 
 NSMutableDictionary
 
 ********************************************************************************/

@interface NSMutableOrderedDictionary : NSOrderedDictionary

/************ Creating and initalizing ************/
+ (id)orderedDictionaryWithCapacity:(NSUInteger)numEntrys;
- (id)initWithCapacity:(NSUInteger)numEntrys;

/************ Adding objects ************/
//add* will add the entry at the end of the orderedDictionary. If the key exists, its entry will be deleted, before the entry is added
- (void)addObject:(id)object pairedWithKey:(id<NSCopying>)key;
- (void)addEntry:(NSDictionary *)entry;
- (void)addEntriesFromOrderedDictionary:(NSOrderedDictionary *)orderedDictionary;
- (void)addEntriesFromDictionary:(NSDictionary *)dictionary;

//insert* will insert the entry at the specific index. If the key exists, its entry will be deleted, before the entry is inserted; also, the insertion compensates for the deleted key, so the entry will end up between the same to indexes regardless if a key is deleted or not.
- (void)insertObject:(id)object pairedWithKey:(id<NSCopying>)key atIndex:(NSUInteger)index;
- (void)insertEntry:(NSDictionary *)entry atIndex:(NSUInteger)index;
- (void)insertEntrysFromOrderedDictionary:(NSOrderedDictionary *)orderedDictionary atIndex:(NSUInteger)index;
- (void)insertEntrysFromDictionary:(NSDictionary *)dictionary atIndex:(NSUInteger)index;

//set* methods will, if a key exists will overrite the object for said key, not changing the order of keys. if the key does not exist, it will append the entry at the end of the ordered dictionary
- (void)setObject:(id)object forKey:(id<NSCopying>)aKey;
- (void)setEntry:(NSDictionary *)entry;
- (void)setEntriesFromOrderedDictionary:(NSOrderedDictionary *)orderedDictionary;
- (void)setEntriesFromDictionary:(NSDictionary *)dictionary;

//set* atIndex methods will, if a key exists will overrite the object for said key, not changing the order of keys. if the key does not exist, the entry will be inserted at the specified index.
- (void)setObject:(id)object forKey:(id<NSCopying>)aKey atIndex:(NSUInteger)index;
- (void)setEntry:(NSDictionary *)entry  atIndex:(NSUInteger)index;
- (void)setEntriesFromOrderedDictionary:(NSOrderedDictionary *)orderedDictionary atIndex:(NSUInteger)index;
- (void)setEntriesFromDictionary:(NSDictionary *)dictionary  atIndex:(NSUInteger)index;



/************ Removing objects ************/

//Vanilla NSMutableDictionary methods, for sanity
- (void)removeObjectForKey:(id)key;
- (void)removeObjectsForKeys:(NSArray *)keys;
- (void)removeAllObjects;

- (void)removeAllEntrys;
- (void)removeLastEntry;

- (void)removeEntryWithObject:(id)object;
- (void)removeEntryWithKey:(id<NSCopying>)key;
- (void)removeEntryWithObject:(id)object pairedWithKey:(id<NSCopying>)key;
- (void)removeEntry:(NSDictionary *)entry;

- (void)removeEntryWithObject:(id)object inRange:(NSRange)range;
- (void)removeEntryWithKey:(id<NSCopying>)key inRange:(NSRange)range;
- (void)removeEntryWithObject:(id)object pairedWithKey:(id<NSCopying>)key inRange:(NSRange)ramge;
- (void)removeEntry:(NSDictionary *)entry inRange:(NSRange)range;

- (void)removeEntryAtIndex:(NSUInteger)index;
- (void)removeEntrysAtIndexes:(NSIndexSet *)indexes;

- (void)removeEntryWithObjectIdenticalTo:(id)anObject;
- (void)removeEntryWithObjectIdenticalTo:(id)anObject inRange:(NSRange)range;

- (void)removeEntrysWithObjectsInArray:(NSArray *)array;
- (void)removeEntrysWithKeysInArray:(NSArray *)array;

- (void)removeEntrysInRange:(NSRange)range;

/************ Replacing objects ************/
- (void)replaceEntryAtIndex:(NSInteger)index withObject:(id)object pairedWithKey:(id<NSCopying>)key;
- (void)replaceEntryAtIndex:(NSUInteger)index withEntry:(NSDictionary *)entry;

- (void)replaceEntrysAtIndexes:(NSIndexSet *)indexes withObjects:(NSArray *)objects pairedWithKeys:(NSArray *)keys;
- (void)replaceEntrysAtIndexes:(NSIndexSet *)indexes withEntrys:(NSArray *)orderedEntrys;//orderedEntrys is an ordered array with NSDictionarys with a single object-key pair as entrys.
- (void)replaceEntrysAtIndexes:(NSIndexSet *)indexes withEntrysFromOrderedDictionary:(NSOrderedDictionary *)orderedDictionary;

- (void)replaceEntrysInRange:(NSRange)range withObjectsFromArray:(NSArray *)objects pairedWithKeysFromArray:(NSArray *)keys inRange:(NSRange)range2;
- (void)replaceEntrysInRange:(NSRange)range withEntrysFrom:(NSArray *)orderedEntrys inRange:(NSRange)range2;//orderedEntrys is an ordered array with NSDictionarys with a single object-key pair as entrys.
- (void)replaceEntrysInRange:(NSRange)range withEntrysFromOrderedDictionary:(NSOrderedDictionary *)dictionary inRange:(NSRange)range2;

- (void)replaceEntrysInRange:(NSRange)range withObjectsFromArray:(NSArray *)objects pairedWithKeysFromArray:(NSArray *)keys;
- (void)replaceEntrysInRange:(NSRange)range withEntrysFrom:(NSArray *)orderedEntrys;//orderedEntrys is an ordered array with NSDictionarys with a single object-key pair as entrys.
- (void)replaceEntrysInRange:(NSRange)range withEntrysFromOrderedDictionary:(NSOrderedDictionary *)dictionary;

- (void)setEntrysToObjects:(NSArray *)objects pairedWithKeys:(NSArray *)keys;
- (void)setEntrysToOrderedDictionary:(NSOrderedDictionary *)orderedDictionary;

/************ Filtering Content ************/
- (void)filterEntrysUsingPredicateForObjects:(NSPredicate *)predicate;

/************ Rearranging content ************/
- (void)exchangeEntryAtIndex:(NSUInteger)idx1 withEntryAtIndex:(NSUInteger)idx2;

- (void)sortEntrysByObjectUsingDescriptors:(NSArray *)descriptors;
- (void)sortEntrysByKeysUsingDescriptors:(NSArray *)descriptors;

- (void)sortEntrysByObjectUsingComparator:(NSComparator)cmptr;
- (void)sortEntrysByKeysUsingComparator:(NSComparator)cmptr;

- (void)sortEntrysByObjectWithOptions:(NSSortOptions)opts usingComparator:(NSComparator)cmptr;
- (void)sortEntrysByKeysWithOptions:(NSSortOptions)opts usingComparator:(NSComparator)cmptr;

- (void)sortEntrysByObjectUsingFunction:(NSInteger (*)(id, id, void *))compare context:(void *)context;
- (void)sortEntrysByKeysUsingFunction:(NSInteger (*)(id, id, void *))compare context:(void *)context;

- (void)sortEntrysByObjectUsingSelector:(SEL)comparator;
- (void)sortEntrysByKeysUsingSelector:(SEL)comparator;

/************ Indexed Subscripts ************/
- (void)setObject:(id)object forKeyedSubscript:(id<NSCopying>)key;

@end
