#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>

#define TYPE int

struct sLink {
    TYPE value;
    int level;
    struct sLink *next[1]; /* an array of pointers at the position*/
};

struct skipList {
    int maxLevel;
    int currMax;
    int size;
    struct sLink *sentinel;
};

void initSkipList(struct skipList *list, int max);
int levelGen(struct skipList *list);
void addValTest(struct skipList *list, TYPE val, int lvl);
void addVal(struct skipList *list, TYPE val);
int searchVal(struct skipList *list, TYPE val);
void printLv(struct skipList *list, int lv);
int getSize(struct skipList *list);
void removeLink(struct skipList *list, TYPE val);
void deleteList(struct skipList *list);
void staticTest(struct skipList *list);
void test(struct skipList *list);
