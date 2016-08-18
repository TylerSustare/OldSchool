/* CS260 - Assignment 2 - EX 3*/
/* Name:
 * Date:
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>

struct person {
	int age;
	char sex;
};

void sort(struct person people, int n) {
	/*Sort the given array number , of length n*/
}

/*This function can be identical to the previous sort function, however it needs to return the total number of comparisons carried out in the sort.
If you want to attempt to optimize the sort, then you are welcome to do so */

int sortAnalysis(struct person people, int n) {
     /*Sort the given array number , of length n
	 Return the number of comparisons required to terminate the algorithm */
}

void display(struct person people, int n) {
     /*Display information about the ten values in the format:
	  Value 1: valueVar
	  ...
	  Value N: valueVar*/
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/

    /*Allocate memory for an array of n integers using malloc.*/

    /*Fill this array with random numbers between 0 and n, using rand().*/

	/*Pass this array along with n to the display() function.*/

    /*Pass this array along with n to the sort() function.*/

    /*Pass this array along with n to the display() function.*/
	
	/*Pass this array along with n to the sortAnalysis() function.*/
	
	/*Display the number of comparisons the function returns.	Did it matter that the array was already sorted? Why? - Display your answer in comments below
	Note - this will depend on your implementation. There is not one answer*/

    return 0;
}


