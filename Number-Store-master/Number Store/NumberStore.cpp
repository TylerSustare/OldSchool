#include "stdafx.h"
#include "NumberStore.h"


NumberStore::NumberStore()
	: sz{ 0 }, elem{ new int[10] }, space{ 10 } {}

NumberStore::NumberStore(int x)
	: sz{ x }, elem{ new int[x] }, space{ 10 } // uninitialized memory for elements
{
	std::cout << "Constructing NumberStore with single int argument." << std::endl;
	for (int i = 0; i < x; ++i) elem[i] = 0; // initialize elements
}

NumberStore::NumberStore(const NumberStore& ns)
	: sz{ ns.sz }, elem{ new int[ns.sz] }, space{ ns.sz }
{
	std::cout << "Constructing NumberStore with copy constructor." << std::endl;
	std::copy(ns.elem, ns.elem + sz, elem);	// std::copy()
}

NumberStore::NumberStore(NumberStore&& a)
	:sz{ a.sz }, elem{ a.elem }		// copy a's elem and sz
{
	std::cout << "Move constructor" << std::endl;
	a.sz = 0;	// make a the empty NumberStore
	a.elem = nullptr;
}

NumberStore::NumberStore(std::initializer_list<int> lst)
{
	std::cout << "Constructing NumberStore with initializer list argument." << std::endl;
	int size = lst.size();	// if this line isn't in, there is a narrowing error on build
	space = size + 1;
	sz = size;
	elem = new int[sz];	// uninitialized memory for elements

	std::copy(lst.begin(), lst.end(), elem);	// initialize using std::copy()
}

NumberStore::~NumberStore()
{
	std::cout << "Destructing NumberStore\n";
	delete[] elem;
}

NumberStore& NumberStore::operator=(const NumberStore& a)
{	//std::cout << "Assignment operator overloaded\n";
	if (this == &a) return *this;

	if (a.sz <= space) {	// self-assignment, no work needed
		for (int i = 0; i < a.sz; ++i) elem[i] = a.elem[i];
		sz = a.sz;
		return *this;
	}
	int* p = new int[a.sz];	// allocate new space
	for (int i = 0; i < a.sz; ++i) p[i] = a.elem[i];	
	// copy(a.elem, a.elem+sz, p); // copy elements
	delete[] elem;		// deallocate old space
	space = sz = a.sz;	// set new size
	elem = p;			// now we can reset elem;
	// sz = a.sz;
	return *this;		// return a self reference.

}

NumberStore& NumberStore::operator=(NumberStore&& a)	// move a to this NumberStore
{
	std::cout << "Move assignment operator.\n";
	delete[] elem;	// deallocate old space
	elem = a.elem;	// copy a's elem and sz
	sz = a.sz;
	a.elem = nullptr;	// make this an empty NumberStore
	a.sz = 0;
	return *this;	// return self-reference
}

int NumberStore::size() const
{
	return this->sz;
}

// private function 'reserve()' used for push() function
void NumberStore::reserve(int newalloc)
{
//	if (newalloc <= space) return;	// line would be used, if the 
	int* p = new int[newalloc];		// allocate new space
	for (int i = 0; i < newalloc; ++i) {
		p[i] = elem[i];	// copy old elements
	}
	delete[] elem;					// deallocate old space
	elem = p;
	space = newalloc;
//	sz = newalloc;
}

// resize function to increase or decrease NumerStore capacity
// makes the NumberStore have newsize elements
// initializes each new element with default value 0
void NumberStore::trim(int newsize) {
	if (newsize < 0) { std::cout << "Cannot trim to less than 0"; return; }
	reserve(newsize);
	// if trim() were to increase size, the new elements woudld be initialized wtih zeros.
	if (newsize > this->sz) {
		for (int i = sz; i < newsize; ++i) {
			elem[i] = 0;	// initialize new elements
		}
	}
	sz = newsize;
}

NumberStore & NumberStore::insert(int val, int index)
{
	if (index > space || index < 0) { std::cout << "Bad removal index."; return *this; }
	int* tempNS = new int[sz + 1];
	for (int i = 0; i < index; ++i) {
		tempNS[i] = elem[i];	// initialize elements in tempNS up to the removal index. 
	}
	// stop initializing before index to remove 
	// start initializing again after index to remove.
	for (int i = index + 1; i < sz + 1; ++i) {
		tempNS[i] = elem[i-1];	// initialize the rest of the elements in tempNS after index 
	}
	tempNS[index] = val;
	sz += 1;
	delete[] elem;
	elem = tempNS;

	return *this;
}

NumberStore & NumberStore::remove(int index)
{
	if (index > sz || index < 0) { std::cout << "Bad removal index."; return *this; }
	int* tempNS = new int[sz - 1];
	for (int i = 0; i < index; ++i) {
		tempNS[i] = elem[i];	// initialize elements in tempNS up to the removal index. 
	}
	// stop initializing before index to remove 
	// start initializing again after index to remove.
	for (int i = index + 1; i < sz-1; ++i) {
		tempNS[i] = elem[i+1];	// initialize the rest of the elements in tempNS after index 
	}
	tempNS[index] = elem[index + 1];
	sz -= 1;
	delete[] elem;
	elem = tempNS;

	return *this;
}

// increase NumberStore size by one; initialize new element to d
NumberStore& NumberStore::push(int d) {
	if (!(d <= 0 || d>0)) {
std::cout << "Bad input"; return *this;
}
	if (space == 0) {
		reserve(8);		//start with space for 8 elements
	}
	else if (sz == space) {
		reserve(1.5 * space);	// get more space (50% more space)
	}
	elem[sz] = d;
	++sz;
	return *this;
}

// square bracket element access
int& NumberStore::operator[](int n) { return elem[n]; }

// square bracket const element access
int NumberStore::operator[](int n) const {return elem[n]; }

std::ostream& operator<<(std::ostream& os, const NumberStore & ns) {
	os << '(';
	for (int i = 0; i < ns.sz; ++i) {
		os << ns[i];
		if (!(i == ns.sz - 1)) {
			os << ',';
		}
	}
	os << ')';
	return os;
}

// Input stream
std::istream& operator>>(std::istream& is, NumberStore& ns) {
	int temp{ 0 };
	is >> temp;
	ns.push(temp);
	return is;
}

