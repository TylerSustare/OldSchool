#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "cirListDeq.h"

/*
	initCirListDeque: Initialize deque.
	param: 	q pointer to the deque
	pre:	q is not null
	post:	q->Sentinel is allocated and q->size equals zero
*/
void initCirListDeque (struct cirListDeque *q) {
    q->Sentinel = malloc(sizeof(struct DLink));
    q->Sentinel->value = -999999; // used for testing;
    q->Sentinel->next = NULL;
    q->Sentinel->prev = NULL;
    q->size = 0;
}

/*
	addBackCirListDeque: Adds a link to the back of the deque
	param: 	q pointer to the deque
	param: 	val	value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the back of the deque
*/
void addBackCirListDeque (struct cirListDeque *q, TYPE val) {
    struct DLink* theBack = malloc(sizeof(struct DLink));
    theBack->value = val;
    /*UPDATE POINTERS*/
    if (q->size == 0) /*If List is empty*/
    {
        theBack->next = q->Sentinel;
        theBack->prev = q->Sentinel;
        q->Sentinel->next = theBack;
        q->Sentinel->prev = theBack;
        q->size++;
    }
    else /* the list has at least 1 non-sentinel node in it*/
    {
      theBack->next = q->Sentinel->prev;
      q->Sentinel->prev->prev = theBack;
      theBack->prev = q->Sentinel;
      q->Sentinel->prev = theBack;
      q->size++;
    }
        printf("added %.0f to the back with %d elements\n",q->Sentinel->prev->value, q->size);
}

/*
	addFrontCirListDeque: Adds a link to the front of the deque
	param: 	q pointer to the deque
	param: 	val	value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the front of the deque
*/
void addFrontCirListDeque(struct cirListDeque *q, TYPE val) {
    struct DLink* theFront = malloc(sizeof(struct DLink));
    theFront->value = val;
    /*UPDATE POINTERS*/
    if (q->size == 0) /*If List is empty*/
    {
        theFront->next = q->Sentinel;
        theFront->prev = q->Sentinel;
        q->Sentinel->next = theFront;
        q->Sentinel->prev = theFront;
        q->size++;
    }
    else /* the list has at least 1 non-sentinel node in it*/
    {
      theFront->prev = q->Sentinel->next;
      q->Sentinel->next->next = theFront;
      theFront->next = q->Sentinel;
      q->Sentinel->next = theFront;
      q->size++;
    }
        printf("added %.0f to the front with %d elements\n",q->Sentinel->next->value, q->size);
}

/*
	frontCirListDeque: Get the value of the front of the deque
	param: 	q pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the front of the deque
*/
TYPE frontCirListDeque(struct cirListDeque *q) {
	return q->Sentinel->next->value;
}

/*
	backCirListDeque: Get the value of the back of the deque
	param: 	q pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the back of the deque
*/
TYPE backCirListDeque(struct cirListDeque *q) {
	return q->Sentinel->prev->value;
}

/*
	removeFrontCirListDeque: Remove the front of the deque
	param: 	q pointer to the deque
	pre:	q is not null and q is not empty
	post:	the front is removed from the deque
*/
void removeFrontCirListDeque (struct cirListDeque *q) {
    q->Sentinel->next->prev->next = q->Sentinel;
    q->Sentinel->next = q->Sentinel->next->prev;
}

/*
	removeBackCirListDeque: Remove the back of the deque
	param: 	q pointer to the deque
	pre:	q is not null and q is not empty
	post:	the back is removed from the deque
*/
void removeBackCirListDeque(struct cirListDeque *q) {
    q->Sentinel->prev->next->prev = q->Sentinel;
    q->Sentinel->prev = q->Sentinel->prev->next;
}

/*
	isEmptyCirListDeque: Check whether the deque is empty
	param: 	q pointer to the deque
	pre:	q is not null
	ret: 	1 if the deque is empty. Otherwise, 0.
*/
int isEmptyCirListDeque(struct cirListDeque *q) {
	if (q->size == 0){
	return 1;
	}
	return 0;
}

/*
	printCirListDeque: Print the links in the deque from front to back
	param: 	q pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the links in the deque are printed from front to back
*/
void printCirListDeque(struct cirListDeque *q) {
	/* FIX ME*/
	if (isEmptyCirListDeque(q)) return;
	//struct DLink* curr = malloc(sizeof(struct DLink));
	struct DLink* curr;
	printf("List size = %d\n", q->size);
	int i = q->size; // counter to point out what node in the LL you are printing
	curr = q->Sentinel->prev; // start curr at beginning of the list
	while(i>0){
        printf("Node %d: %.0f\n", i, curr->value);
        --i;
        curr = curr->next;
	}
	return;
}

/*
	freeCirListDeque: De-allocate all links of the deque
	param: 	q pointer to the deque
	pre:	none
	post:	All links (including backSentinel) are de-allocated
*/
void freeCirListDeque(struct cirListDeque *q) {
	/* FIX ME*/
	free(q);
}
