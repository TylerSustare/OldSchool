/* 	dynamicArray.h : Dynamic Array implementation. */
#include<math.h>

#ifndef DYNAMIC_ARRAY_INCLUDED
#define DYNAMIC_ARRAY_INCLUDED 1


# ifndef TYPE
# define TYPE     double
# define TYPE_SIZE sizeof(double)
# endif

# ifndef EQ
# define EQ(A, B) (fabs(A - B) < 10e-7)
# endif

typedef struct DynArr DynArr;

/* Dynamic Array Functions */
DynArr *createDynArr(int cap);
void deleteDynArr(DynArr *d);

int sizeDynArr(DynArr *d);

void addDynArr(DynArr *d, TYPE val);
TYPE getDynArr(DynArr *d, int pos);
void putDynArr(DynArr *d, int pos, TYPE val);
void swapDynArr(DynArr *d, int i, int  j);
void removeAtDynArr(DynArr *d, int pos);

/* Stack interface. */
int isEmptyDynArr(DynArr *d);
void pushDynArr(DynArr *d, TYPE val);
TYPE peekDynArr(DynArr *d);
void popDynArr(DynArr *d);

/* Bag Interface */
int containsDynArr(DynArr *d, TYPE val);
void removeDynArr(DynArr *d, TYPE val);

#endif
