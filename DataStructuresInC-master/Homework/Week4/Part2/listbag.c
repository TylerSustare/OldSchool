#include "listbag.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

/*
	initBag:Function to initialize bag
	param: b the bag
	pre: b is not null
	post: list implementing the bag is initialized, size = 0
*/
void initBag(struct bag* b) {
	assert( b != NULL);
	b->lst = (struct list*)malloc(sizeof(struct list));/*Allocate for the list implementing the bag*/
	initList(b->lst);/*Initialize list*/
	b->size = 0;
}

/*
	addToBag: Function to add an element to the bag
	param: b the bag
	param: val the value added to the bag
	pre: b is not null
	post: val is added to the bag (list implementing the bag), size is incremented
*/
void addToBag(struct bag* b, TYPE val) {
 	addFrontList(b->lst->head, val);
 	b->size++;
}

/*
	removeFromBag: Function to remove an element from the bag
	param: b the bag
	param: val the value to remove from the bag
	pre: b is not null
	post: Element (if found) removed from bag size is decremented.
*/
void removeFromBag(struct bag* b, TYPE val) {
	int i = 0;
	while (i <b->size){
        if (b->lst->head->next->value = val){
            b->lst->head->next = b->lst->head->next->next;
            b->size--;
        }
        ++i;
	}
}

/*
	bagContains: Function to test if an element exists in the bag
	param: b the bag
	param: val the value to search for
	pre: b is not null
	post: no changes to the bag
	return: return 1 if found, otherwise return 0
*/
int bagContains(struct bag* b, TYPE val) {
    int i = 0;
    struct DLink* curr = b->lst->head;
    while (i < b->size && curr->next != NULL){
        if (curr->next->value == val){
            return 1;
        }
        ++i;
        curr = curr->next;
    }
}

/*
	isEmptyBag: Function to test if the bag is empty
	param: b the bag
	pre: b is not null
	post: no changes to the bag
	return: return 1 if found, otherwise return 0
*/
int isEmptyBag(struct bag* b) {
    if (b->size == 0) return 1;
    return 0;
}

/*
	freeBag: Function to deallocate bag memory
	param: b the bag
	pre: b is not null
	post: bag is deallocated
*/
void freeBag(struct bag *b) {
    /* FIX ME*/
    free(b);
}

