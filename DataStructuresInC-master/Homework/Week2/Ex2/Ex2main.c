/* CS260 - Assignment 2 - EX 2*/
/* Name: Tyler Sustare	
 * Date: 10/10/2015
 * Solution description: uses sorting algo in sort() to sort the contents of an array in main()
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
	desc: sorts numbrs in decending order
	
*/
void sort(int *numbers, int n){
     /*Sort the array according to value in ascending order*/
}

int main(){
    /*Declare an integer n and assign it the value 20.*/
	int n = 20;
    /*Allocate memory for n integers using malloc.*/
	int* myArr = malloc(n * sizeof(int));
    /*Generate random integers for the array, using rand().*/
	int i;
	srand(time(NULL));
	for (i = 0; i < n; i++){
		myArr[i] = rand();
	}
	for (i = 0; i < n; i++){
	printf("myArr[%d]: %d\n", i, myArr[i]);
	}
    /*Print the contents of the array.*/

    /*Pass this array along with n to the sort() function*/

    /*Print the contents of the sorted array.*/

    return 0;
}
