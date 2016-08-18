// CPP-Bubble-Sort.cpp : Defines the entry point for the console application.
// C++ console application to demonstrate and deepen understanding of a
// bubble sort. 
// G. Tyler Sustare. Mar 19, 2015.

#include "stdafx.h"
#include <iostream>
#include <vector>

// swaps consecutive integer values in the list
void exchange(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
	return;
}
// uses a bubble sort to make an ascending list of ints
// All values are passed and changed by reference
void bubble_sort(std::vector<int>& num) {
	int i, j;
	bool swap = true;
	int num_size = num.size();
	for (int i = 1; (i <= num_size - i) && swap; ++i) {
		swap = false;
		for (int j = 0; j < num_size - 1; ++j) {
			if (num[j] > num[j + 1]) {
				exchange(num[j], num[j + 1]);
				swap = true;		// shows a swap happened
			}
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	std::vector<int> num_list{ 1,23,5,0,3,-32,-2,3,9,-7 };
	bubble_sort(num_list);

	for (auto i : num_list) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	return 0;
}

