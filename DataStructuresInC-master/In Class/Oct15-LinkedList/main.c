#include <stdio.h>
#include <stdlib.h>

#define TYPE double

typedef struct node{
    TYPE value;
    struct node* next;

};

void insertBeg(struct node* head, TYPE x){
    struct node* temp = malloc(sizeof(struct node));
    temp->value = x;
    temp->next = head->next;
    head->next = temp;

    printf("added %f\n", x);
}

void printList(struct node* head){
    struct node* curr = head;
    int i = 0;

    while(curr->next != NULL){
    curr = curr->next;
    printf("Item %d: %f\n", i, curr->value);
    i++;
    }
}

void insertEnd(struct node* head, TYPE x){
    struct node* temp;
    struct node* curr;
    temp = malloc(sizeof(struct node));
    curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    temp->value = x;
    temp->next = NULL;
    curr->next = temp;

    printf("Inserted %f to end\n", x);
}

void insertAtIndex(struct node* head, TYPE x, int pos){
    struct node* temp, *curr;
    temp = malloc(sizeof(struct node));
    curr = head;
    int i = 0;
    if (pos!=-1){
        while (i < pos && curr->next != NULL){
            curr = curr->next;
            ++i;
        }
    }
    else {
        while(curr->next != NULL){
            curr = curr->next;
        }
    }
    temp->next = curr->next;
    curr->next = temp;
    temp->value = x;

    printf("inserted %f, at pos %d\n", x, i);
}

void deleteAtIndex(struct node* head, int pos){
    struct node* curr = head;
    struct node* next;
    int i = 0;
    while(i<pos && curr->next != NULL){
        curr = curr->next;
        ++i;
    }
    next = curr->next;
    curr->next = curr->next->next;
    free(next);

    printf("deleted at %d \n", pos);
}

int main()
{
    struct node* head = 0;
    head = malloc(sizeof(struct node));
    head->next = NULL;

    insertBeg(head, 5);
    insertBeg(head, 9);
    insertBeg(head, 33);

    insertEnd(head, 100);

    insertAtIndex(head, 6, 0);
    insertAtIndex(head, 44, 8);

    printList(head);

    deleteAtIndex(head, 0);
    deleteAtIndex(head, 2);

    printList(head);


    return 0;
}
