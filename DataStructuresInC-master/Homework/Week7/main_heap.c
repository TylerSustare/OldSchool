/*
	file: main_heap.c
	Heap test file
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "dynamicArray.h"

/*
    createTask: create a task from the description and the priority
    param: priority - priority of the task
    param: desc - pointer to the description string
    pre: none
    post: none
	return: a task with description and priority
*/
struct task createTask(int priority, char *desc) {
	struct task newTask;
	newTask.priority = priority;
	strcpy(newTask.description, desc);
	return newTask;
}

/*
	printTask: Display the information about the first node in the heap (root)
	param: task - the task to print
	pre: heap is not empty
	post: no changes to the heap
	return: the task priority and description are printed to standard output
	format: "Priority: XX - Description: Ipsum Lorem"
*/
void printTask(TYPE task) {
    /* FIXME */
    printf("Priority: %d - Description: %s \n",task.priority, task.description);
}

int main() {
	printf("================= Starting Program ==================\n");
    struct task task1, task2, task3, task4, task5, task6, task7, task8, task9, task10;
	struct DynArr taskList;
	initDynArr(&taskList, 10);

    /* create tasks */
	task1 = createTask(10, "Clean house");
	task2 = createTask(6, "Eat dinner");
	task3 = createTask(2, "Do laundry");
	task4 = createTask(4, "Do dishes");
	task5 = createTask(5, "Grocery shopping");
	task6 = createTask(7, "Change oil");
	task7 = createTask(13, "Do taxes");
	task8 = createTask(8, "Sleep");
	task9 = createTask(1, "Do other homework");
	task10 = createTask(0, "Finish heap homework");

	/* add tasks to the dynamic array */
	addHeap(&taskList, task1);
	addHeap(&taskList, task2);
	addHeap(&taskList, task3);
	addHeap(&taskList, task4);
	addHeap(&taskList, task5);
	addHeap(&taskList, task6);
	addHeap(&taskList, task7);
	addHeap(&taskList, task8);
	addHeap(&taskList, task9);
	addHeap(&taskList, task10);

	printf("Beginning testing... \n");

    /* Should print: heap size: 10 */
    printf("heap size: %d \n", sizeDynArr(&taskList));

    /* Should print - Priority: 0 - Description: Finish heap homework */
    printTask(getMinHeap(&taskList));

    /* Remove top node from head */
	removeMinHeap(&taskList);

    /* Should print - Priority: 1 - Do other homework */
	printTask(getMinHeap(&taskList));

	int i;
	printf("printing heap... \n");
	/* Should print - 1 2 6 4 5 7 13 10 8 */
	for(i = 0; i <sizeDynArr(&taskList);i++) {
        printf("%d ", getDynArr(&taskList, i).priority);
	}
	printf("\n");

    /* Sort heap */
	sortHeap(&taskList);

    printf("printing sorted heap... \n");
    /* Should print (without descriptions) : 1, 2, 4, 5, 6, 7, 8, 10, 13 */
	for (i = 0; i < taskList.size; i++)	{
	  	printTask(getDynArr(&taskList, i));
	}
    printf("\n");

	return 0;
}
