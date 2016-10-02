//
//  main.c
//  scanf_example
//
//  Created by Tyler on 9/14/15.
//  Copyright (c) 2015 G. Tyler Sustare. All rights reserved.

#include <stdio.h>

typedef struct{
//typedef struct date{
    int day;
//    int month;
    char month[4]; // ex. Nov with one char for \0
    int year;
}Date;

void printDate(Date d){
    printf("%s/%d/%d\n", d.month, d.day, d.year);
}

int main(int argc, const char * argv[]) {
    printf("scanf() example\n");
    Date dob;
    Date month[31]; // array of Dates for 31 day month
//    scanf("%d %d %d", &dob.day, &dob.month, &dob.year); // need address of operator b/c arg is a pointer. Can be separated by spaces or line breaks
    scanf("%d %s %d", &dob.day, dob.month, &dob.year);
    Date birthday;
    birthday = dob;
    printf("Birthday day = %d\n", birthday.day);
//    printf("Birthday month = %d\n", birthday.month);
    printf("Birthday month = %s\n", birthday.month);
    printf("Birthday year = %d\n", birthday.year);
//    printf("Birthday is on %d/%d/%d\n", birthday.day, birthday.month,birthday.year);
    printf("Birthday is on %d/%s/%d\n", birthday.day, birthday.month,birthday.year);
    typedef char* string;
    string bros = "Dude";   // string like typedef; probably bad practice, but it can be done
    printf("string bros = %s", bros);
    
    return 0;
}
