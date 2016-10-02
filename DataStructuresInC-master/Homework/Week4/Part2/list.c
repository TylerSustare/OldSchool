#include "listbag.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

/*
	initlist: Function to initialize the list, create both sentinels and initialize pointers
	param lst: the list
	pre: lst is not null
	post: lst size is 0
*/
void initList (struct list *lst) {
	assert(lst != NULL);
	lst->head = malloc(sizeof(struct DLink));
	lst->head->next = NULL;
}

/*
	addFrontList: Function to add a value to the front of the list
	param: head of  the list
	param: e the value to add to the list
	pre: head is not null
	pre: lst is not empty
	post: value is added to the front of the list
*/
void addFrontList(struct DLink *head, TYPE e) {
	struct DLink *temp = malloc(sizeof(struct DLink));
    temp->value = e;
    /* FIX ME*/
    temp->next = head->next;
    head->next = temp;
}

/*
	addBackList: Function to add a value to the back of the list - MUST USE RECURSION
	param: tail of  the list
	param: e the value to add to the list
	pre: tail is not null
	pre: lst is not empty
	post: value is added to the back of the list
*/
void addBackListRecursive (struct DLink *head, TYPE e) {
    if(head->next == NULL){
        struct DLink* ball = malloc(sizeof(struct DLink));
        head->next = ball;
        ball->value = e;
        ball->next = NULL;
    }else{
        addBackListRecursive(head->next, e);
    }
}

/*
	frontList: Function to return the element in the front of the  list
	param: head of the list
	pre: head is not null
	pre: lst is not empty
	post: no changes to the list
	return: return value at front of the list
*/
TYPE frontList (struct DLink *head) {
    /* FIX ME*/
    return head->next->value;

}

/*
	backList: Function to return the element in the back of the  list - MUST USE RECURSION
	param: tail of the list
	pre: tail is not null
	pre: lst is not empty
	post: no changes to the list
	return: return value at back of the list
*/
TYPE backListRecursive (struct DLink *head) {
    /* FIX ME*/
    if (head->next == NULL){
        return head->value;
    }
    return backListRecursive(head->next);
}

/*
	removeFrontList: Function to remove element from front of list
	param: head the list
	pre: head is not null
	pre: head is not empty
	post: front link is removed
*/
void removeFrontList(struct DLink *head) {
	head->next = head->next->next;
}

/*
	removeBackList:	Function to remove element from back of list - MUST USE RECURSION
	param: tail of the list
	pre: tail is not null
	pre: list is not empty
	post: back link is removed
*/
void removeBackListRecursive (struct DLink *head) {
	/* FIX ME*/
	if (head->next->next == NULL){
        head->next = NULL;
	}else{
        removeBackListRecursive(head->next);
	}

}

/*
	displayListRecursive: Function prints the contents of the list - MUST USE RECURSION
	param: head of the list
	pre: head is not null
	post: list contents are printed with printf
*/
void displayListRecursive (struct DLink *head) {
    /* FIX ME*/
    if (head->next == NULL){
        printf("\n");
    }else{
        head = head->next;
        printf("%d, ", head->value);
        return  displayListRecursive(head);
    }
}

/*
	listContainsRecursive: Recursive implementation of contains() - MUST USE RECURSION
	param: head of the list
	param: e is the search value
	pre: head is not null
	post: no changes to the list
	return: Return 1 if found, 0 if not
 */
int listContainsRecursive (struct DLink *head, TYPE e) {
    if(head->value == e){
        return 1;
    }else if(head->next == NULL){
        return 0;
    }
    return listContainsRecursive(head->next, e);
}

/*
	listRemoveRecursive: Recursive implementation of remove() - MUST USE RECURSION
	param: head the list
	param: e the value to remove
	pre: head is not null
	post: first occurrence of e has been removed from the list, size has been decreased by 1
*/
void listRemoveRecursive (struct DLink *head, TYPE e) {
	if (head->next->value == e){
        head->next = head->next->next;
        printf("%d has been removed\n", e);
	}else{
        listRemoveRecursive(head->next, e);
	}

}

/*
	isEmptyList: Function checks whether the list is empty or not
	param: head of the list
	pre: head is not null
	post: none
	return: Return 1 if empty, 0 if not
*/
int isEmptyList(struct DLink *head) {
	assert(head != NULL);
	if(head->next == NULL) {
        return 1;
	}
	return 0;

}

/*
	freeList: Free the list
	param: head of the list
	pre: head is not null
	post: each link of the list has been deallocated
*/
void freeList(struct list *lst) {
    /* FIX ME*/
    free(lst);
}
