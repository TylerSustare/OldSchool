#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <float.h>
#include "cirListDeque.h"

/* Double Link Struture */
struct DLink {
	TYPE value;/* value of the link */
	struct DLink * next;/* pointer to the next link */
	struct DLink * prev;/* pointer to the previous link */
};

# define TYPE_SENTINEL_VALUE DBL_MAX


/* ************************************************************************
 Deque ADT based on Circularly-Doubly-Linked List WITH Sentinel
 ************************************************************************ */

struct cirListDeque {
	int size;/* number of links in the deque */
	struct DLink *Sentinel;	/* pointer to the Sentinel */
};
/* internal functions prototypes */
struct DLink* _createLink (TYPE val);
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, TYPE v);
void _removeLink(struct cirListDeque *q, struct DLink *lnk);



/* ************************************************************************
	Deque Functions
************************************************************************ */

/* Initialize deque.

	param: 	q		pointer to the deque
	pre:	q is not null
	post:	q->Sentinel is allocated and q->size equals zero
*/
void _initCirListDeque (struct cirListDeque *q)
{
  	/* FIXME: you must write this */
		assert(q != 0);
		q->size = 0;
		q->Sentinel = (struct DLink *)malloc(sizeof(struct DLink));

		/* Sentinel link is initialized properly */
		q->Sentinel->next = q->Sentinel;
		q->Sentinel->prev = q->Sentinel;
		q->Sentinel->value = 0;
}

/*
 create a new circular list deque

 */

struct cirListDeque *createCirListDeque()
{
	struct cirListDeque *newCL = malloc(sizeof(struct cirListDeque));
	_initCirListDeque(newCL);
	return(newCL);
}


/* Create a link for a value.

	param: 	val		the value to create a link for
	pre:	none
	post:	a link to store the value
*/
struct DLink * _createLink (TYPE val)
{
	/* FIXME: you must write this */
	struct DLink *newestLink = (struct DLink *)malloc(sizeof(struct DLink));

	/*temporary return value..you may need to change it*/
	newestLink->value = val;
	return(newestLink);

}

/* Adds a link after another link

	param: 	q		pointer to the deque
	param: 	lnk		pointer to the existing link in the deque
	param: 	v		value of the new link to be added after the existing link
	pre:	q is not null
	pre: 	lnk is not null
	pre:	lnk is in the deque
	post:	the new link is added into the deque after the existing link
*/
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, TYPE v)
{
	/* FIXME: you must write this */
	assert(q != 0);
	assert(lnk != 0);

	int i, inside = 0;
	struct DLink  *cur = q->Sentinel->next;

	/* check if lnk is inside in the deque */
	for (i = 0; i < q->size; ++i){
		if (cur == lnk){
			inside = 1;
			break;
		}
		cur = cur->next;
	}
	assert(inside != 0); /* if lnk is not inside the deque */

	struct DLink *newLink = (struct DLink *)malloc(sizeof(struct DLink));

	/* put lnk in position. Update pointers */
	newLink->next = lnk->next;
	newLink->prev = lnk;

	lnk->next = newLink;
	newLink->next->prev = newLink;

	newLink->value = v;
	q->size++;
}

/* Adds a link to the back of the deque

	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the back of the deque
*/
void addBackCirListDeque (struct cirListDeque *q, TYPE val)
{
	/* FIXME: you must write this */
	assert(q != 0);

	struct DLink *newLink = (struct DLink *)malloc(sizeof(struct DLink));

	/* put lnk at the back. Update pointers */
	newLink->next = q->Sentinel;
	newLink->prev = q->Sentinel->prev;

	q->Sentinel->prev = newLink;
	newLink->prev->next = newLink;

	newLink->value = val;
	q->size++;
}

/* Adds a link to the front of the deque

	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the front of the deque
*/
void addFrontCirListDeque(struct cirListDeque *q, TYPE val)
{
	/* FIXME: you must write this */
	assert(q != 0);

	struct DLink *newLink = (struct DLink *)malloc(sizeof(struct DLink));

	/* put lnk at the front. Update pointers */
	newLink->next = q->Sentinel->next;
	newLink->prev = q->Sentinel;

	q->Sentinel->next = newLink;
	newLink->next->prev = newLink;

	newLink->value = val;
	q->size++;
}

/* Get the value of the front of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the front of the deque
*/
TYPE frontCirListDeque(struct cirListDeque *q)
{
	/* FIXME: you must write this */
	/*temporary return value..you may need to change it*/
	assert(q != 0);
	return(q->Sentinel->next->value);
}

/* Get the value of the back of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the back of the deque
*/
TYPE backCirListDeque(struct cirListDeque *q)
{
	/* FIXME: you must write this */
	/*temporary return value..you may need to change it*/
	assert(q != 0);
	return(q->Sentinel->next->value);
}

/* Remove a link from the deque

	param: 	q		pointer to the deque
	param: 	lnk		pointer to the link to be removed
	pre:	q is not null and q is not empty
	post:	the link is removed from the deque
*/
void _removeLink(struct cirListDeque *q, struct DLink *lnk)
{
	/* FIXME: you must write this */
	assert(q != 0);
	assert(q->size > 0);
	/* update pointers */
	lnk->prev->next = lnk->next;
	lnk->next->prev = lnk->prev;

	q->size -= 1;
	free(lnk);
}

/* Remove the front of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the front is removed from the deque
*/
void removeFrontCirListDeque (struct cirListDeque *q) {
	/* FIXME: you must write this */
	assert(q != 0);
	assert(q->size > 0);

	_removeLink(q, q->Sentinel->next);
}


/* Remove the back of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the back is removed from the deque
*/
void removeBackCirListDeque(struct cirListDeque *q)
{
  	/* FIXME: you must write this */
		assert(q != 0);
		assert(q->size > 0);

		_removeLink(q, q->Sentinel->prev);
	}

/* De-allocate all links of the deque

	param: 	q		pointer to the deque
	pre:	none
	post:	All links (including Sentinel) are de-allocated
*/
void freeCirListDeque(struct cirListDeque *q)
{
	/* FIXME: you must write this */
	int i, size = q->size;

	/* remove all links */
	for(i = 0; i < size; i++)
	{
		_removeLink(q, q->Sentinel->next);
	}
}

/* Check whether the deque is empty

	param: 	q		pointer to the deque
	pre:	q is not null
	ret: 	1 if the deque is empty. Otherwise, 0.
*/
int isEmptyCirListDeque(struct cirListDeque *q) {
  	/* FIXME: you must write this */
	/*temporary return value..you may need to change it*/
	assert(q != 0);

	if(q->size > 0)
		return(0);
	else
		return(1);
}

/* Print the links in the deque from front to back

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the links in the deque are printed from front to back
*/
void printCirListDeque(struct cirListDeque *q)
{
	/* FIXME: you must write this */
	assert(q != 0);
	assert(q->size > 0);

	struct DLink *cur = q->Sentinel->next;
	int i;

	for(i = 0; i < q->size; i++){
		printf("Value %d: %f\n", i + 1, cur->value);
		cur = cur->next;
	}
}

/* Reverse the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the deque is reversed
*/
void reverseCirListDeque(struct cirListDeque *q)
{
	/* FIXME: you must write this */
	assert(q != 0);
	assert(q->size > 0);

	struct DLink *temp = malloc(sizeof(struct DLink));
	struct DLink *cur = malloc(sizeof(struct DLink));

	cur = q->Sentinel;

	do{
		temp = cur->next;
		cur->next = cur->prev;
		cur->prev = temp;
		cur = temp;

	}while(cur != q->Sentinel);
}
