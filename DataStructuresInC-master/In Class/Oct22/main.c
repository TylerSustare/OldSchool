#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TYPE double



struct node {
    TYPE value;
    struct node *next;
};

struct list {
    struct node *head;
};

/*
    function: initList

*/
void initList(struct list *lst) {
    lst->head = NULL;
}

void pushQ(struct list *lst, TYPE val) {
    struct node *temp = malloc(sizeof(struct node));
    temp->value = val;

    temp->next = lst->head;
    lst->head = temp;
    printf("Pushed: %.1f \n", val);
}

void printQ(struct node* curr){
   if (curr == NULL){
      return;
   }
   printf("val: %.1f \n", curr->value);
   printQ(curr->next);
}

void printQRev(struct node* curr){
   if (curr == NULL){
      return;
   }
   printQRev(curr->next);
   printf("val: %.1f \n", curr->value);

}

int searchQ(struct node* curr, TYPE val){
   if (curr == NULL){
      return 0;
   } else if(curr->value == val){
      return 1;
   }
   return searchQ(curr->next, val);
}

int main() {
    struct list *lst = malloc(sizeof(struct list));
    initList(lst);

    pushQ(lst, 2);
    pushQ(lst, 4);
    pushQ(lst, 6);

    printf("Printing... \n"); // good idea for homework
    printQRev(lst->head);

    printf("result of search 4: %d", searchQ(lst->head, 99));

    return 0;
}





/*
clock_t start, end;
double timeSpent;

double factorial(double num){
   if (num == 1){
      return 1;
   } return num * factorial(num -1);
}

double fibRec(double x){
   if (x == 0){
      return 0;
   }else if (x ==1){
      return 1;
   }
   return fibRec(x -1) + fibRec(x -2);
}

double fibIt(double num){
   if (num <= 1) {return num;}
   double last = 1;
   double curr = 1;
   double next;
   int i = 2;
   while(i < num){
      next = curr + last;
      last = curr;
      curr = next;
      i++;
   }
   return curr;
}

int main()
{
    start = clock();
    printf("10 factorial: %.1f", factorial(10));
    end = clock();
    printf("\n");
    //printf("Fib 11: %.1f", fibRec(11));
    printf("Fib 11: %.1f", fibIt(11));
    timeSpent = (double) end - start;
    printf("that took: %f", timeSpent);
    return 0;
}
*/
