#pragma once
#pragma warning(disable:4996)	// must use this for copy constructor to work
#include <iostream>
#include <initializer_list>
#include <algorithm>
class NumberStore
{
public:
	int sz;		// the size
	int* elem;	// pointer to the first element (of type int)
	int space;	// space
//-------------------------------------------------------------
	// Ctor with default capacity, USE 10 for capacity
	NumberStore();
	// Ctor with int capacity
	explicit NumberStore(int);
	// Ctor with copy
	NumberStore(const NumberStore&);
	// Ctor with move
	NumberStore(NumberStore&&);
	// Ctor with initializer list
	NumberStore(std::initializer_list<int> lst);
	// Destructor
	~NumberStore();

// -----------------------------------------------------------
	// Add element to end
	NumberStore& push(int);
	// Copy assignment
	NumberStore& operator=(const NumberStore&);
	// Move assignment
	NumberStore& operator=(NumberStore&&);
	// Subscript
	int& operator[](int n);
	// Subscript const
	int operator[](int n) const;
	// Number of elements
	int size() const;
	// Storage capacity before resize
	int capacity() const { return space; }
	// Reduce capacity to n, may remove elements, modifying size
	void trim(int);
	// Insert val at position index
	NumberStore& insert(int val, int index);
	// Remove an element at position index
	NumberStore& remove(int index);
	// Output stream
	friend std::ostream& operator<<(std::ostream& os, const NumberStore & ns);
	// Input stream
	friend std::istream& operator>>(std::istream& is, NumberStore& ns);
	//----------------------------------------------------------------------
	// using reserve to set up push() from ch 19 in book.
	void reserve(int newalloc);

};

