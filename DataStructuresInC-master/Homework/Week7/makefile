default: main_heap

dynamicArray: dynamicArray.c dynamicArray.h
	gcc -Wall -ansi -c dynamicArray.c

main_heap: main_heap.c dynamicArray.o
	gcc -Wall -ansi -o main_heap dynamicArray.o main_heap.c

clean:
	rm *.o

