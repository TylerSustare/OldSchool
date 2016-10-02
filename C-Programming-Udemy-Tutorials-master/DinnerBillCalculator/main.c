/*	G Tyler Sustare
 * 'C' Programming basics. Used as a reference for 
 * Data Structures class at OSU. Concepts will be based
 * on "C Programming for Beginners" Udemy course tutorial
 * concepts. 
 */
 
 /* Simple dinner Calc */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct guest{
	int order;
	double subtotal;
	char* name;
}Guest;

// enum for get 
enum menu_options{
	steak = 1, burger, bacon
};

char* global_name_array[10];
Guest global_guest_list[10];

/* funciton to get subtotal of order. takes the number for the order 
 in restaurant_menu() function and returns how much the item is 
 worth. (Could possibly be used as encapsilation without Classes
 also could be used if menu items change price */
double get_subtotal(int order, int i){
	double subtotal; // replaced with struct Guest memeber variable
	switch(order){
		case steak:
//		subtotal = 15;
		global_guest_list[i].subtotal = 15;
			break;
		case burger:
//			subtotal = 13;
			global_guest_list[i].subtotal = 13;
			break;
		case bacon:
//			subtotal = 9;
			global_guest_list[i].subtotal = 9;
			break;
		default: 
			printf("Invalid menu choice.");
//			subtotal = 0;
			global_guest_list[i].subtotal = 0;
			break;		// unneccesary break, but good practice
		}
//		printf("Subtotal is $%3.2f", subtotal);
	return global_guest_list[i].subtotal;
}

// menu funciton to order from when calculating total
int restaurant_menu(){
	const int MENU_OPTIONS = 3;
	char s_choice[2];
	int choice = -1;
	int i = 1;
	int subtotal = 0;
	int party = get_party();
	printf("\nPlease enter the numebr of the item you wish to order.\n");
	printf("1. Steak & Potatoes\t $15\n");
	printf("2. Burger  & Fries\t $13\n");
	printf("3. Bacon & Eggs\t $9\n\n");
//	for (;i <= party; ++i){
	while (i <= party){
//		printf("%s, what would you like?\n", global_name_array[i]);
		printf("%s, what would you like?\n", global_guest_list[i].name);
		fgets(s_choice, 2, stdin);
		rewind(stdin);
		choice = atoi(s_choice);
		global_guest_list[i].order = choice;
		if (choice >0 && choice <= MENU_OPTIONS){
		subtotal += get_subtotal(choice,i); // calls get_subtotal() function for price parsing
		++i;
		}else{	// user did not choose a correct menu option
		/* code below was used when the program bailed on invalid input. 
		 * Now it will not accept invalid input
//		subtotal = 0;	// assign zero so main() check will say invalid input
//		break;	// breaks out of the for loop when an invalid selection is made 
//		continue;
		 */ 
		}
	}
	return subtotal;
}
  
// calculates the total bill including tax
double total_bill(double bill, const double TAX_RATE) {
         return bill + (bill*TAX_RATE);
}

//	calculates total tip of dinner
double total_tip(double total, const double TIP_RATE){
	return total * TIP_RATE;
}

// rewind() funciton substitute.
// buffer flushes without rewind()
void flush_input(){	
	int ch;
	while((ch = getchar()) != '\n' && ch != EOF);
	// problem with function: When used with the command line,
	// the enter key must be pushed twice
}

/*	uses the fgets() and rewind() functions that are not as reliable, 
 *	function works, but we can make it better in the next read_line() */
 int readLine(char s[], int maxlen){
	int len_s;
	fgets(s, maxlen, stdin);
	len_s = strlen(s);	// strlen() standard funciton to get the length of a string
	if (s[len_s - 1] == '\n'){
		s[len_s - 1] = '\0';
		len_s -= 1;
	}
	rewind(stdin); // rewind() flushes keyboard buffer (On Windows)
	return len_s;
}

