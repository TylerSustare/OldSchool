#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dynamicArray.h"


/* param: s the string
 param: num a pointer to double
 return: 1 (true) if 's' is a number, else return 0 (false).
 postcondition: if 's' is a number, num will hold the value of the number
 */
int isNumber(char *s, double *num) {
    char *end;
    double returnNum;
    
    if(strcmp(s, "0") == 0)	{
        *num = 0;
        return 1;
    }
    else {
        returnNum = strtod(s, &end);
        /* If there's anything in end, it is bad */
        if((returnNum != 0.0) && (strcmp(end, "") == 0)) {
            *num = returnNum;
            return 1;
        }
    }
    return 0;  /*return 0 indicates it was not a number*/
}

/*	param: stack is the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and their sum is pushed back onto the stack.
 */
void add (struct DynArr *stack) {
    /* FIXME: You will write this function */
    double x, y, z;
    x = peekDynArr(stack);
    popDynArr(stack);
    y = peekDynArr(stack);
    z = x + y;
    pushDynArr(stack, z);
}

/*	param: stack is the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and their difference is pushed back onto the stack.
 */
void subtract(struct DynArr *stack) {
    /* FIXME: You will write this function */
    double x, y, z;
    x = peekDynArr(stack);
    popDynArr(stack);
    y = peekDynArr(stack);
    z = x - y;
    pushDynArr(stack, z);
}

/*	param: stack is the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and their quotient is pushed back onto the stack.
 */
void divide(struct DynArr *stack) {
    /* FIXME: You will write this function */
    double x, y, z;
    x = peekDynArr(stack);
    popDynArr(stack);
    y = peekDynArr(stack);
    z = x * y;
    pushDynArr(stack, z);
}

/* Read the RPN string and carry out the operations
	param: 	numInputTokens is the number of tokens entered via command line
	param: 	inputString is the string of tokens
	pre:	inputString is a valid string of Reverse polish Notation - supported operators +, -, x, /
	pre:	numInputTokens is > 0
	post:	none
	ret:	the size of the dynamic array
 */
double calculate(int numInputTokens, char **inputString) {
    double result = 0.0;
    char *s;
    struct DynArr *stack;
    double* dp;
    /*set up the stack */
    stack = createDynArr(20);
    
    int i;
    
    /* start at 1 to skip the name of the calculator calc */
    for(i=1; i < numInputTokens; i++) {
        s = inputString[i];
        
        /* General algorithm:
         1) Check if the string 's' is in the list of operators
         1 a) If 's' is an operator, then call the corresponding function
         1 b) If 's' is not an operator, check if it is a number
         2 a) If 's' is not a number, produce an error
         2 b) If 's' is a number, push it onto the stack */
        
        if(strcmp(s, "+") == 0)
            add(stack);
        else if(strcmp(s,"-") == 0)
            subtract(stack);
        else if(strcmp(s, "/") == 0)
        /* FIXME: replace printf with your own function */
            printf("Dividing\n");
        else if(strcmp(s, "x") == 0)
        /* FIXME: replace printf with your own function */
            printf("Multiplying\n");
        else if(strcmp(s, "^") == 0)
        /* FIXME: replace printf with your own function */
            printf("Power\n");
        else if (isNumber(s, dp)) {
            pushDynArr(stack, atof(s));
        }
        else{// not a number or operator, must be garbage
            /* FIXME: You need to develop the code here (when s is not an operator )*/
            printf("Bad input, try again\n");
        }
    }	//end for
    
    /* FIXME: You will write this part of the function
     If the stack looks OK, then store the final value in result
     Print the result */
    result = peekDynArr(stack);
    return result;
}

/*
	This program relies on command line input
	Assume each argument is contained in the argv array
	argc-1 determines the number of operands + operators
 */
int main(int argc , char** argv) {
    if (argc == 1) {
        return 0;
    }
    
    calculate(argc, argv);
    return 0;
}

/* A few test cases:
 1 2 + 3 x
 should display 9
 
 1 2 + 4 x 5 + 3 −
 should display 14 */
