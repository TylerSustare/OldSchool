/*
	file: dynamicArray.c
	Dynamic Array implementation.
*/
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "dynamicArray.h"

/*
    compare: compare two tasks by priority
    param: left - first task
    param: right - second task
    pre: none
    post: none
	return: return scheme is below
        -1 if priority of left < priority of right
        1 if priority of left > priority of right
        0 if priority of left = priority of right
*/
int compare(TYPE left, TYPE right) {
	if (left.priority < right.priority)
		return -1;
	else if (left.priority > right.priority)
		return 1;
	else
		return 0;
}

/*
	initDynArr: Initialize (including allocation of data array) dynamic array.
	param1: d - pointer to the dynamic array
	param2 : capacity - capacity of the dynamic array
	pre: d is not null
	post: internal data array can hold cap elements
	post: d->data is not null
*/
void initDynArr(struct DynArr *d, int capacity) {
	assert(capacity > 0);
	assert(d != NULL);
	d->data = (TYPE *) malloc(sizeof(TYPE) * capacity);
	assert(d->data != NULL);
	d->size = 0;
	d->capacity = capacity;
}

/*
	createDynArr: Allocate and initialize dynamic array.
	param: cap desired capacity for the dynamic array
	pre: cap is greater than 0
	post: none
	ret: a non-null pointer to a dynArr of cap capacity and 0 elements in it.
*/
struct DynArr *createDynArr(int cap) {
	assert(cap > 0);
	struct DynArr *dyn;
	dyn = malloc(sizeof(struct DynArr));
	if(!dyn) {
		printf("Failed to allocate memory \n");
	}
	initDynArr(dyn,cap);
	return dyn;
}

/*
	freeDynArr: Deallocate data array in dynamic array.
	param: d - pointer to the dynamic array
	pre: none
	post: d->data points to null
	post: size and capacity are 0
	post: the memory used by d->data is freed
*/
void freeDynArr(struct DynArr *d) {
	if(d->data != NULL) {
		free(d->data); /* free the space on the heap */
		d->data = NULL; /* make it point to null */
	}
	d->size = 0;
	d->capacity = 0;
}

/*
	deleteDynArr: Deallocate data array and the dynamic array.
	param: d - pointer to the dynamic array
	pre: d is not NULL
	post: the memory used by d->data is freed
	post: the memory used by d is freed
*/
void deleteDynArr(struct DynArr *d) {
	assert(d != NULL);
	freeDynArr(d);
	free(d);
}

/*
	_dynArrSetCapacity: Resizes the old array to the size of capacity
	param1: d - pointer to the dynamic array
	param2: newCap - the new desired capacity
	pre: d is not null
	post: d has capacity newCap
*/
void _dynArrSetCapacity(struct DynArr *d, int newCap) {
	printf("Doubling array size \n");
	TYPE *oldArr; /* array to store old (undersized) array contents - will be freed */
	int oldSize = d->size;
	oldArr = d->data;

	/* Create a new dynamic array with new capacity */
	initDynArr(d, newCap);

	int i;
	for(i = 0; i < oldSize; i++){
		d->data[i] = oldArr[i];
	}
	d->size = oldSize;
	free(oldArr);
}

/*
	sizeDynArr: Get the size of the dynamic array
	param: d - pointer to the dynamic array
	pre: d is not null
	post: none
	ret: the size of the dynamic array
*/
int sizeDynArr(struct DynArr *d) {
	assert(d != NULL);
	return d->size;
}

/*
	addDynArr: Adds an element to the end of the dynamic array
	param: d - pointer to the dynamic array
	param: val - the value to add to the end of the dynamic array
	pre: the dynArry is not null
	post: size increases by 1
	post: if reached capacity, capacity is doubled
	post: val is in the last utilized position in the array
*/
void addDynArr(struct DynArr *d, TYPE val) {
	assert(d != NULL);
	/* If full, then re-size */
	if(d->size >= d->capacity) {
		_dynArrSetCapacity(d, d->capacity * 2);
	}

	d->data[d->size] = val;
	d->size++;
}

/*
	getDynArr: Get an element from the dynamic array from a specified position
	param1: d - pointer to the dynamic array
	param2: pos - integer index to get the element from
	pre: d is not null
	pre: d is not empty
	pre: pos <= size of the dynamic array and >= 0
	post: no changes to the dynamic array
	return: value stored at index position, pos
*/
TYPE getDynArr(struct DynArr *d, int pos) {
	assert(d != NULL);
	assert(pos <= d->size);
	assert(pos >= 0);

	return d->data[pos];
}

/*
	putDynArr: Put an item into the dynamic array at the specified location, overwriting the element that was there
	param1: d - pointer to the dynamic array
	param2: pos - the index to put the value into
	param3: val	- the value to insert
	pre: d is not null
	pre: d is not empty
	pre: pos >= 0 and pos <= size of the array
	post: index (pos) contains new value (val)
*/
void putDynArr(struct DynArr *d, int pos, TYPE val) {
	assert(d != NULL);
	assert(pos <= d->size);
	assert(pos >= 0);
	d->data[pos] = val;
}

