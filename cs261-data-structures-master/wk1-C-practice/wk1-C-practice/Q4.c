/* CS261- Assignment 1 - Q.4*/
/* Name: George Sustare	
* Date: 1/9/2015
* Solution description: Get even better at sorting! 
*	This time we get to sort structs! Now that's what
*	I'm talking about!
*/

#include <stdio.h>
#include <stdlib.h>

struct student {
	int id;
	int score;
};

/*********************************************************************   
** Function: sort()  
** Description: Sorts student structs using insertion sort 
** Parameters: 
**		1) Pointer to student struct list
**		2) Integer represent size of the list
** Pre-Conditions: student Pointer is not NULL, int is positive  
** Post-Conditions: student list is in ascended sorting order
*********************************************************************/
void sort(struct student* students, int n) {
	/*Sort the n students based on their score*/
	int i = 0;
	int j, temp;
	for (i = 1; i < n; ++i) {
		temp = students[i].score;
		j = i - 1;
		while ((temp < students[j].score) && (j >= 0)) {
			students[j + 1].score = students[j].score;
			j -= 1;
		}
		students[j + 1].score = temp;
	}
}

int main_4() {
	/*Declare an integer n and assign it a value.*/
	int n = 42; // the meaning of life
	/*Allocate memory for n students using malloc.*/
	struct student *ladiesAndGentlemen = malloc(n * sizeof(struct student));
	/*Generate random IDs and scores for the n students, using rand().*/
	int i = 0;
	int j = 0;
	for (i; i < n; ++i) {
		ladiesAndGentlemen[i].id = 1 + (rand() % n);
		ladiesAndGentlemen[i].score = (rand() % 101);
		if (i > 0) {
			for (j = 0; j < i; ++j) {
				if (ladiesAndGentlemen[i].id == ladiesAndGentlemen[j].id){
					i--;			// start loop again until unique ID
				}
			}
		}
	}
	/*Print the contents of the array of n students.*/
	printf("Unsorted\n----------------\n");
	for (i = 0; i < n; ++i) {
		printf("Student %d: Score: %d\n", ladiesAndGentlemen[i].id, ladiesAndGentlemen[i].score);
	}
	/*Pass this array along with n to the sort() function*/
	sort(ladiesAndGentlemen, n);
	/*Print the contents of the array of n students.*/
	printf("Post Sorting\n----------------\n");
	for (i = 0; i < n; ++i) {
		printf("Student %d: Score: %d\n", ladiesAndGentlemen[i].id, ladiesAndGentlemen[i].score);
	}
	return 0;
}
