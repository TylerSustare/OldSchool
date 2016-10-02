#include "listbag.h"
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

int main() {


	struct list *lst = malloc(sizeof(struct list));
	initList(lst);
	printf("Initialized List \n");

    addFrontList(lst->head, 3);
    addFrontList(lst->head, 2);
    addFrontList(lst->head, 1);

    /* Should display 1, 2, 3 */
    displayListRecursive(lst->head);

    addBackListRecursive(lst->head, 4);
    addBackListRecursive(lst->head, 5);

    /* Should display 1, 2, 3, 4, 5*/
    displayListRecursive(lst->head);

    /* Should display Front: 1 Back: 5 */
    printf("Front: %d Back: %d \n", frontList(lst->head), backListRecursive(lst->head));

    removeFrontList(lst->head);
    /* Should display Front: 2 Back: 5 */
    printf("Front: %d Back: %d \n", frontList(lst->head), backListRecursive(lst->head));

    removeBackListRecursive(lst->head);
    /* Should display 2, 3, 4*/
    displayListRecursive(lst->head);

    printf("Result of listContainsRecursive(3): %d \n", listContainsRecursive(lst->head, 3));
    printf("Result of listContainsRecursive(5): %d \n", listContainsRecursive(lst->head, 5));

    displayListRecursive(lst->head);

    free(lst->head);

	/* Test your bag implementation */



	return 0;
}
