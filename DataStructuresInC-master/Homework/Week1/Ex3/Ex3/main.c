/* CS260 - Assignment 1 - EX 3*/
/* Name: Tyler Sustare
 * Date: 10/2/15
 * Solution description: Use an array of structs to get stats on a group of random people.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*Sex: (M)ale or (F)email*/
struct person {
    int age;
    char sex;
};

struct person* allocate();
void generate(struct person* people);
void output(struct person* people);
void stats(struct person* people);
void deallocate(struct person* people);

int main() {
    struct person* people = NULL;
    
    /*call allocate
     set people to the pointer returned by the function call*/
    people = allocate();
    /*call generate*/
    generate(people);
    /*call output*/
    output(people);
    /*call stats*/
    stats(people);
    /*call deallocate*/
    deallocate(people);
    return 0;
}

struct person* allocate() {
    /*Allocate memory for ten persons - use malloc*/
    int personStructSize = (sizeof(char) + sizeof(int));
    struct person* people = malloc(10 * personStructSize);
    /*return the pointer*/
    return people;
}

void generate(struct person* people) {
    /*Generate random age and sex for 10 persons and store in people
     Age is between 18 and 90 - sex is either M or F
     Calculate random numbers between using rand().
     Simply assigning ages 19, 20, 21.. is not sufficient*/
    int seed;
    type_cast<int>seed = time(NULL);
    srand(seed);
    int loopCounter = 0;
    int gender = 0;
    while (loopCounter < 10){
        people[loopCounter].age = 18 + (rand() % 73);
        gender = rand()%2;
        if (gender == 0){
            people[loopCounter].sex = 'M';
        }
        else{
            people[loopCounter].sex = 'F';
        }
        loopCounter++;
    }
    return;
}

void output(struct person* people) {
    /*Output information about the ten persons in the format:
     Person 1: Age: varAge Sex: varSex
     ...
     Person 10: Age: varAge Sex: varSex*/
    int loopCounter = 0;
    while (loopCounter < 10) {
        printf("Person %d: Age: %d Sex: %c\n", loopCounter+1, people[loopCounter].age, people[loopCounter].sex);
        loopCounter++;
    }
    printf("\n");
    return;
}

void stats(struct person* people) {
    /*Compute and print the minimum, maximum and average age of the ten persons*/
    int minAge = people[0].age;
    int maxAge = people[0].age;
    int totalAge = 0;
    int loopCounter = 0;
    while (loopCounter < 10) {
        if (people[loopCounter].age < minAge){
            minAge = people[loopCounter].age;
        }
        if (people[loopCounter].age > maxAge){
            maxAge = people[loopCounter].age;
        }
        totalAge += people[loopCounter].age;
        loopCounter++;
    }

    printf("Max age: %d \n", maxAge);
    printf("Min age: %d \n", minAge);
    printf("Average age: %d \n", totalAge/10);
}

void deallocate(struct person* people) {
    /*Deallocate memory from stud by calling free()*/
    free(people);
}
    
