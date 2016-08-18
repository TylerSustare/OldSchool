//
//  main.c
//  Oct1
//
//  Created by Tyler on 10/1/15.
//  Copyright © 2015 Tyler. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <string.h>

typedef struct{
    int age;
    char species[31];
}Animal;

void dispAnimal(Animal a){
    printf("Animal species: %s age: %d \n", a.species, a.age);
}

void funky(int* x){
    *x = 25;
}

int main(int argc, const char * argv[]) {
//    int tSeed = time(NULL);
////    srand(tSeed);   // should compile in code::blocks
   
//    Animal fido;
//    fido.age = rand() % 16;
//    strcpy(fido.species, "dog");    // copies string into memory space;
//    dispAnimal(fido);
    
//    int x = 10;
//    int* ptr = &x;
    
//    printf("val of x: %d \n", x);
//    printf("addr of x: %p \n", &x);
//    printf("val of ptr: %p \n", ptr);
//    printf("val ptr points to: %d \n", *ptr);
//    printf("ptr addr: %p \n", &ptr);
//    printf("x as hex: %d \n", x);
   
//    int arr[10] = {4,6,8};
//    printf("address of arr: %p\n", arr);
//    printf("address of arr: %p\n", &arr[0]);
//    printf("address of arr: %p\n", &arr);
//    printf("val of arr[0]: %d\n", arr[0]);
//    printf("address of arr: %d\n", *arr);

//    printf("sizeof(int): %d\n", sizeof(int));

//    int x = 5;
//    funky(&x);
//    printf("x: %d\n", x);

    int *arr = 0;
    arr = malloc(sizeof(int) * 10); // can resize array when using malloc
    arr = realloc(arr, sizeof(int) * 20);
    

    
    return 0;
}
