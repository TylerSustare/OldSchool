/* CS261- Assignment 1 - Q.3*/
/* Name: George Sustare	
* Date:	1/7/2016
* Solution description: To get super good at sorting. Woo hoo!!
*/

#include <stdio.h>

/*********************************************************************   
** Function:  sort() 
** Description: uses insertion sort to sort integer array  
** Parameters:  
	1) integer array
	2) integer representing the length of the array
** Pre-Conditions:  int array is valid / not NULL. integer is positive
** Post-Conditions:  int array is sorted in ascending order. 
*********************************************************************/
void sort_3(int* number, int n) {
	/*Sort the given array number , of length n*/
	int i = 0;
	int j, temp;
	for (i = 1; i < n; ++i) {
		temp = number[i];
		j = i - 1;
		while ((temp < number[j]) && (j >= 0)) {
			number[j + 1] = number[j];
			j -= 1;
		}
		number[j + 1] = temp;
	}
}

int main_3() {
	/*Declare an integer n and assign it a value of 20.*/
	int n = 20;
	/*Allocate memory for an array of n integers using malloc.*/
	int *myArray = malloc(n * sizeof(int));
	/*Fill this array with random numbers, using rand().*/
	int i = 0;
	for (i; i < n; ++i) {
		myArray[i] = rand();
	}
	/*Print the contents of the array.*/
	for (i = 0; i < n; ++i) {
		printf("myArray[%d] = %d\n", i, myArray[i]);
	}
	/*Pass this array along with n to the sort() function of part a.*/
	sort(myArray, n);
	/*Print the contents of the array.*/
	printf("Post sorting:\n");
	for (i = 0; i < n; ++i) {
		printf("myArray[%d] = %d\n", i, myArray[i]);
	}
	return 0;
}
