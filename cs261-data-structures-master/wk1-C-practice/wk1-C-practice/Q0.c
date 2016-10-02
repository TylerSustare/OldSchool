/* CS261- Assignment 1 - Q. 0*/
/* Name: George T Sustare
* Date: 1/6/2016
* Solution description: Practice with the C language. A small amount of pointer work.
*/

#include <stdio.h>
#include <stdlib.h>

/*********************************************************************   
** Function: fooA
** Description: Prints properties of an integer pointer
** Parameters: integer pointer
** Pre-Conditions: Must be a valid, non NULL pointer to an int
** Post-Conditions: N/A just prints the values
*********************************************************************/
void fooA(int* iptr) {
	/*Print the value pointed to by iptr*/
	printf("val of iptr = %d \n", *iptr);
	/*Print the address pointed to by iptr*/
	printf("address iptr is pointing to = %p \n", iptr);
	/*Print the address of iptr itself*/
	printf("address of the pointer iptr = %p \n", &iptr);
}

int main_0() {
	/*declare an integer x*/
	int x = 0;
	/*print the address of x*/
	printf("address of x = %p \n", &x);
	/*Call fooA() with the address of x*/
	fooA(&x);
	/*print the value of x*/
	printf("value of x = %d \n", x);
	return 0;
}
