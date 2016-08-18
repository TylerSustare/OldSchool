/* CS261- Assignment 1 - Q.2*/
/* Name: George Sustare
* Date: 1/7/2016 
* Solution description: More practice with C. Getting more comfortable with return types and such.
*/

#include <stdio.h>
#include <stdlib.h>

/*********************************************************************   
** Function:  foo() 
** Description:  Performs mathematical operations on int and int*
** Parameters:  int pointer, int pointer, int 
** Pre-Conditions:  pointers are not NULL 
** Post-Conditions: side effect changes the value the two int pointers
	are pointing to.
*********************************************************************/
int foo(int* a, int* b, int c) {
	/*Set a to double its original value*/
	*a = (2 * (*a));
	/*Set b to half its original value*/
	*b = ((*b) / 2);
	/*Assign a+b to c*/
	c = *a + *b;
	/*Return c*/
	return c;
}

int main_2() {
	/*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
	int x = 5;
	int y = 6;
	int z = 7;
	/*Print the values of x, y and z*/
	printf("x = %d\n", x);
	printf("y = %d\n", y);
	printf("z = %d\n", z);
	/*Call foo() appropriately, passing x,y,z as parameters*/
	/*Print the value returned by foo*/
	printf("val returned by foo(): %d\n", foo(&x, &y, z));
	/*Print the values of x, y and z again*/
	printf("x = %d\n", x);
	printf("y = %d\n", y);
	printf("z = %d\n", z);
	/*Is the return value different than the value of z?  Why?*/
	/*("Yes, the return value of foo() is different than z
	 *("because z was only passed by value to foo(). It made
	 *("a copy of z but no values were assigned foo() so z
	 *("remains unchanged. x and y were both changed in foo()
	 *("because their addresses were passed in and foo() changed
	 *("their values as a side effect of the function.
	 */
	return 0;
}


