/* CS260 - Assignment 2 - EX 1*/
/* Name: Tyler Sustare
 * Date: 10/9/15
 * Solution description: main() converts a c-style string to StUdLy case
 */

#include <stdio.h>
#include <stdlib.h>

/*
	Desc: converts ch to upper case
	Precondition: ch is a lower case char (a-z).
	Postcondition: ch is return as upper case.
*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*
	Desc: converts ch to lower case
	Precondition: ch is a upper case char (a-z).
	Postcondition: ch is return as lower case.
*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

/*
    Desc: convert a char array to StUdLy case. Side effect of void function, no return.
    Precondition: word is a character array of letters, case does not matter (a-z and A-Z)
    Postcondition: char array word is modified inside the function to StUdLy case.
*/
void studly(char* word){
     /*Convert to studly caps
	 It is safe to assume that he string is terminated by '\0'*/
    int i;
	 for (i = 0; word[i]!='\0'; ++i){
        if (i%2 == 0){
            if (word[i] >= 65 && word[i] <= 90){
                //word[i] += 32; // make lower case
            }
            else if (word[i] >= 97 && word[i] <= 123){
                word[i] -= 32; // make upper case
            }
        }
        else {
            if (word[i] >= 65 && word[i] <= 90){
                word[i] += 32;// make lower case
            }
            else if (word[i] >= 97 && word[i] <= 123){
                //word[i] -= 32; // make upper case
            }
        }
	 }
}

int main(){
    /*Read word from the keyboard using scanf
	Max length 100 characters including strung terminator*/
    char* input;
    input = malloc(100*sizeof(char));
    scanf("%s", input);
    /*Call studly*/
    studly(input);
    /*Print the new word*/
    printf("Studly cased: %s \n", input);
    free(input);
    return 0;
}
