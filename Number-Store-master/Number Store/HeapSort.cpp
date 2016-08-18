#include "stdafx.h"
#include "HeapSort.h"

HeapSort::HeapSort()
{
}

HeapSort::~HeapSort()
{
}

void max_heapify(int* a, int i, int n) {
	int j, temp;
	temp = a[i]; // value of parent
	j = 2 * i; // refer to left child
	while (j <= n) {
		if (j < n && a[j + 1] > a[j]) {	// pick biggest of the two children
			j = j + 1;	// select right child
		}
		if (temp > a[j]) break; // if parent > child, leave it alone
		else if (temp <= a[j]) {// neccesary test? (no, just assigns child to parent)
			a[j / 2] = a[j];
			j = 2 * j;
		}
	}
	a[j / 2] = temp;
	return;
}

void swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

void heapsort(int* a, int n) {
//	int temp;
	for (int i = n; i >= 2; i--) {
		swap(a[i], a[1]);
		max_heapify(a, 1, i - 1);
	}
}

void buid_maxheap(int* a, int n) {
	for (int i = n / 2; i >= 1; i--) {
		max_heapify(a, i, n);
	}
}

void NumberStore_heapsort(NumberStore& ns) {
	buid_maxheap(ns.elem - 1, ns.size());
	heapsort(ns.elem - 1, ns.size());
}

void sort_now() {
	int n{ 0 };
	NumberStore ns;
	std::cout << "How many items would you like to sort? ";
	std::cin >> n;
	ns.space = 2*n;
	std::cout << "Please enter them seperately, separated by the return key" << std::endl;
	for (int i = 0; i < n; ++i) {
		std::cout << '>';
		std::cin >> ns;
	}
	std::cout << std::endl;
	NumberStore_heapsort(ns);
	std::cout << ns << std::endl;

}