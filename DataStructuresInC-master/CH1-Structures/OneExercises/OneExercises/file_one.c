//
//  file_one.c
//  OneExercises
//
//  Created by Tyler on 9/15/15.
//  Copyright (c) 2015 G. Tyler Sustare. All rights reserved.
//

#include "file_one.h"

char* getString(FILE* in, char* str){
    int i = 0;
    char tempC;
    int quotes = 0;
//    do{
    while(quotes < 2){
        tempC = fgetc(in);
        if (tempC != '"'){
            str[i] = tempC;
        }else{
            quotes++;
        }
        ++i;
    }
//    }while (str[i] != '\0');
    str[i-1] = '\0';
    return str;
}

void getStringv2(FILE* in, char* str){
    rewind(in);
    char tempS[31];
//    char string[31];
    int i = 0;
    int j = 0;
    fgets(tempS, 31, in);
    while(tempS[i] != '\n'){
        if (tempS[i] >= 64 && tempS[i] <= 122){
            str[j] = tempS[i];
            ++j;
        }
        ++i;
    }
//    printf("%s", str);
//    return string;
}

char readChar(FILE* in){
    char c;
    if(c != ' ')c = getc(in);
    return c;
}