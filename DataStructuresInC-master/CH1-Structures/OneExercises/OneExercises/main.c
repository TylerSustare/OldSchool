//
//  main.c
//  OneExercises
//
//  Created by Tyler on 9/15/15.
//  Copyright (c) 2015 G. Tyler Sustare. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "file_one.h"

typedef struct{
    char name[31];
    int age;
    char gender;
}Student;

int main(int argc, const char * argv[]) {
    printf("CHAPTER ONE CODE\nCH1.2 Exercises\n------------------------\n");
    Student pupil[100];
    FILE* in = fopen("/Users/tyler/Documents/DataStructuresInC/CH1-Structures/OneExercises/input.txt", "r"); // "r" means to open it in read mode.
    rewind(in);
//    char* temp = malloc(31);
    int n = 0;
    int j = 0;
    char temp[31];
    for (j; j<31;++j){
        temp[j] = '\0';
    }
    getStringv2(in, temp);
    
    printf("String is %s\n", temp);
    
//    while(strcmp(temp,"END")!=0){
//        strcpy(pupil[n].name, temp);
//        fscanf(in, "%d", &pupil[n].age);
//        pupil[n].gender = readChar(in);
//        n++;
//        getStringv2(in, temp);
//        fclose(in);
//    }
    
    
/*  char testChar;
    while(testChar != EOF){
      testChar = fgetc(in);
      testChar = readChar(in);
      if (testChar == 't') printf("true\n");
      if (testChar == 'e') printf("establishment\n");
    }
    char testString[100];
    getString(in, testString);
    printf("%s", testString);   */
    return 0;
    }
