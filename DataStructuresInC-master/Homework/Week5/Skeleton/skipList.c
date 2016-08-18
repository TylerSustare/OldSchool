/*
    skip list implementation
    link heights are probabilistically determined
    link heights are only allowed to exceed current max (currMax) height by one
    link heights are capped at maximum level (maxLevel)
*/

#include "skipList.h"
#include "stdlib.h"
#include "time.h"
/*#include <malloc.h>*/

/*
    initSkipList: Skiplist is initialized
    pre: list is not null
    pre: max is at least 1 max. should be set to log n of the number of level 1 links
    param1: list - the list
    param2: max - maximum depth of the list
    post: memory is allocated to sentinel
    maxLevel, currMax and size are initialized
*/
void initSkipList(struct skipList *list, int max) {
    assert(list != NULL);
    assert(max > 0);
    list->sentinel = malloc(sizeof(struct sLink)+sizeof(struct sLink)*max);/* sentinel is an array with a pointer to every level */
    list->maxLevel = max;/* max allowable levels */
    list->currMax = 0;/* level of highest node currently */
    list->size = 0;/* number of level 1 links */

    int i;
    for(i = max; i > 0; i--) {
        list->sentinel->next[i] = list->sentinel;/* sentinel points to itself at every level */
        // not looking for null, you will be at the end if you are back at the sentinel!!
    }
}

/*
    levelGen: Generate a random level for new links
    pre: list is not null
    param1: list - the list
    return: random level
    post: random level cannot exceed list->maxLevel
    random level can only exceed currMax by 1
    random levels are determined by a "series of coin flips"
    Each level is 50% less common than the last
    Approximately 50% are level 2, 25% are level 3, 12.5% are level 4, etc
    Each consecutive "heads" adds one to the level, at the first "tails" we have reached our level
    start at level 1 and add 1 for each heads
    Ex: HHT = level 3, T = 1, THH = 1, HHHT = 4
*/
int levelGen(struct skipList *list) {
    /* FIX ME */
    assert(list != NULL);
   int lvl = (rand()%(list->maxLevel)) + 1;
   srand(time(0));
   int i = 1;
   while(i && lvl <= list->maxLevel){
     i = rand()%2;
     lvl += 1;
   }
   if (lvl > list->currMax && lvl < list->maxLevel){/*Redundant check for lvl < list->maxLevel*/
      list->currMax = lvl;
   }
   return lvl;
}

/*
    addValTest: Adds a value to the skipList at a specified - useful for testing purposes
    pre: list is not null
    pre: lvl > 0 and lvl <= maxLevel
    param1: list - the list
    param2: val - the value to add
    param3: lvl - the level of the link
    post: value is added to the skip list at each necessary level
*/
void addValTest(struct skipList *list, TYPE val, int lvl) {
    assert(list != NULL);
    assert(lvl <= list->maxLevel && lvl > 0);
    /* pointers for node to insert and iterator node */
    struct sLink *insert, *curr;// curr is the iterator
    /* allocate memory for link to insert - extra space is allocated for the "height" of the link */
    insert = malloc(sizeof(struct sLink) + sizeof(struct sLink)*lvl);
    /* set insert value to val */
   insert->value = val;
    /* set insert level to level */
   insert->level = lvl;
    /* if lvl is greater than currMax, set currMax to lvl */
   if (lvl > list->currMax){
      list->currMax = lvl;
   }
    /* initialize curr to sentinel */
    curr = list->sentinel;
    /* add insert to the correct position for each level of the skip list less or equal to the link's level */
    /* HINT - start at the top and work down */
    int i = lvl; // just sets pointers at the top level and below
    while (i > 0){
      while (curr->next[i] != list->sentinel && curr->next[i]->value < val){
         curr = curr->next[i]; /* printf("slide right\n"); */
      }
      insert->next[i] = curr->next[i];
      curr->next[i] = insert;
      i--; /*printf("slid down\n"); */
    }
}

/*
    addVal: Adds a value to the skipList at a random level
    pre: list is not null
    pre: lvl > 0 and lvl <= maxLevel
    param1: list - the list
    param2: val - the value to add
    post: value is added to the skip list at each necessary level. Level is generated randomly.
*/
void addVal(struct skipList *list, TYPE val) {
    assert(list != NULL);
    //printf("addVal val %d\n", val);
    struct sLink *insert, *curr;
    int lvl = 0;
    lvl = levelGen(list);
    //printf("levelGen returned %d\n",lvl);
    assert(lvl <= list->maxLevel && lvl > 0);
    insert = malloc(sizeof(struct sLink) + sizeof(struct sLink)*lvl);
    insert->value = val;
    insert->level = lvl;
    if(lvl > list->currMax){
      list->currMax = lvl;
    }
    curr = list->sentinel;
    int i = lvl; /* Starts the add with the top level of the skip list */
    while (i > 0){
      while (curr->next[i] != list->sentinel && curr->next[i]->value < val){
        curr = curr->next[i];
      }
      insert->next[i] = curr->next[i];
      curr->next[i] = insert; //printf("addVal insert %d at: %d\n", val, i);
      i--;
    }
}

/*
    searchVal: Searches the skipList for a value
    pre: list is not null
    param1: list - the list
    param2: val - the search value
    post: returns the number of comparisons needed to find the value - If not found, return 0
*//*can easily be optimzed*/
int searchVal(struct skipList *list, TYPE val) {
    int i = 0;
    struct sLink *printLink = list->sentinel;
    while (printLink->next[1] != list->sentinel){
      i++;
      if (printLink->next[1]->value == val){
        return i;
      }
      printLink = printLink->next[1];
    }
    return 0;
}

/*
    printLv: Print the specified level of the list
    pre: list is not null
    pre: lv is greater than 0 and less than list->maxLevel
    param1: list - the list
    param2: lv - level of the list to print
    post: prints all of the values at a specified level
*/
void printLv(struct skipList *list, int lv) {
	/* FIX ME */
   struct sLink *curr = list->sentinel;
   printf("Level %d: ", lv);
   while(curr->next[lv] != list->sentinel){
      curr = curr->next[lv];
      printf("%d, ", curr->value);
   }
   printf("\n");
}

/*
    getSize: return the number of level 1 links in the skip list
    pre: list is not null
    param1: list - the list
    post: return the number of level 1 links in the list
*/
int getSize(struct skipList *list) {
	int i = 0;
  struct sLink *curr = list->sentinel;
  while(curr->next[i] != list->sentinel){
    i++;
  }
  return i;
}

/*
    removeLink: Remove the first instance of the link containing the value from the list
    pre: list is not null
    param1: list - the list
    param2: val - value to remove
    post: link is removed from the list and pointers are adjusted
    post: if not found "Not Found" is displayed via standard output
*/
void removeLink(struct skipList *list, TYPE val) {
	/* WORKS FOR LEVEL 1, BUT NOT LEVEL 2 YET */
  struct sLink *curr = list->sentinel;
  while(curr->next[1] != list->sentinel){
    if (curr->next[1]->value == val){
      curr->next[1] = curr->next[1]->next[1];
      return;
    }
    curr = curr->next[1];
  }
  printf("Not Found\n");
}

/*
    deleteList: delete all links from the list as well as the list
    pre: list is not null
    param1: list - the list
    post: all links are deallocated
    post: list is deallocated
*/
void deleteList(struct skipList *list) {
	/* FIX ME */
	struct sLink *curr = list->sentinel;
	while (curr->next[1] != list->sentinel){
    free(curr);
	}
  free(list);
}
