/* CS260 - Assignment 2 - EX 3*/
/* Name: Tyler Sustare
 * Date: 10/10/2015
 * Solution description: Meeting
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct person {
	int age;
	char sex;
};

void sort(struct person* people, int n) {
	/*Sort the given array of people by age, of length n*/
	int t, i, j;
	for (i = 1; i < n; ++i){
        j=i;
        while (j>0 && people[j].age < people[j-1].age){
            t = people[j].age;
            people[j].age = people[j-1].age;
            people[j-1].age = t;
            j--;
        }
	}
}

/*This function can be identical to the previous sort function, however it needs to return the total number of comparisons carried out in the sort.
If you want to attempt to optimize the sort, then you are welcome to do so */

int sortAnalysis(struct person* people, int n) {
     /*Sort the given array of persons of length n
	 Return the number of comparisons required to terminate the algorithm */
    int t, i, j,comp;
	comp = 0;
	for (i = 1; i < n; ++i){
        comp++;
        j=i;
        while (j>0 && people[j].age < people[j-1].age){
            t = people[j].age;
            people[j].age = people[j-1].age;
            people[j-1].age = t;
            j--;
            comp++;

        }
	}
    return comp;
}

void display(struct person* people, int n) {
     /*Display information about the ten people in the format:
	  Person 1: Age: X, Gender: Y
	  ...
	  Person N: Age: X, Gender: Y
      */
      int i;
      for (i = 0; i<n; ++i){
        printf("Person %d: Age: %d, Gender %c\n", i+1, people[i].age, people[i].sex);
      }
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;
    /*Allocate memory for an array of n persons using malloc.*/
    struct person* people;
    people = malloc(n*sizeof(struct person));
    /*Fill this array with random persons with ages between 18 and 90 and random genders, using rand().*/
    srand(time(NULL));
    int i, gender, comparisons;
    comparisons = 0;
    for (i = 0; i < n; ++i){
        people[i].age = rand()%100;
        gender = rand()%2;
        if (gender == 1){
            people[i].sex = 'M';
        }
        if (gender == 0){
            people[i].sex = 'F';
        }
    }
	/*Pass this array along with n to the display() function.*/
	printf("Initial values of person array\n");
    display(people, n);
    printf("\n");
    /*Pass this array along with n to the sort() function.*/
    sort(people, n);
    /*Pass this array along with n to the display() function.*/
    printf("Sorted values of person array\n");
    display(people, n);
    printf("\n");
	/*Pass this array along with n to the sortAnalysis() function.*/
	comparisons = sortAnalysis(people, n);
	/*Display the number of comparisons the function returns.	Did it matter that the array was already sorted? Why? - Display your answer in comments below
	Note - this will depend on your implementation. There is not one answer*/
    printf("Number of comparisons = %d\n", comparisons);
    return 0;
}

/*
    It does matter if the array was already sorted because the while loop quit much earlier if the section that was sorted (behind the wall)
    When the list was unsorted, there were about 110 comparisons, when it was sorted, there were only 19, comparing each one to the previous one.
*/
