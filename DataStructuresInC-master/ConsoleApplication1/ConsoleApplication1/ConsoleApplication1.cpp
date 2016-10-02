// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdlib>
#include <stdio.h>

void insertionSort(int num[]) {
	int temp, element, unsorted_element;
	for (int i = 1; i < 10; ++i) {
		element = num[i];
		unsorted_element = i;
		while (unsorted_element > 0 && num[unsorted_element] < num[unsorted_element -1]) {
			temp = num[unsorted_element];
			num[unsorted_element] = num[unsorted_element - 1];
			num[unsorted_element - 1] = temp;
			unsorted_element -= 1;
		}
//		printf("Num[%d] = %d\n", i, num[i]);
	}
}

int main()
{
	int nums[10];
	for (int i = 0; i < 10; ++i) {
		nums[i] = rand();
	}

	for (int i = 0; i < 10; ++i) {
		printf("PRE SORT::Num[%d] = %d\n", i, nums[i]);
	}

	insertionSort(nums);

	for (int i = 0; i < 10; ++i) {
		printf("POST SORT::Num[%d] = %d\n", i, nums[i]);
	}

    return 0;
}

