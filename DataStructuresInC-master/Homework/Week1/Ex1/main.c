/* CS260 - Assignment 1 - EX 1*/
/* Name: Tyler Sustare
 * Date: 10/1/2015
 * Solution description: Declaring integers, pointers and playing with their addresses.
 */

#include <stdio.h>
#include <stdlib.h>

void foo(int* ptr);

int main() {
    /*declare an integer x*/
    int x = 0;
    /*print the address of x*/
    printf("Add. of x: %p\n", &x);
    /*Call foo() with the address of x*/
    foo(&x);
    /*print the value of x*/
    printf("Val. of x: %d\n", x);

    return 0;

}

void foo(int* ptr) {

     /*Print the value pointed to by ptr*/
    printf("Val. pointed to by ptr: %d\n", *ptr);
     /*Print the address pointed to by ptr*/
    printf("Add. pointed to by ptr %p\n", ptr);
     /*Print the address of ptr itself*/
    printf("Add. of ptr: %p\n", (void*)&ptr);
}

