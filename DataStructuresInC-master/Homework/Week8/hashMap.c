#include "hashMap.h"

/*
	hashFunction1: The first hash function you will use - the sum of the ASCII values is computed
	param1: str - the string to hash
	pre: str is not NULL
	post: none
	return: the sum of the ASCII values of the word is returned
*/
int hashFunction1(char *str) {
	int i;
	int sum = 0;
	for (i = 0; str[i] != '\0'; ++i){
		sum += str[i];
	}
	return sum;
}

/*
	hashFunction2: The second hash function you will use - the difference is in the for loop
	param1: str - the string to hash
	pre: str is not NULL
	post: none
	return: the hash is returned - not as easily explained as hashFunction1
*/
int hashFunction2(char *str) {
	int i;
	int h = 0;
	for (i = 0; str[i] != '\0'; i++) {
		h += (i+1) * str[i];
	}
	return abs(h);
}

/*
	hashValue: returns the hash of the key - hash algorithm is specified
	param1: str - the string to hash
	param2: hashNum - the number of the hashing function
	pre: str is not NULL
	post: none
	return: the hash is returned
*/
int _hashValue(char *key, int hashNum) {
    if(hashNum == 1) {
        return hashFunction1(key);
    } else {
        return hashFunction2(key);
    }
}

/*
	initMap: Initialize the hashMap
	param1: ht - the hash map to initialize
	param2: tableSize - the size of the hash map
	pre: ht is not NULL
	pre: tableSize is greater than 0
	post: memory for table has been allocated - need to store specified (tableSize) hash links
	post: tableSize has been set
	post: bucketCount is set to 0
	post: count is set to 0
	post: hashID is set to ID
	post: all hash links (buckets) are initialized to NULL
*/
void _initMap(struct hashMap *ht, int tableSize, int ID) {
	assert(ht != NULL);
	assert(tableSize > 0);
  /* malloc table and initialize values */
	ht->table = malloc(sizeof(struct hashLink) * tableSize);
	ht->tableSize = tableSize;
	ht->hashID = ID;
	ht->bucketCount = 0;
	ht->count = 0;
  /* initialize all links to NULL */
	int i;
	for (i = 0; i < ht->tableSize; ++i){
		ht->table[i] = NULL;
	}
}

/*
	createMap: allocate memory and initialize a hash map
	param1: tableSize - the capacity of the table
	pre: tableSize > 0
	return: newly created hash map of size, tableSize
    post: memory for the hash map has been created
    post: hash map of size tableSize has been initialized
*/
struct hashMap *createMap(int tableSize, int ID) {
	assert(tableSize > 0);

	struct hashMap *ht;
	ht = malloc(sizeof(struct hashMap));
	assert(ht != 0); /* ensure that memory was successfully allocated */

	_initMap(ht, tableSize, ID);
	return ht;
}

/*
  _reSizeTable: Resizes the hash map to the size, newCap. Rehashes all of the current keys.
  param1: hashMap - the map
	param2: newCap - the new capacity
	pre: ht is not empty
	pre: newCap is > 0
	post: ht now has tableSize, newCap.
	post: all keys have been re-hashed and inserted into ht
	HINT - use insertMap to re-hash the keys. Everything has been completed for you except the copy/re-hash.
	Free the temp data as you copy/re-hash.
*/
void _reSizeTable(struct hashMap *ht, int newCap) {
	struct hashLink *cur, *del; /* Used to free the old hash links and iterate through them */
  struct hashLink **temp = ht->table; /* pointer to the old table */
  int tempSize = ht->tableSize; /* size of the old table */
  _initMap(ht, newCap, ht->hashID); /* Re-initialize the table */
  /* FIX ME */
	int i = 0;
	while(i < tempSize){
		cur = temp[i];
		while(cur != NULL){
			insertMap(ht, cur->key, cur->value);
			del = cur;
			cur = cur->next;
			free(del);
		}
		i++;
	}
}

 /*
	insertMap: insert the key/value into a hash link - no duplicate keys are permitted
	param1: ht - the map
    param2: k - the key to insert - in this case, the word
	param3: v - the value to insert - in this case, the number of occurrences
	pre: ht is not empty
	post: map contains the key/value
	post: count has been incremented
    Duplicate values - if a duplicate key is found, leave it and insert the new value in the link
    Ex. You can't have two hash links for the word 'bobcat', but you can have many links in the same bucket
    Concordance will mange the word count (value) - the hash is not concerned with counts
    You must monitor the load factor and resize (double size) when the load factor is greater than LOAD_FACTOR_THRESHOLD (.75)
    Use the load factor function - contains an explanation of load factor
 */
