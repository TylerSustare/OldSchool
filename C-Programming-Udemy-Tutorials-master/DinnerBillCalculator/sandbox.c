/* Sandbox C file to check out different thigs before adding them to the main.c */

#include <stdio.h>
#include <stdlib.h>

typedef struct guest{
	int order;
	double tab;
	char* name;
}Guest;

Guest guest_list[3]; 

// allocates new memory on heap to return a char* string
char* change_name(){
	char* name = malloc(30);
	name[0] = 0; 	// needed when allocating new memory
	fgets(name, 30, stdin);
	rewind(stdin);
	return name;
}
// uses a fixed location array to pass back a char* string. 
char* change_name_2(char new_name[]){
	// does not need malloc. the array is at a fixed location in memory with []
	fgets(new_name, 30, stdin);
	rewind(stdin);
	return new_name;
}
// passes in an argument with a pointer, not by value
int pass_by_point(int* i){
	*i+=2;
	return (*i);
}

int change_order(){
    printf("Order #: ");
    int order = 0;
    char* s_order = malloc(30);
    s_order[0] = 0; 	// needed when allocating new memory
    fgets(s_order, 30, stdin);
    order = atoi(s_order);
    rewind(stdin);
    return order;
}

int number_from_struct(Guest g){
    return g.order;
}

int main_x(int argc, char** argv){
	int i;
    for (i = 0; i < 3; ++i){
        guest_list[i].name = change_name();
        guest_list[i].order = change_order();
        
    }
	int j;
    for (j = 0; j < 3; ++j){
        printf("Name is %s\n", guest_list[j].name);
        printf("Order is %d\n", guest_list[j].order);
    }
     
	/*
	int i = 2;
	int ip = &i;
	pass_by_point(ip);
	printf("value is %d\n", i);
	*/
	 
	/*	Illustrating pointers & thier values
	int x = 10;
	int* xp = &x;
	printf("Value of x is \t\t\t %d\n", x);
	printf("Value of xp is \t\t\t %x\n", xp);
	printf("Value xp is pointing to is \t %d\n", *xp);
	*/
	
	/*  Playing with pointers and returning strings
	char* birth_name;
	birth_name = change_name();
	printf("your name is %s\n", birth_name);
	char renamed[30];
	change_name_2(renamed);
	birth_name = renamed;		// birth_name can be reassigned to renamed b/c its a pointer
	printf("changed to %s\n", birth_name);
	*/
	return 0;
}