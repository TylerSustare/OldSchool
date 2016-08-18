
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define TYPE int

struct DynArr {
	TYPE *data;	/* pointer to the data array */
	int size; /* Number of elements in the array */
	int capacity; /* capacity of the array */
};

/* Dynamic Array Functions */
struct DynArr *createDynArr(int cap);
void deleteDynArr(struct DynArr *d);
int sizeDynArr(struct DynArr *d);
void addDynArr(struct DynArr *d, TYPE val);
TYPE getDynArr(struct DynArr *d, int pos);
void putDynArr(struct DynArr *d, int pos, TYPE val);
void swapDynArr(struct DynArr *d, int i, int  j);
void removeAtDynArr(struct DynArr *d, int idx);
void copyDynArr(struct DynArr *source,struct  DynArr *destination);

/* Heap-based Priority Queue Interface */
TYPE getMinHeap(struct DynArr *heap);
void addHeap(struct DynArr *heap, TYPE val);
void removeMinHeap(struct DynArr *heap);
void heapify(struct DynArr *dyn);
void sortHeap(struct DynArr *heap);
void printList(struct DynArr *heap);


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
	pre: none
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
	param: d pointer to the dynamic array
	param: val the value to add to the end of the dynamic array
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
	swapDynArr: Swap two specified elements in the dynamic array
	param1: d pointer to the dynamic array
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
	isEmptyDynArr: returns boolean based on whether the array is empty
	param: d pointer to the dynamic array
	pre: v is not null
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
	containsDynArr: returns boolean based on whether val is in the dynamic array
	param: d pointer to the dynamic array
	param: val the value to look for in the bag
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
      if(d->data[i] == val) {
		  return 1;
	  }
	}

    return 0;
}

/*
	Heap-based priority queue implementation ----------------------------------- Starts here --------------------------------------
*/

/*
	getMinHeap: Get the value from first node in the heap (root)
	param: heap - pointer to the heap
	pre: heap is not empty
	return: value of first node's value
	HINT - getDynArr()
*/
TYPE getHeapTop(struct DynArr *heap) {
    return heap->data[0];

}

/*
    getDynArr(heap, idx)
	addHeap: Add a node to the heap
	param1: heap - pointer to the heap
	param2: node - node to be added to the heap
	pre: heap is not null
	post: node is added to the heap
	HINT - swapDynArr
*/
void addHeap(struct DynArr *heap, TYPE val) {
    /* FIXME */
    printf("adding %d\n", val);
    int idx = heap->size;
    heap->data[idx] = val;
    int par = floor((idx -1)/2);
    heap->size++;
    while(idx > 0){
      int par = floor((idx -1)/2);
      printf("Comparing %d and %d\n", heap->data[idx], heap->data[par]);
      if(heap->data[idx] > heap->data[par]){
        swapDynArr(heap, idx, par);
        printf("Swapping %d and %d\n", heap->data[idx], heap->data[par]);
        idx = par;
      }else{
        printf("no swap\n");
        break;
      }
    }
}

/*
	removeMinHeap: Remove the first node from the heap
	param: heap pointer to the heap
	pre: heap is not empty
	post: the first node is removed from the heap
	HINT - swapDynArr
*/
void removeHeapTop(struct DynArr *heap) {
    int idx = 0; /*spot 0*/
    heap->data[0] = heap->data[heap->size-1];
    heap->size--;
    while(idx < (heap->size-1)/2){ /*stops the loop before you compare children that don't exist. You will go off the end of the array*/
      int left = (2*idx)+1;
      int right = (2*idx)+2;
      int largestChild;
      if(heap->data[left] > heap->data[right]){
        largestChild = left;
      } else {
        largestChild = right;
      }

      if(heap->data[idx] < heap->data[largestChild]){
        printf("Swapping %d and %d\n", heap->data[idx], heap->data[largestChild]);
        swapDynArr(heap, idx, largestChild);
        idx = largestChild;
      } else { /* no swap needed */
        printf("No swap needed\n");
        break;
      }
    }
}

/*
	populateHeap: Populate a test head with 10 values
	param: heap - the dynamic array to fill with values
	pre: heap is not NULL
	post: heap contains 10 values
	post: heap is a heap
*/
void populateHeap(struct DynArr *heap) {
	/* add values to the dynamic array heap */
	addHeap(heap, 7);
	addHeap(heap, 12);
	addHeap(heap, 3);
	addHeap(heap, 5);
	addHeap(heap, 4);
	addHeap(heap, 11);
	addHeap(heap, 6);
	addHeap(heap, 0);
	addHeap(heap, 15);
	addHeap(heap, 9);
}

int main() {
	struct DynArr *heap, *randomDyn;

	heap = createDynArr(10);
	populateHeap(heap);

/*
	int size = 100;
	randomDyn = createDynArr(size);
	int i;
	for(i=0;i<size;i++) {
        addHeap(randomDyn, rand()%1000);
	}
*/
    /* Should print: top: 0 */
    printf("top: %d \n", getHeapTop(heap));
	removeHeapTop(heap);
	/* Should print: top: 3 */
	printf("top: %d \n", getHeapTop(heap));
	removeHeapTop(heap);
	/* Should print: top 4 */
	printf("top: %d \n", getHeapTop(heap));

	return 0;
}
