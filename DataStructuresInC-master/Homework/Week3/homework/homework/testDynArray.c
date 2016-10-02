/* testDynArray.c
 * This file is used for testing the dynamicArray.c file.
 * This test suite is by no means complete or thorough.
 * More testing is needed on your own.
 */
#include <stdio.h>
#include <stdlib.h>
#include "dynamicArray.h"


void assertTrue(int predicate, char *message) {
    printf("%s: ", message);
    if (predicate)
        printf("Pass \n");
    else
        printf("Fail \n");
}


// this main function contains some
int _main2(int argc, char* argv[]){
    DynArr *dyn;
    dyn = createDynArr(2);
    
    printf("Testing addDynArr... \n");
    addDynArr(dyn, 5);
    addDynArr(dyn, 8);
    addDynArr(dyn, 10);
    addDynArr(dyn, 12);
    addDynArr(dyn, 3);
    
    printf("The array's contents: [5, 8, 10 , 12, 3] \n");
    assertTrue(EQ(getDynArr(dyn, 0), 5), "Test 0th element == 5");
    assertTrue(EQ(getDynArr(dyn, 1), 8), "Test 1st element == 8");
    assertTrue(EQ(getDynArr(dyn, 2), 10), "Test 2nd element == 10");
    assertTrue(EQ(getDynArr(dyn, 3), 12), "Test 3rd element == 12");
    assertTrue(EQ(getDynArr(dyn, 4), 3), "Test 4th element == 3");
    assertTrue(sizeDynArr(dyn) == 5, "Test size = 5");
    
    
    printf("Testing putDynArr...\n Calling putDynArr(dyn, 2, 7) \n");
    putDynArr(dyn, 2, 7);
    printf("The array's content: [5, 8, 7, 12, 3] \n");
    assertTrue(EQ(getDynArr(dyn, 2), 7), "Test 2nd element == 7");
    assertTrue(sizeDynArr(dyn) == 5, "Test size = 5");
    
    printf("Testing swapDynArr...\n Calling swapDynArr(dyn, 1, 3) \n");
    swapDynArr(dyn, 1, 3);
    printf("The array's content: [5, 12, 7, 8, 3] \n");
    assertTrue(EQ(getDynArr(dyn, 2), 7), "Test 2nd element == 7");
    assertTrue(EQ(getDynArr(dyn, 4), 3), "Test 4th element == 3");
    
    printf("Testing removeAtDynArr...\n Calling removeAtDynArr(dyn, 1) \n");
    removeAtDynArr(dyn, 1);
    printf("The array's content: [5, 7, 8, 3] \n");
    assertTrue(EQ(getDynArr(dyn, 0), 5), "Test 0th element == 5");
    assertTrue(EQ(getDynArr(dyn, 3), 3), "Test 3rd element == 3");
    assertTrue(sizeDynArr(dyn) == 4, "Test size = 4");
    
    printf("Testing stack interface... \n");
    printf("The stack's content: [5, 7, 8, 3] <- top \n");
    assertTrue(!isEmptyDynArr(dyn), "Testing isEmptyDynArr");
    assertTrue(EQ(peekDynArr(dyn), 3), "Test peekDynArr == 3");
    
    popDynArr(dyn);
    printf("Popping...\n The stack's content: [5, 7, 8] <- top \n");
    assertTrue(EQ(peekDynArr(dyn), 8), "Test peekDynArr == 8");
    
    pushDynArr(dyn, 10);
    printf("Pushing 10...\n The stack's content: [5, 7, 8, 10] <- top \n");
    assertTrue(EQ(peekDynArr(dyn), 10), "Test peekDynArr == 10");
    
    printf("Testing bag interface... \n");
    printf("The bag's content: [5, 7, 8, 10]\n");
    assertTrue(containsDynArr(dyn, 5), "Test containing 5");
    assertTrue(containsDynArr(dyn, 7), "Test containing 7");
    assertTrue(containsDynArr(dyn, 8), "Test containing 8");
    assertTrue(containsDynArr(dyn, 10), "Test containing 10");
    assertTrue(!containsDynArr(dyn, 6), "Test not containing 6");
    
    removeDynArr(dyn, 2);
    printf("Removing 2...\n The stack's content: [5, 7, 10] \n");
    assertTrue(!containsDynArr(dyn, 3), "Test not containing 3");
    
    return 0;
}
