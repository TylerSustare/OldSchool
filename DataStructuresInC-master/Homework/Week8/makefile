default: hash_main

hashMap: hashMap.c hashMap.h
	gcc -Wall -ansi -c hashMap.c

hash_main: hash_main.c hashMap.o
	gcc -Wall -ansi -o hash_main hashMap.o hash_main.c

clean:
	rm *.o