/*
	swapDynArr: Swap two specified elements in the dynamic array
	param1: d - pointer to the dynamic array
	param2: i - one of the elements to be swapped
	param3: j - one of the elements to be swapped
	pre: d is not null
	pre: d is not empty
	pre: i & j are greater than or equal to 0
	pre: i & j are less than the size of the dynamic array
	post: index i now holds the value at j and index j now holds the value at i
*/
void swapDynArr(struct DynArr *d, int i, int  j) {
	TYPE  temp;
	assert(d != NULL);
	assert(i < d->size);
	assert(j < d->size);
	assert(i >= 0);
	assert(j >= 0);

	temp = d->data[i];
	d->data[i] = d->data[j];
	d->data[j] = temp;
}

/*
	removeAtDynArr: Remove the element at the specified location from the array, shifts other elements back one to fill the gap
	param1: d - pointer to the dynamic array
	param2: pos - location of element to remove
	pre: d is not null
	pre: d is not empty
	pre: pos < size and pos >= 0
	post: the element at pos is removed
	post: the elements past pos are shifted back one
*/
void removeAtDynArr(struct DynArr *d, int idx) {
	int i;
	assert(d != NULL);
	assert(idx < d->size);
	assert(idx >= 0);

   /* Shift all elements up */
   for(i = idx; i < d->size-1; i++){
      d->data[i] = d->data[i+1];
   }
   d->size--;
}

/*
	isEmptyDynArr: returns boolean based on whether the array is empty
	param: d - pointer to the dynamic array
	pre: d is not null
	post: none
	ret: 1 if empty, otherwise return 0
*/
int isEmptyDynArr(struct DynArr *d) {
	assert(d != NULL);

	if(d->size == 0) {
		return 1;
	}
	return 0;
}

/*
	copyDynArr: copy elements from a dynamic array to another dynamic array
	param1: source - pointer to the source dynamic array
	param2: destination - pointer to the destination dynamic array
	pre: source is not null and s is not empty
	post: destination is initialized
	post: the elements from source are copied to destination
*/
void copyDynArr(struct DynArr *source, struct DynArr *destination) {
	assert(source != NULL);
	assert(source->size > 0);

	initDynArr(destination, source->capacity);

	int i;
	for(i = 0; i < source->size; i++) {
		destination->data[i] = source->data[i];/* copy elements to destination array */
	}

	destination->size = source->size;
}

/* Stack Interface Functions */

/*
	pushDynArr: Push an element onto the top of the stack
	param: d - pointer to the dynamic array
	param: val - the value to push onto the stack
	pre: d is not null
	post: size increases by 1. If capacity is reached, then capacity is doubled
	post: val is on the top of the stack
*/
void pushDynArr(struct DynArr *d, TYPE val) {
	assert(d != NULL);
	addDynArr(d, val);
}

/*
	peekDynArr: returns the element at the top of the stack
	param: d - pointer to the dynamic array
	pre: d is not null
	pre: d is not empty
	post: no changes to the stack
	return: the value on top of the stack is returned
*/
TYPE peekDynArr(struct DynArr *d) {
	assert(d != NULL);
	assert(!isEmptyDynArr(d));
	return d->data[d->size-1];
}

/*
	popDynArr: removes the element on top of the stack
	param: d - pointer to the dynamic array
	pre: d is not null
	pre: d is not empty
	post: size is decremented by 1. The top of the stack has been removed
*/
void popDynArr(struct DynArr *d) {
	assert(d != NULL);
	assert(! isEmptyDynArr(d));
	d->size--;
}

/* Bag Interface Functions */

/*
	containsDynArr: returns boolean based on whether val is in the dynamic array
	param1: d - pointer to the dynamic array
	param2: val - the value to look for in the bag
	pre: d is not null
	pre: d is not empty
	post: no changes to the bag
	return: if the val is in the bag, return 1, otherwise return 0
*/
int containsDynArr(struct DynArr *d, TYPE val) {
	assert(d != NULL);
	assert(!isEmptyDynArr(d));

	int i = 0;
	for(i = 0; i < sizeDynArr(d); i++) {
      if(compare(d->data[i], val) == 0) {
		  return 1;
	  }
	}

    return 0;
}

/*
	removeDynArr: Removes the first occurrence of the specified value from the collection	if it occurs
	param: d - pointer to the dynamic array
	param: val - the value to remove from the array
	pre: d is not null
	pre: d is not empty
	pre: val is in the dynamic array
	post: val has been removed. Size of the bag is reduced by 1.
*/
void removeDynArr(struct DynArr *d, TYPE val) {
	assert(d != NULL);
	assert(!isEmptyDynArr(d));

	if(!containsDynArr(d, val)) {
		printf("val is not contained in the bag \n");
		return;
	}

	int i = 0;
	for(i = 0; i < sizeDynArr(d); i++) {
      if(compare(d->data[i], val) == 0) {
           removeAtDynArr(d, i);
           break;
		}
	}
}

