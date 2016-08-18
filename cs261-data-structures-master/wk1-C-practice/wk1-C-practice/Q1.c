/* CS261- Assignment 1 - Q.1*/
/* Name: George T Sustare
* Date: 1/7/2016
* Solution description: More practice of C language. Dynamic memory and such.
*/

#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student {
	int id;
	int score;
};

/*********************************************************************   
** Function:  allocate() 
** Description:  Allocates memory on the heap for student* array
** Parameters:   N/A
** Pre-Conditions: N/A 
** Post-Conditions:  Allocated memory on the heap for 10 students
*********************************************************************/
struct student* allocate() {
	/*Allocate memory for ten students*/
	struct student *allocateStudent = malloc(10 * sizeof(struct student));
	/*return the pointer*/
	return allocateStudent;
}

/*********************************************************************   
** Function:  generate() 
** Description: Generates 10 random values for student IDs and scores. 
**		IDs are unique
** Parameters:  valid student array. 
** Pre-Conditions:  student pointer is not NULL
** Post-Conditions:  student array has random values for ID and scores 
*********************************************************************/
void generate(struct student* students) {
	/*Generate random ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
	int i = 0;
	int j = 0;
	for (i; i < 10; ++i) {
		students[i].id = 1 + (rand() % 10);
		students[i].score = (rand() % 101);
		if (i > 0) {
			for (j = 0; j < i; ++j) {
				if (students[i].id == students[j].id){
					i--;			// start loop again until unique ID
				}
			}
		}
	}
}

/*********************************************************************   
** Function:  output() 
** Description:  Prints the student array
** Parameters:   array of students
** Pre-Conditions:  pointer is not to NULL
** Post-Conditions:  N/A. Array is printed
*********************************************************************/
void output(struct student* students) {
	/*Output information about the ten students in the format:
	ID1 Score1
	ID2 score2
	ID3 score3
	...
	ID10 score10*/
	int i = 0;
	for (i; i < 10; ++i) {
		printf("ID: %d Score: %d \n", students[i].id, students[i].score);
	}
}

/*********************************************************************   
** Function:   summary()
** Description:  compute and print min, max and average score of students
** Parameters:   array of students
** Pre-Conditions: array is not empty / pointer is not NULL 
** Post-Conditions:  N/A Printed values 
*********************************************************************/
void summary(struct student* students) {
	/*Compute and print the minimum, maximum and average scores of the ten students*/
	int min = students[0].score;	// initial min will be first score
	int max = students[0].score;	// initial max will be first score
	int total = 0;
	int average = 0;
	int i = 0;
	for (i; i < 10; ++i) {
		if (students[i].score < min) {
			min = students[i].score;
		}
		if (students[i].score > max) {
			max = students[i].score;
		}
		total += students[i].score;
	}
	average = total / 10;
	printf("Student min: %d\n", min);
	printf("Student max: %d\n", max);
	printf("Student average: %d\n", average);
}

/*********************************************************************   
** Function:  deallocate() 
** Description:  Deallocates memory on the heap for student array
** Parameters:  Array of students 
** Pre-Conditions: student array must be allocated with mem on heap 
** Post-Conditions:  memory is freed 
*********************************************************************/
void deallocate(struct student* stud) {
	/*Deallocate memory from stud*/
	free(stud);
	stud = NULL;
}

int main_1() {
	struct student* stud = NULL;
	
	/*call allocate*/
	stud = allocate();
	/*call generate*/
	generate(stud);
	/*call output*/
	output(stud);
	/*call summary*/
	summary(stud);
	/*call deallocate*/
	deallocate(stud);
	return 0;
}
