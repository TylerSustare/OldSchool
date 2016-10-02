#ifndef __LIST_H
#define __LIST_H

# ifndef TYPE
# define TYPE int
# define TYPE_SIZE sizeof(int)
# endif

/*Structure for a link/node in the list*/
struct DLink{
	TYPE value; /*Value of the link*/
	struct DLink* next; /*Ptr to next link*/
	struct DLink* prev; /*Ptr to prev link*/
};

/*Structure for the list*/
struct list{
	struct DLink* head; /*Head sentinel of the list*/
};

/*Structure for the bag - just a wrapper - so that you can pass a bag pointer to the bag functions*/
struct bag{
	struct list *lst;/*List that implements the bag*/
	int size;
};

/*Linked list with 2 sentinels*/
void initList(struct list *lst);
int isEmptyList(struct DLink *head);
void addBackListRecursive(struct DLink *head, TYPE val);
void addFrontList(struct DLink *head, TYPE val);
TYPE frontList(struct DLink *head);
TYPE backListRecursive(struct DLink *head);
void removeFrontList(struct DLink *head);
void removeBackListRecursive(struct DLink *head);
void displayListRecursive(struct DLink *head);
int listContainsRecursive(struct DLink *head, TYPE e);
void listRemoveRecursive(struct DLink *head, TYPE e);
void freeList(struct list *lst);

/*Bag interface*/
void initBag(struct bag* b);
void addToBag(struct bag* b, TYPE val);
void removeFromBag(struct bag* b, TYPE val);
int bagContains(struct bag* b, TYPE val);
int isEmptyBag(struct bag* b);
void freeBag(struct bag *b);

#endif
