//
//  main.c
//  Sept29
//
//  Created by Tyler on 9/29/15.
//  Copyright © 2015 Tyler. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
// intro to the class with Kenny
    
    char myString[10] = "Steve";
    int i;
    for (i = 0; i < 10; i++){
        if (myString[i] == '\0'){
            // myString[i] = 'B';
        }
        printf("%d: %c \n", i, myString[i]);
    }
    return 0;
}
