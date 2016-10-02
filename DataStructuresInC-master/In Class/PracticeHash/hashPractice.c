#include <stdio.h>
#include <stdlib.h>

struct hashLink {
    char *key;
    int value;
    struct hashLink *next;
};

struct hashTable {
    struct hashLink **table;
    int count;
    int tableSize;
};

int hash(char *word) {
  int sum = 0;
  int i = 0;
  while (word[i] != '\0'){
    sum += word[i];
    i++;
  }
  return sum;
}

struct hashTable *initHash(struct hashTable *ht, int size) {
  ht->count = 0;
  ht->tableSize = size;
  ht->table = malloc(sizeof(struct hashLink) * size);

  int i;
  for (i = 0; i < size; ++i){
    ht->table[i] = NULL;
  }
  return ht;
}

void addHash(struct hashTable *ht, char *key, int val) {
  int hashed = hash(key) % ht->tableSize;
/*if duplicate key, don't malloc*/
  struct hashLink* temp = malloc(sizeof(struct hashLink));
  temp->key = key;
  temp->value = val;
  temp->next = NULL;

    printf("Insterting %s in location %d \n", key, hashed);

  if (ht->table[hashed] == NULL) {
    ht->table[hashed] = temp; /*simple case, no duplicate*/
  } else {
    printf("collision \n");
    struct hashLink* cur = ht->table[hashed]; /*head of the chain at that point*/
    struct hashLink* prev = ht->table[hashed];
    while (cur != NULL){ /*does not account for duplicates*/
      printf("Next \n");
      prev = cur;
      cur = cur->next;
    }
    prev->next = temp;
  }
}

void reHash(struct hashTable *ht, int size) {
    printf("--------------------re-sizing table------------------------ \n");
  struct hashLink** tempTable = ht->table;
  int oldSize = ht->tableSize;
  ht = initHash(ht, size); /*resets the hash table*/

  int i = 0;
  while (i < oldSize){
    struct hashLink* temp = tempTable[i];
    while (temp != NULL){
      addHash(ht, temp->key, temp->value);
      temp = temp->next;
    }
    i++;
  }
}

int main() {
    printf("testing table... \n");

    struct hashTable *myTable;
    myTable = malloc(sizeof(struct hashTable));

    myTable = initHash(myTable, 10);

    addHash(myTable, "ken", 20);
    addHash(myTable, "dave", 24);
    addHash(myTable, "nora", 28);
    addHash(myTable, "greg", 28);
    addHash(myTable, "janice", 28);
    addHash(myTable, "carl", 28);
    addHash(myTable, "carla", 28);
    addHash(myTable, "carlton", 28);

    reHash(myTable, 13); /*when modding by prime numbers, chance for collisions goes down*/


    return 0;
}