/*
	Heap-based priority queue implementation ----------------------------------- Starts here --------------------------------------
*/

/*
	getMinHeap: Get the first node in the heap (root)
	param: heap - pointer to the heap
	pre: heap is not empty
	post: no changes to the heap
	return: value of first node's value
*/
TYPE getMinHeap(struct DynArr *heap) {
  /* FIXME */
	/*printf("getMinHeap returning task\n");*/
  return heap->data[0];
}

/*
	_smallerIndexHeap: Get the index of the smaller node between two nodes in a heap - this is an auxiliary function
	param1: heap - pointer to the heap
	param2: i - index of one node
	param3: j - index of the other node
	pre: i < size and j < size
	return: the index of the smaller node
*/
int _smallerIndexHeap(struct DynArr *heap, int i, int j) {
  /* FIXME */
	/* debugging *//* printf("Comparing index %d to index %d\n", i, j);
	int temp; */
	if (heap->data[i].priority < heap->data[j].priority){
		/*printf("%d is the smaller index. Swapping\n", i);*/
		return i;
	}else{
		return j;
	}
}

/*
	addHeap: Add a node to the heap
	param1: heap - pointer to the heap
	param2: val - node to be added to the heap
	pre: heap is not null
	post: node is added to the heap (maintain heap properties)
	post: heap size is incremented
*/
void addHeap(struct DynArr *heap, TYPE val) {
  /* FIXME */
	/*printf("adding task with \"%s\" task and \"%d\" priority\n", val.description, val.priority);*/
	int idx = heap->size;
	heap->data[idx] = val;
	heap->size++;
	while (idx > 0){
		int par = (idx-1)/2;
		/*printf("comparing %d and %d\n", heap->data[idx].priority, heap->data[par].priority);*/
		if(heap->data[idx].priority < heap->data[par].priority){
			swapDynArr(heap, idx, par);
			/*printf("swapping %d and %d\n", heap->data[idx].priority, heap->data[par].priority);*/
			idx = par;
		} else {
			/*printf("no swap\n");*/
			break;
		}
	}
}

/*
	Heap: Remove the first node from the heap
	param: heap - pointer to the heap
	pre: heap is not empty
	post: the first node is removed from the heap - nodes are sifted after top is removed (maintain heap properties)
	HINT: use the _smallerIndexHeap to find the smaller node of the current node
*/
void removeMinHeap(struct DynArr *heap) {
    /* FIXME */
	int idx = 0; /*spot 0*/
	/*printf("Removing base with priority %d\n", heap->data[0].priority);*/
	heap->data[0] = heap->data[heap->size-1];
	heap->size--;
	while (idx < (heap->size-1)/2){
		int left = (2*idx)+1;
		int right = (2*idx)+2;
		int smallestChild;
		smallestChild = _smallerIndexHeap(heap, left, right);
		/*printf("smallestChild = %d\n",heap->data[smallestChild].priority);
*/
		if (heap->data[idx].priority > heap->data[smallestChild].priority){
			/*printf("Swapping %d and %d\n", heap->data[idx].priority, heap->data[smallestChild].priority);*/
			swapDynArr(heap, idx, smallestChild);
			idx = smallestChild;
		} else {
			/*printf("No swap needed\n");*/
			break;
		}
	}
}

/*
  heapify: builds a heap from an arbitrary dynArray
  param: dyn - a dynamicArray to be converted to a heap
  pre: dyn is not empty
  post: dyn has heap properties
*/
void heapify(struct DynArr *dyn) {
  struct DynArr *heap = malloc(sizeof(struct DynArr));
  initDynArr(heap, dyn->size); /* temporary heap we are building. Free it when you are done with it*/
  /* FIXME */
  int itr; /* itterator */
  for (itr = 0; itr < heap->size; ++itr){
    addHeap(heap, dyn->data[itr]);
  }
  dyn = heap;
  free(heap);
}

/*
    sortHeap: converts a heap into a sorted dynamic array
    param: heap - pointer to the heap
    pre: heap is not empty
    post: the heap is in sorted order
    HINT: you can use the copyDynArr() function to copy arrays
*/
void sortHeap(struct DynArr *heap) {
  struct DynArr *aux = createDynArr(heap->size);
  initDynArr(aux, heap->size);/* temporary heap we are building. Free it when you are done with it*/
  /* FIXME */
  int itr = 0; /* itterator */
  int initialSize = heap->size;
  printf("size = %d\n",  aux->size);
  while (heap->size > 0){
		pushDynArr(aux, heap->data[0]);
		removeMinHeap(heap);
		itr++;
	}
	printf("new size = %d\n",  aux->size);
  copyDynArr(aux, heap);
  free(aux);
}
