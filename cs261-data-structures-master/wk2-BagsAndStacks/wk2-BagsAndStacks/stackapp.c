/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
param: 	s pointer to a string
pre: s is not null
*/
char nextChar(char* s)
{
/*s assert(s != 0); will not work unless using <assert.h> but 
 * since we are not allowed to add extra includes I'll use an
 * if()*/ 
	if (s != NULL){
		static int i = -1;
		char c;
		++i;
		c = *(s + i);
		if (c == '\0')
			return '\0';
		else
			return c;
	} 
	else {
		printf("char* cannnot be NULL");
		return -1; 
	}
}

/* Checks whether the (), {}, and [] are balanced or not
param: 	s pointer to a string
pre: s is not null
post: no changes
ret: return 0 if string is not balanced, 1 if balanced
*/
int isBalanced(char* s)
{
	/* FIXME: You will write this function */
	if (s != NULL){
		int i = 0;
		char temp;
		DynArr *dyn;
		dyn = newDynArr(2);
		while (nextChar(s) != '\0') {
			if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
				pushDynArr(dyn, s[i]);
			}if (s[i] == ')') {
				temp = topDynArr(dyn);
				popDynArr(dyn);
				if (temp != '(') {
					return 0;
				}
			}if (s[i] == '}') {
				temp = topDynArr(dyn);
				popDynArr(dyn);
				if (temp != '{') {
					return 0;
				}
			}
			if (s[i] == ']') {
				temp = topDynArr(dyn);
				popDynArr(dyn);
				if (temp != '[') {
					return 0;
				}
			}
			++i;
		}
		if (isEmptyDynArr(dyn) == 0){
			return 0;
		}
	return 1; // passed all tests, string is balanced.
	} else {
		printf("char* cannot be NULL\n"); 	 
		return -1;
	}
}

int main(int argc, char* argv[]) {

	char* s = argv[1];
	int res;

	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n", s);
	else
		printf("The string %s is not balanced\n", s);

	return 0;
}
