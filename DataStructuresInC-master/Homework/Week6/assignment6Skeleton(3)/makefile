default: main

bst: bst.c bst.h
	gcc -Wall -ansi -c bst.c

main: main.c bst.o
	gcc -Wall -ansi -o main bst.o main.c

clean:
	rm *.o

