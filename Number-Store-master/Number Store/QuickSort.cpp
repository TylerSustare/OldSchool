#include "stdafx.h"
#include "QuickSort.h"


QuickSort::QuickSort()
{
}

QuickSort::~QuickSort()
{
}

void quickSort(int arr[], int left, int right) { 
	int i = left;	// left most point in data list		
	int j = right;	// right most point in data list
	int temp;
	int pivot = arr[(left + right) / 2];

	/* partition */  
	while (i <= j) {
		while (arr[i] < pivot)	// COMPARING VALUES, NOT INDEXES
			i++;
		while (i <= j) {
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	}

	/* recursion */
	if (left < j)
		quickSort(arr, left, j);
	if (i < right)
		quickSort(arr, i, right);
}