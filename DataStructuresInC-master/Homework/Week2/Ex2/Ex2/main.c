/* CS260 - Assignment 2 - EX 2*/
/* Name: Tyler Sustare
 * Date: 10/10/2015
 * Solution description: uses sorting algo in sort() to sort the contents of an array in main()
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
	desc: sorts numbers in ascending order (smallest to largest)
    precondition: an integer array in any order
    postcondition: an integer array in ascending order starting at location 0
*/

void sort(int *numbers, int n){
     /*Sort the array according to value in ascending order*/
    int temp, j, k;
    for (j = 1; j < n; j++){
        k = j;
        while(k > 0 && numbers[k] < numbers[k-1]){
            temp = numbers[k];
            numbers[k] = numbers[k-1];
            numbers[k-1] = temp;
            k--;
        }
    }
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
		myArr[i] = rand() % 100;
		//myArr[i] = 20-i;
	}
    /*Print the contents of the array.*/
    printf("Pre-sorted Array\n");
    for (i = 0; i < n; i++){
        printf("myArr[%d]: %d\n", i, myArr[i]);
	}
	printf("\n");
    /*Pass this array along with n to the sort() function*/
    sort(myArr, n);
    /*Print the contents of the sorted array.*/
    printf("Post-sorted Array\n");
    for (i = 0; i < n; i++){
        printf("myArr[%d]: %d\n", i, myArr[i]);
	}
    return 0;
}



