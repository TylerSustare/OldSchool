#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#define KeyType char *
#define ValueType int
#define TYPE double
#define LOAD_FACTOR_THRESHOLD .75

struct hashLink {
   KeyType key; /* The key is what you use to look up a hashLink */
   ValueType value; /* The value stored with the hashLink, an int in our case */
   struct hashLink * next; /* Notice how these are like linked list nodes */
};

struct hashMap {
    struct hashLink **table; /* Array of pointers to hashLinks */
    int tableSize; /* Number of buckets in the table */
    int bucketCount; /* Number of non-empty buckets in the table */
    int count; /* Number of hash links */
    int hashID; /* ID of the hashing algorithm */
};

/* Hash functions */
int stringHash1(char * str);
int stringHash2(char * str);
int _hashValue(char *key, int hashNum);

/* Hash Map Functions */
void _initMap (struct hashMap * ht, int tableSize, int ID);
struct hashMap *createMap (int tableSize, int ID);
void _reSizeTable(struct hashMap *ht, int newCap);
void insertMap (struct hashMap * ht, KeyType k, ValueType v);
int containsKey (struct hashMap * ht, KeyType k);
void removeKey (struct hashMap * ht, KeyType k);
ValueType valAtKey(struct hashMap *ht, KeyType k);
int fullBuckets(struct hashMap *ht);
int emptyBuckets(struct hashMap *ht);
int linkCount(struct hashMap *ht);
void printMap(struct hashMap * ht);
float tableLoad(struct hashMap *ht);
int capacityMap(struct hashMap *ht);
void _freeMap (struct hashMap * ht);
void deleteMap (struct hashMap * ht);

void assertTrue(int predicate, char *message);
char* getWord(FILE *file);
void concordance(struct hashMap *ht, char *word);
