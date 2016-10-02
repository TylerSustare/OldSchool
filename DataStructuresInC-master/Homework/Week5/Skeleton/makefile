default: skipList_main

skipList: skipList.c skipList.h
	gcc -Wall -ansi -c skipList.c

skipList_main: skipList_main.c skipList.o
	gcc -Wall -ansi -o skipList_main skipList.o skipList_main.c

clean:
	rm *.o
