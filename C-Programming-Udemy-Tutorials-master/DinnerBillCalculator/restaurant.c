#include <stdio.h>
#include <stdlib.h>
#include "restaurant.h"

// gets the name of the restaurant using fgets()
char* get_restaurant(char* restaurant){
	printf("What restaurant are you going to? ");
	fgets(restaurant, 10, stdin);
	rewind(stdin);	// flushes the buffer on Windows.
	return restaurant;
}