void insertMap(struct hashMap *ht, KeyType k, ValueType v) {
    /* hash the key */
	int hash = _hashValue(k, ht->hashID);
	hash = hash % ht->tableSize;
  /* create and initialize new link */
	struct hashLink* temp = malloc(sizeof(struct hashLink));
	temp->key = k;
	temp->value = v;
	temp->next = NULL;
	/*if key is not in hashTable*/
	if(ht->table[hash] == NULL){
		ht->table[hash] = temp;
		ht->bucketCount++;
	}
	/*if there is a collision*/
	else{
		struct hashLink* cur = ht->table[hash]; /*first node in bucket*/
		struct hashLink* prev = cur;
		while (cur != NULL){
/*	UNCOMMENT FOR CONCORDANCE IN FIRST FILE		
				if(!strcmp(cur->key, k)){
				cur->value += 1;
				return;
			}
*/
			prev = cur;
			cur = cur->next;
			}
			prev->next = temp;
		}
	/* check load factor and re-size table */
	if(tableLoad(ht) > LOAD_FACTOR_THRESHOLD){
		_reSizeTable(ht, ht->tableSize * 2);
	}
}

/*
	containsKey: determines whether the key is contained in the map
	param1: ht - the map
	param2: k - the key to search for
	pre: ht is not null
	post: none
	return: return 0 is not found, otherwise return 1
*/
int containsKey(struct hashMap *ht, KeyType k) {
    /* hash the key */
		int hash = _hashValue(k, ht->hashID) % ht->tableSize;
    /* search table for the key - return the appropriate value */
		struct hashLink* temp = ht->table[hash];
		while (temp != NULL){
			if (!strcmp(k, temp->key)){
				return 1;
			}
			temp = temp->next;
		}
	return 0;
}

/*
	removeKey: find the hash link for the key and remove it, also free the memory for the hash link
	If unable to find the key, then print an appropriate message
	param1: ht - the map
	param2: k - the key to remove
	pre: ht is not NULL
	post: key has been removed from the table
	post: count has been decremented
	HINT - If the map only contains a single hash link, it is a special case
	removing the solitary link should set the table entry to NULL
 */
void removeKey(struct hashMap *ht, KeyType k) {
	/* check for the key, if not found, then print message and return */
	if(containsKey(ht, k) == 0){
		printf("I'm sorry but '%s' is in another castle.\n", k); /*tm Mario*/
		return;
	}
	/* hash the key */
	int hash = _hashValue(k, ht->hashID) % ht->tableSize;
	/* special case for single link */
	if(ht->table[hash]->next == NULL){
		ht->table[hash] = NULL;
	}
	/* find key and remove it */
	struct hashLink* cur = ht->table[hash];
	struct hashLink* prev = cur;
	while(cur != NULL){
		if(!strcmp(cur->key, k)){
			prev->next = cur->next;
			free(cur);
			break;
		}
		prev = cur;
		cur = cur->next;
	}
}

/*
	valAtKey: return the value stored at the key
	param1: ht - the map
	param2: k - the key to search for
	pre: ht is not null
	pre: if key not found, then display an appropriate message
	post: none
	return: return the value found at the key
*/
ValueType valAtKey(struct hashMap *ht, KeyType k) {
	/* check for the key, if not found, then print message and return */
	if(containsKey(ht, k) == 0){
		printf("I'm sorry but '%s' is in another castle.\n", k); /*tm Mario*/
		return -1;
	}
	/* hash the key */
	int hash = _hashValue(k, ht->hashID) % ht->tableSize;
	/* search table for the key and return the current value */
	struct hashLink* cur = ht->table[hash];
	struct hashLink* prev = cur;
	while(cur != NULL){
		if(!strcmp(cur->key, k)){
			return cur->value;
		}
		prev = cur;
		cur = cur->next;
	}
	return -1; /*function should never reach here*/
}

