/* CS260 - Assignment 1 - EX 2*/
/* Name: Tyler Sustare
 * Date: 10/2/15
 * Solution description: Pass by value & reference practice
 */

#include <stdio.h>
#include <stdlib.h>

int bar(int* a, int* b, int c){
    /*Set a to double its original value*/
    *a = 2*(*a);
    /*Set b to half its original value*/
    *b = (*b)/2;
    /*Assign a+b to c*/
    c = *a + *b;
    /*Return c*/
    return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 11, 12, & 13 respectively*/
    int x = 11, y = 12, z = 13;
    /*Print the values of x, y and z*/
    printf("x: %d \ny: %d \nz: %d \n", x,y,z);
    /*Call bar() appropriately, passing x,y,z as parameters*/
    bar(&x, &y, z);
    /*Print the value returned by bar from this function call*/
    printf("bar(&x,&y,z): %d \n", bar(&x, &y, z));
    /*Print the values of x, y and z again*/
    printf("New x: %d \nNew y: %d \nNew z: %d \n", x,y,z);
    /*Is the return value different than the value of z?  Why?
     Express your short answer at the bottom of the file as a comment.*/
    return 0;
}

// The return value of bar() is different than the value of z because it was passed by value, not by reference. The values of x and y were changed becasue they were passed by reference by passing the memory addresses to bar()


