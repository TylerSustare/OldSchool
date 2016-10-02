/*	dynamicArray.c: Dynamic Array implementation. */
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "dynamicArray.h"

struct DynArr {
    TYPE *data;		/* pointer to the data array */
    int size;		/* Number of elements in the array */
    int capacity;	/* capacity ofthe array */
};
void printDynArr(DynArr*, int);

/* ************************************************************************
	Dynamic Array Functions
 ************************************************************************ */

/* Initialize (including allocation of data array) dynamic array.
	param: 	d pointer to the dynamic array
	param:	cap	capacity of the dynamic array
	pre:	d is not null
	post:	internal data array can hold cap elements
	post:	d->data is not null
 */
void initDynArr(DynArr *d, int capacity) {
    assert(capacity > 0);
    assert(d!= 0);
    d->data = (TYPE *) malloc(sizeof(TYPE) * capacity);
    assert(d->data != 0);
    d->size = 0;
    d->capacity = capacity;
}

/* Allocate and initialize dynamic array.
	param:	cap desired capacity for the dynamic array
	pre:	none
	post:	none
	ret:	a non-null pointer to a dynArr of cap capacity and 0 elements in it.
 */
DynArr* createDynArr(int cap) {
    DynArr *dyn;
    assert(cap > 0);
    dyn = (DynArr *)malloc(sizeof( DynArr));
    if(!dyn) {
        printf("Failed to allocate memory \n");
    }
    initDynArr(dyn,cap);
    return dyn;
}

/* Deallocate data array in dynamic array.
	param: 	d pointer to the dynamic array
	pre:	none
	post:	d->data points to null
	post:	size and capacity are 0
	post:	the memory used by d->data is freed
 */
void freeDynArr(DynArr *d) {
    if(d->data != 0) {
        free(d->data); 	/* free the space on the heap */
        d->data = 0;   	/* make it point to null */
    }
    d->size = 0;
    d->capacity = 0;
}

/* Deallocate data array and the dynamic array ure.
	param: 	d pointer to the dynamic array
	pre:	none
	post:	the memory used by d->data is freed
	post:	the memory used by d is freed
 */
void deleteDynArr(DynArr *d) {
    freeDynArr(d);
    free(d);
}

/* Get the size of the dynamic array
	param: 	d pointer to the dynamic array
	pre:	d is not null
	post:	none
	ret:	the size of the dynamic array
 */
int sizeDynArr(DynArr *d) {
    return d->size;
}

/* 	Adds an element to the end of the dynamic array
	param: 	d pointer to the dynamic array
	param:	val	the value to add to the end of the dynamic array
	pre:	the dynArry is not null
	post:	size increases by 1
	post:	if reached capacity, capacity is doubled
	post:	val is in the last utilized position in the array
 */
void addDynArr(DynArr *d, TYPE val) {
    /* FIXME: You will write this function */
    if (d->size >= d->capacity) {
        d->capacity *= 2;
        ///printf("Capacity doubled\n");
    }
    /// printf("d->size is: %d\n", d->size);
    d->data[d->size] = val;
    /// printf("d->data[d->size] = %f\n", val);
    d->size += 1;
    
}

/*	Get an element from the dynamic array from a specified position
	param: 	d pointer to the dynamic array
	param:	pos	integer index to get the element from
	pre:	d is not null
	pre:	d is not empty
	pre:	pos < size of the dyn array and >= 0
	post:	no changes to the dyn Array
	ret:	value stored at index pos
 */
TYPE getDynArr(DynArr *d, int pos) {
    /* FIXME: You will write this function */
    /* FIXME: you must change this return value */
    return d->data[pos];
}

/*	Put an item into the dynamic array at the specified location, overwriting the element that was there
	param: 	d pointer to the dynamic array
	param:	pos	the index to put the value into
	param:	val	the value to insert
	pre:	d is not null
	pre:	d is not empty
	pre:	pos >= 0 and pos < size of the array
	post:	index pos contains new value, val
 */
void putDynArr(DynArr *d, int pos, TYPE val) {
    /* FIXME: You will write this function */
    d->data[pos] = val;
}