/*
	sizeMap: returns the number of hashLinks in the map
	param1: ht - the map
	pre: ht is not NULL
	post: none
	return: the bucketCount of the hash table
	this will be the number of 'chains' in the table
*/
int fullBuckets(struct hashMap *ht) {
	return ht->bucketCount;
	printf("bucketcount = %d\n", ht->bucketCount);
}

/*
	emptyBuckets: returns the number of empty buckets in the table, these are buckets which have no hashlinks in them
	param1: ht - the hash table
	pre: ht is not null
	post: no changes to the table
	return: the number of empty buckets in the table
	HINT - you need to check the hash map for NULLs
*/
int emptyBuckets(struct hashMap *ht) {
	return ht->tableSize - ht->bucketCount;
}

/*
	linkCount: returns the number of hashLinks in the map
	param1: ht - the map
	pre: ht is not NULL
	post: none
	return: the count of the hash table
	this will be the total number of hash links in the table
*/
int linkCount(struct hashMap *ht) {
	int i;
	int jackLinks = 0;
	struct hashLink* cur = ht->table[0];
	for(i = 0; i < ht->tableSize; ++i){
		cur = ht->table[i];
		while(cur != NULL){
			jackLinks++;
			cur = cur->next;
		}
	}
  return jackLinks;
}

/*
	printMap: prints the contents of the hash map
	param1: ht - the map
	pre: ht is not NULL
	post: map has been printed to standard output
	return: contents of the hash map are displayed via standard output - see format below
	bucket x: key (value), key (value, ....
    Ex. Bucket 1: cat (1), dog (1), the (5)...
*/
void printMap(struct hashMap *ht) {
	int i, j;
	struct hashLink* curr;
	for (i = 0; i < ht->tableSize; ++i){
		printf("Bucket %d: ", i);
		curr = ht->table[i];
		while(curr != NULL){
			printf("%s (%d), ", curr->key, curr->value);
			curr = curr->next;
		}
		printf("\n");
	}
}

/*
	tableLoad: determine the load of the table
	there are a couple ways you can calculate this - we want full buckets / empty buckets
	we are not concerned with the number of hash links - we are assuming a reasonable hash
	param1: ht - the hash table
	pre: ht is not null
	post: no changes to the table
	return: returns the ratio of: (number of hash links) / (number of buckets)
	HINT - cast one of the operands to a float, otherwise you have integer division
*/
float tableLoad(struct hashMap *ht) {
	float load;
	load = (float)(fullBuckets(ht))/ht->tableSize;
	return load;
}

/*
	capacityMap: returns the number of buckets in the map
	param1: ht - the hash map
	pre: - ht is not null
	post: no changes to the map
	return: return the tableSize
*/
int capacityMap(struct hashMap *ht) {
	return ht->tableSize;
}

/*
	freeMap: free all memory used by the buckets
	param1: ht - the hash map
	pre: - ht is not null
	post: memory used by the hash buckets has been freed
*/
void _freeMap (struct hashMap *ht) {
	int i = 0;
	struct hashLink *cur, *del;
	while(i < ht->tableSize){
		cur = ht->table[i];
		while(cur != NULL){
			del = cur;
			cur = cur->next;
			free(del);
		}
		i++;
	}
}

/*
	freeMap: deallocate buckets and the hash map
	param1: ht - the hash map
	pre: - ht is not null
	post: memory used by the hash buckets and the hash table has been freed
*/
void deleteMap(struct hashMap *ht) {
	assert(ht != NULL);

	_freeMap(ht);/* free all memory used by the buckets */
	free(ht);/* free the hash map */
}
