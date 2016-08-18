#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hashMap.h"

/*
	assertTrue: testing function
	param1: predicate - result of the test function
	param2: message - the output message
	pre: none
	post: none
 */
void assertTrue(int predicate, char *message) {
	printf("%s: ", message);
	if (predicate)
		printf("Pass \n");
	else
		printf("Fail \n");
}

/*
	getWord: function takes a FILE pointer and returns a string which is the next word in the file
	words are defined to be characters, apostrophes or numbers separated by periods, spaces or newlines
	param1: file - the file to parse
	pre: none
	post: no changes to the file
	return: current word of file is returned. NULL is returned at the end of the file
 */
char* getWord(FILE *file) {
	int length = 0;
	int maxLength = 16;
	char character;

	char *word = malloc(sizeof (char) *maxLength);
	assert(word != NULL);

	while((character = fgetc(file)) != EOF) {
		if((length+1) > maxLength) {
			maxLength *= 2;
			word = (char*)realloc(word, maxLength);
		}
		if((character >= '0' && character <= '9') || (character >= 'A' && character <= 'Z') || (character >= 'a' && character <= 'z') || character == 39) {
			word[length] = character;
			length++;
		} else if(length > 0) {
			break;
		}
	}

	if(length == 0)	{
		free(word);
		return NULL;
	}
	word[length] = '\0';
	return word;
}

/*
    concordance: create a hash map which contains word frequencies
    param1: ht - the hash map
    param2: word - the current word to hash
    pre: ht is not NULL
    post: key and value is now updated
    if the key already exists, add 1 to the value
    HINT - this is a 'normal' insert, the difference is that the value is not always 1
    use valAtKey() and insertMap()
*/
void concordance(struct hashMap *ht, char *word) {
	int hash = _hashValue(word, ht->hashID);
	hash = hash % ht->tableSize;
	struct hashLink* temp = malloc(sizeof(struct hashLink));
	temp->key = word;
	temp->value = 1;
	temp->next = NULL;
	if(ht->table[hash] == NULL){
		ht->table[hash] = temp;
		ht->bucketCount++;
	}
	else{
		struct hashLink* cur = ht->table[hash]; /*first node in bucket*/
		struct hashLink* prev = cur;
		while (cur != NULL){
			if(!strcmp(cur->key, word)){ /*true if keys are the same*/
			cur->value += 1;
			return; /*do not need to check the load factor if same key*/
			}
			prev = cur;
			cur = cur->next;
		}
		prev->next = temp;
	}
if(tableLoad(ht) > LOAD_FACTOR_THRESHOLD){
	_reSizeTable(ht, ht->tableSize * 2);
}
}


int main (int argc, const char * argv[]) {
	char *fn; /* File name */
	struct hashMap *hashTable, *hashTable2;
	FILE *filePtr;
	fn = "/Users/tyler/Documents/DataStructuresInC/Homework/Week8/text1.txt"; /*complete file path on Mac*/
	/* fn = "text1.txt"; the file name and path */
	filePtr = fopen(fn, "r");
	hashTable = createMap(40, 1);
    char *word;
    while((word = getWord(filePtr)) != '\0') {
        insertMap(hashTable, word, 1);
    }

    printf("--------------- Testing contains --------------- \n");

    assertTrue(containsKey(hashTable, "it") == 1, "Search for 'it'");
    assertTrue(containsKey(hashTable, "comparison") == 1, "Search for 'comparison'");
    assertTrue(containsKey(hashTable, "period") == 1, "Search for 'period'");
    assertTrue(containsKey(hashTable, "despair") == 1, "Search for 'despair'");
    assertTrue(containsKey(hashTable, "deriop") == 0, "Search for 'deriop'");
    assertTrue(containsKey(hashTable, "yuck") == 0, "Search for 'yuck'");

    printf("--------------- Testing table stats --------------- \n");

    assertTrue(hashTable->tableSize == 40, "Test table size");
    assertTrue(fullBuckets(hashTable) == 30, "Test full buckets");
    assertTrue(emptyBuckets(hashTable) == 10, "Test empty buckets");
    assertTrue(linkCount(hashTable) == 59, "Test link count");

    printf("--------------- Testing remove --------------- \n");

    removeKey(hashTable, "yuck"); /* Should print some type of 'not found' message */
		removeKey(hashTable, "despair");
    assertTrue(containsKey(hashTable, "despair") == 0, "Search for 'despair'");

    printf("--------------- Printing hash table --------------- \n");

    printMap(hashTable);

    deleteMap(hashTable);

    printf("--------------- New table - same text file - new hash --------------- \n");

	fn = "/Users/tyler/Documents/DataStructuresInC/Homework/Week8/text1.txt"; /*complete file path on Mac*/
	/* fn = "text1.txt"; the file name and path */
	printf("Opening file: %s \n", fn);
	filePtr = fopen(fn, "r");
	hashTable2 = createMap(40, 2);

    while((word = getWord(filePtr)) != '\0') {
        insertMap(hashTable2, word, 1);
    }

    printf("--------------- Testing table stats 2 --------------- \n");

    assertTrue(hashTable2->tableSize == 80, "Test table size");
    assertTrue(fullBuckets(hashTable2) == 38, "Test full buckets");
    assertTrue(emptyBuckets(hashTable2) == 42, "Test empty buckets");
    assertTrue(linkCount(hashTable2) == 59, "Test link count");

    printf("Closing file: %s \n", fn);
	fclose(filePtr);

	/* Concordance testing	*/

	struct hashMap *concord;

    fn = "text2.txt";
	printf("Opening file: %s \n", fn);
	filePtr = fopen(fn, "r");
	concord = createMap(10, 2);


	/*instead of calling insert, we call concordance*/
    while((word = getWord(filePtr)) != '\0') {
        concordance(concord, word);
    }

    printf("--------------- Concordance table stats --------------- \n");

    printf("table size: %d \n", concord->tableSize);
    printf("full buckets: %d \n", fullBuckets(concord));
    printf("empty buckets: %d \n", emptyBuckets(concord));
    printf("link count: %d \n", linkCount(concord));

    /* Test further on your own */

		printMap(concord);

	return 0;
}
