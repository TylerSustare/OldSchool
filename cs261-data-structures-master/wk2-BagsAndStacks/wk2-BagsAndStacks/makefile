all: prog

prog: dynamicArray.o stackapp.o
	gcc -g -Wall -std=c99 -o prog dynamicArray.o stackapp.o

stackapp.o: stackapp.c dynArray.h
	gcc -g -Wall -std=c99 -c stackapp.c

dynamicArray.o: dynamicArray.c dynArray.h 
	gcc -g -Wall -std=c99 -c dynamicArray.c	
		
clean:
	rm dynamicArray.o
	rm stackapp.o
	rm prog