/*	Swap two specified elements in the dynamic array
	param: 	d pointer to the dynamic array
	param:	i, j the elements to be swapped
	pre:	d is not null
	pre:	d is not empty
	pre:	i & j are greater than 0
	pre:	i & j are less than the size of the dynamic array
	post:	index i now holds the value at j and index j now holds the value at i
 */
void swapDynArr(DynArr *d, int i, int  j) {
    /* FIXME: You will write this function */
    TYPE temp;
    temp = d->data[i];
    d->data[i] = d->data[j];
    d->data[j] = temp;
}

/*	Remove the element at the specified location from the array, shifts other elements back one to fill the gap
	param: 	d pointer to the dynamic array
	param:	pos	location of element to remove
	pre:	d is not null
	pre:	d is not empty
	pre:	pos < size and pos >= 0
	post:	the element at pos is removed
	post:	the elements past pos are moved back one
 */
void removeAtDynArr(DynArr *d, int pos) {
    /* FIXME: You will write this function */
    TYPE temp[d->size];
    int i;
    for (i = 0; i < d->size; ++i) {
        temp[i] = d->data[i];
    }
    d->size -= 1;
    i = 0;
    while (i < d->size){
        if (i >= pos) {
            d->data[i] = temp[i+1];
        }else{
            d->data[i] = temp[i];
        }
        ++i;
    }
}

/* ************************************************************************
	Stack Interface Functions
 ************************************************************************ */

/*	Returns boolean (encoded in an int) demonstrating whether or not the dynamic array stack has an item on it.
	param:	d pointer to the dynamic array
	pre:	the dynamic array is not null
	post:	none
	ret:	1 if empty, otherwise 0
 */
int isEmptyDynArr(DynArr *d) {
    /* FIXME: You will write this function */
    int isTrue = 0; // initialize isTrue to false
    if (d->data == NULL && d->size == 0) {
        isTrue = 1;
    }
    return isTrue;
}

/* 	Push an element onto the top of the stack
	param:	d pointer to the dynamic array
	param:	val	the value to push onto the stack
	pre:	d is not null
	post:	size increases by 1 - if capacity is reached, then capacity is doubled
	post:	val is on the top of the stack
 */
void pushDynArr(DynArr *d, TYPE val) {
    /* FIXME: You will write this function */
    if (d->size >= d->capacity) {
        d->capacity *= 2;
    }
    d->data[d->size] = val;
    d->size += 1;
}

/* Removes the element on top of the stack
	param:	d pointer to the dynamic array
	pre:	d is not null
	pre:	d is not empty
	post:	size is decremented by 1
 the top has been removed
 */
void popDynArr(DynArr *d) {
    /* FIXME: You will write this function */
    d->size = d->size - 1;
}

/*	Returns the element at the top of the stack
	param:	d pointer to the dynamic array
	pre:	d is not null
	pre:	d is not empty
	post:	no changes to the stack
 */
TYPE peekDynArr(DynArr *d) {
    /* FIXME: You will write this function */
    return d->data[d->size-1];
}

/* ************************************************************************
	Bag Interface Functions
 ************************************************************************ */

/*	Returns boolean (encoded as an int) demonstrating whether or not the specified value is in the collection
	param:	d pointer to the dynamic array
	param:	val	the value to look for in the bag
	pre:	d is not null
	pre:	d is not empty
	post:	if true, 1 is returned
	post:	if false, 0 is returned
	post:	no changes to the bag
 */
int containsDynArr(DynArr *d, TYPE val) {
    /* FIXME: You will write this function */
    int i = 0;
    int contains = 0; // initialize to false
    while (i < d->size) {
        if (d->data[i] == val) {
            contains = 1;
        }
        i++;
    }
    /* FIXME:  You will change this return value */
    return contains;
}

/*	Removes the first occurrence of the specified value from the collection	if it occurs
	param:	d pointer to the dynamic array
	param:	val	the value to remove from the array
	pre:	d is not null
	pre:	d is not empty
	post:	val has been removed
	post:	size of the bag is reduced by 1
 */
void removeDynArr(DynArr *d, TYPE val) {
    int i = 0;
    while (i < d->size) {
        if (d->data[i] == val){
            removeAtDynArr(d, i);
            break;
        }
        ++i;
    }
}

/************************************************************************
 Print Array Function
 ***********************************************************************/


