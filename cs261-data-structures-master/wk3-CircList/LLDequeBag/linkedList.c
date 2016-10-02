#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


/* Double Link*/
struct DLink {
	TYPE value;
	struct DLink * next;
	struct DLink * prev;
};

/* Double Linked List with Head and Tail Sentinels  */

struct linkedList{
	int size;
	struct DLink *firstLink;
	struct DLink *lastLink;
};

/*
	initList
	param lst the linkedList
	pre: lst is not null
	post: lst size is 0
*/

void _initList (struct linkedList *lst) {
  /* FIXME: you must write this */
	assert(lst != 0);

	lst->size = 0;

	lst->firstLink = (struct DLink *)malloc(sizeof(struct DLink));
	lst->lastLink = (struct DLink *)malloc(sizeof(struct DLink));

	lst->firstLink->next = lst->lastLink;
	lst->lastLink->prev = lst->firstLink;
}

/*
 createList
 param: none
 pre: none
 post: firstLink and lastLink reference sentinels
 */

struct linkedList *createLinkedList()
{
	struct linkedList *newList = malloc(sizeof(struct linkedList));
	_initList(newList);
	return(newList);
}

/*
	_addLinkBeforeBefore
	param: lst the linkedList
	param: l the  link to add before
	param: v the value to add
	pre: lst is not null
	pre: l is not null
	post: lst is not empty
*/

/* Adds Before the provided link, l */

void _addLinkBefore(struct linkedList *lst, struct DLink *l, TYPE v)
{
	/* FIXME: you must write this */
	assert(lst != 0);

	struct DLink *newLink = (struct DLink *)malloc(sizeof(struct DLink));

	newLink->prev = l->prev;
	newLink->next = l;

	newLink->prev->next = newLink;
	l->prev = newLink;

	newLink->value = v;
	lst->size++;
}


/*
	addFrontList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/

void addFrontList(struct linkedList *lst, TYPE e)
{

	/* FIXME: you must write this */
	assert(lst != 0);

	struct DLink *newLink = (struct DLink *)malloc(sizeof(struct DLink));

	newLink->prev = lst->firstLink;
	newLink->next = lst->firstLink->next;

	lst->firstLink = newLink;
	newLink->next->prev = newLink;

	newLink->value = e;
	lst->size++;
}

/*
	addBackList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/

void addBackList(struct linkedList *lst, TYPE e) {

	/* FIXME: you must write this */
	assert(lst != 0);

	struct DLink *newLink = (struct DLink *)malloc(sizeof(struct DLink));

	newLink->next = lst->lastLink;
	newLink->prev = lst->lastLink->prev;

	lst->lastLink->prev = newLink;
	newLink->prev->next = newLink;

	newLink->value = e;
	lst->size++;
}

/*
	frontList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: none
*/

TYPE frontList (struct linkedList *lst) {
	/* FIXME: you must write this */
	/*temporary return value...you may need to change this */
	return(lst->firstLink->next->value);
}

/*
	backList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: lst is not empty
*/

TYPE backList(struct linkedList *lst)
{
	/* FIXME: you must write this */
	/*temporary return value...you may need to change this */
	return(lst->lastLink->prev->value);
}

/*
	_removeLink
	param: lst the linkedList
	param: l the linke to be removed
	pre: lst is not null
	pre: l is not null
	post: lst size is reduced by 1
*/

void _removeLink(struct linkedList *lst, struct DLink *l)
{

	/* FIXME: you must write this */
	assert(lst != 0);
	assert(l != 0);

	l->prev->next = l->next;
	l->next->prev = l->prev;

	lst->size--;
	free(l);
}

/*
	removeFrontList
	param: lst the linkedList
	pre:lst is not null
	pre: lst is not empty
	post: size is reduced by 1
*/

void removeFrontList(struct linkedList *lst) {
   	/* FIXME: you must write this */
	assert(lst != 0);
	assert(lst != 0);

	struct DLink *oldLink = lst->firstLink->next;

	oldLink->next->prev = lst->firstLink;
	lst->firstLink->next = oldLink->next;

	free(oldLink);
	lst->size--;
}

/*
	removeBackList
	param: lst the linkedList
	pre: lst is not null
	pre:lst is not empty
	post: size reduced by 1
*/

void removeBackList(struct linkedList *lst)
{
	/* FIXME: you must write this */
	assert(lst != 0);

	struct DLink *oldLink = lst->lastLink->prev;

	oldLink->prev->next = lst->lastLink;
	lst->lastLink->prev = oldLink->prev;

	free(oldLink);
	lst->size--;
}

/*
	isEmptyList
	param: lst the linkedList
	pre: lst is not null
	post: none
*/

int isEmptyList(struct linkedList *lst) {
 	/* FIXME: you must write this */
	/*temporary return value...you may need to change this */
	if(lst->size > 0)
		return 0;
	else
		return 1;
}


/* Function to print list
 Pre: lst is not null
 */
void _printList(struct linkedList* lst)
{
	/* FIXME: you must write this */
	assert(lst != 0);

	struct DLink *cur = lst->firstLink->next;
	int i;

	for(i = 0; i < lst->size; i++)
	{
		printf("Value %i: %i\n", i + 1, cur->value);
		cur = cur->next;
	}

}

/*
	Add an item to the bag
	param: 	lst		pointer to the bag
	param: 	v		value to be added
	pre:	lst is not null
	post:	a link storing val is added to the bag
 */
void addList(struct linkedList *lst, TYPE v)
{
	/* FIXME: you must write this */
	assert(lst != 0);

	struct DLink *newLink = (struct DLink *)malloc(sizeof(struct DLink));

	newLink->next = lst->lastLink;
	newLink->prev = lst->lastLink->prev;

	lst->lastLink->prev = newLink;
	newLink->prev->next = newLink;

	newLink->value = v;
	lst->size++;

}

/*	Returns boolean (encoded as an int) demonstrating whether or not
	the specified value is in the collection
	true = 1
	false = 0

	param:	lst		pointer to the bag
	param:	e		the value to look for in the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	no changes to the bag
*/
int containsList (struct linkedList *lst, TYPE e) {
	/* FIXME: you must write this */
	/*temporary return value...you may need to change this */
	assert(lst != 0);
	assert(lst->size > 0);

	struct DLink *cur = lst->firstLink->next;
	int i;

	for(i = 0; i < lst->size; i++)
	{
		if(cur->value == e)
			return 1;
		else
			cur = cur->next;
	}

	return 0;
}

/*	Removes the first occurrence of the specified value from the collection
	if it occurs

	param:	lst		pointer to the bag
	param:	e		the value to be removed from the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	e has been removed
	post:	size of the bag is reduced by 1
*/
void removeList (struct linkedList *lst, TYPE e) {
	/* FIXME: you must write this */
	assert(lst != 0);
	assert(lst->size > 0);

	struct DLink *cur = lst->firstLink->next;
	int i;

	for(i = 0; i < lst->size; i++)
	{
		if(cur->value == e)
		{
			_removeLink(lst, cur);
			break;
		}
	}
}
