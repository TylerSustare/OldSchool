/* CS261- Assignment 1 - Q.5*/
/* Name: George Sustare
* Date: 1/9/2016
* Solution description: Convert strings to StIcKy CaPs strings. 
*	Meaning every other letter is a capital one. 
*/

#include <stdio.h>
#include <stdlib.h>

/*Helper function provided by assignment*/
/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch) {
	return ch - 'a' + 'A';
}

/*Helper function provided by assignment*/
/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch) {
	return ch - 'A' + 'a';
}

/*********************************************************************   
** Function:  sticky() 
** Description: Converts char array to StIcKy caps. Every other char
	is capitol. 
** Parameters: character array  
** Pre-Conditions: Valid character array 
** Post-Conditions:  char array has sticky caps as a side effect 
	of the function.
*********************************************************************/
void sticky(char* word) {
	/*Convert to sticky caps*/
	int i;
	for (i = 0; word[i] != '\0'; ++i) {
		if (i % 2 == 0) {
			if (word[i] >= 65 && word[i] <= 90) {
				//word[i] += 32; // make lower case
			}
			else if (word[i] >= 97 && word[i] <= 123) {
				word[i] -= 32; // make upper case
			}
		}
		else {
			if (word[i] >= 65 && word[i] <= 90) {
				word[i] += 32;// make lower case
			}
			else if (word[i] >= 97 && word[i] <= 123) {
				//word[i] -= 32; // make upper case
			}
		}
	}
}

int main() {
	/*Read word from the keyboard using scanf*/
	char *input;
	input = malloc(100 * sizeof(char));
	scanf("%s", input);
	/*Call sticky*/
	sticky(input);
	/*Print the new word*/
	printf("With sticky case: %s \n", input);
	free(input);
	return 0;
}