// takes no args. gets tab with fgets() and returns the tab. 
double get_tab(){
	char s_tab[10];
	double tab;
	printf("Enter how much dinner will cost: ");
	//gets(s_tab);	// gets an input in the form of a c-string
	fgets(s_tab, 10, stdin); // fgets() is much safer to get a string than gets()
								// however it does not empty the buffer
	rewind(stdin); // flushes the buffer on Windows machines
								
	//tab = atoi(s_tab);	// atoi() coverts string to int value
	tab = atof(s_tab); // atof() converts c-string to floating point
	printf("%.2f\n", tab);
	return tab;
}

// gets a string without fgets() and rewind()
// does not return anything. Funciton changes the char array
void get_string(char* s, int maxlen){
	char ch; 
	int i = 0;
	int chars_remain = 1;
	while(chars_remain){
		ch = getchar(); // gets character from the command line. 
		if ((ch == '\n') || (ch == EOF)){
			chars_remain = 0;
		}else if(i < maxlen - 1){
			s[i] = ch;
			++i;
		}
	}
	s[i] = '\0';
	return;
}

// Checks if the total of the dinner ia over $100
void check_total(const double x){
	if (x > 100){
		printf("WOW, that's a lot to spend on dinner!\n");
	}
}

// uses get_party() function to get number of guests
// returns names of the people in the party $$$ Uses malloc $$$
char* get_names(int i){
	const int MAX_LEN = 50;
	char* s; 
	s = malloc(MAX_LEN);	// malloc() allocates memory on the heap. Used to keep the string global
	s[0] = 0;		// needed to initialize the buffer for malloc heap memory allocation
	printf("What is the name of the %d person in your party?\n", i);
	get_string(s, MAX_LEN);
	return s;
}

// takes no args. gets the number of guests for dinner. returns the number of guests
int get_party(){
	char s_party[3];
	int party = -1;
	printf("How many people in your party?\n");
	fgets(s_party, 3, stdin);
	party = atoi(s_party);
	rewind(stdin);
	int i;
	for(i = 1; i <= party; ++i){
//		global_name_array[i] = get_names(i);
		global_guest_list[i].name = get_names(i);
	}
	return party;
}


int main(int argc, char **argv){
	rewind(stdin);
    FILE* out = fopen("/Users/tyler/Documents/C-Programming-Udemy-Tutorials/DinnerBillCalculator/output.txt", "w");
    
	char restaurant[30];
	printf("What restaurant are y'all going to? ");
	get_string(restaurant, 30);
	// printf("it is: %s", restaurant); // only used to test the get_string() fuction.
	
	#define TAX_RATE 0.175 // traditional C style constant with #define
	const double TIP_RATE = 0.18;
	double tip = 0;
	double grand_total = 0;
	double total_bill = 0;
	total_bill = restaurant_menu();
	if (total_bill <= 0){ 	// check if input is valid
		printf("Invalid input for this calculator.\n");
	}
	else {
		fprintf(out,"\nThe total bill for your dinner at %s should be $%.2f\n", restaurant, total_bill);
		tip = total_tip(total_bill, TIP_RATE);
		grand_total = tip + total_bill;
		fprintf(out,"\nTotal with tip will be $%.2f\n", grand_total);
		int k = 1;
		while (global_guest_list[k].subtotal != 0){
			global_guest_list[k].subtotal *= (1+TIP_RATE);
//			printf("Person %d owes: %.2f\n",k, (global_guest_list[k].subtotal));
            fprintf(out, "Person %d owes: %.2f\n", k, global_guest_list[k].subtotal);
			++k;
		}
	}
	
	/*
    total = total_bill(bill, TAX_RATE);
    printf("Dinner was $%.2f\nThe tax rate is  %.1f%% \n", bill, TAX_RATE*100);
    printf("bill + tax = %.2f\n", total);
    printf("Your tip should be $%.2f \n", tip);
    total += tip;
	check_total(total);
	}
	 */
	 
    return 0;
}
