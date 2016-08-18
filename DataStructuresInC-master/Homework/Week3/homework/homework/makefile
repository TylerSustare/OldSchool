default : all

CFLAGS=-std=c99 -lm

calc : dynamicArray.o
    	gcc -std=c99 -Wall -o calc dynamicArray.o

testDynArray : dynamicArray.o
    	gcc -std=c99 -Wall -o testDynArray dynamicArray.o

dynamicArray.o : dynamicArray.c dynamicArray.h
    	gcc -std=c99 -Wall dynamicArray.c

all : testDynArray calc

clean :
	rm testDynArray calc dynamicArray.o
