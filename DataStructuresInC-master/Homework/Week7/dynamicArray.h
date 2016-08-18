/*
	file: dynamicArray.h
	Dynamic array implementation
*/

#define TYPE struct task

#define TASK_DESC_SIZE 128

struct task {
	char description[TASK_DESC_SIZE]; /* description of the task */
	int priority; /* task priority */
};

struct DynArr {
	TYPE *data;	/* pointer to the data array */
	int size; /* Number of elements in the array */
	int capacity; /* capacity of the array */
};

/* used to compare TYPEs - in this case, "tasks" */
int compare(TYPE left, TYPE right);

/* Dynamic Array Functions */
void initDynArr(struct DynArr *d, int capacity);
struct DynArr *createDynArr(int cap);
void deleteDynArr(struct DynArr *d);
int sizeDynArr(struct DynArr *d);
void addDynArr(struct DynArr *d, TYPE val);
TYPE getDynArr(struct DynArr *d, int pos);
void putDynArr(struct DynArr *d, int pos, TYPE val);
void swapDynArr(struct DynArr *d, int i, int  j);
void removeAtDynArr(struct DynArr *d, int idx);
void copyDynArr(struct DynArr *source,struct  DynArr *destination);

/* Stack interface. */
int isEmptyDynArr(struct DynArr *d);
void pushDynArr(struct DynArr *d, TYPE val);
TYPE peekDynArr(struct DynArr *d);
void popDynArr(struct DynArr *d);

/* Bag Interface */
int containsDynArr(struct DynArr *d, TYPE val);
void removeDynArr(struct DynArr *d, TYPE val);

/* Heap-based Priority Queue Interface */
TYPE getMinHeap(struct DynArr *heap);
void addHeap(struct DynArr *heap, TYPE val);
void removeMinHeap(struct DynArr *heap);
void heapify(struct DynArr *dyn);
void sortHeap(struct DynArr *heap);
void printList(struct DynArr *heap);

/* Task Interface */
struct task createTask(int priority, char *desc);
void printTask(TYPE task);
