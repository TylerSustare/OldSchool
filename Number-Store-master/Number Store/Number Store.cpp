// Number Store.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "NumberStore.h"
#include "HeapSort.h"
#include <time.h>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	// initial time variables for testing
	//clock_t t1, t2;
	//t1 = clock();

	//NumberStore ns0{ 0,1,2,3,4 };
	//cout << "initial NS: " << ns0 << endl;
	//cout << "Testing ns0.trim(2)" << endl;
	//ns0.trim(3);
	//cout << "post trim() ns0: " << ns0 << endl;
	//cout << "Testing ns0.push(4)" << endl;
	//ns0.push(4);
	//cout << "post push(4) ns0: " << ns0 << endl;
	//cout << "Testing remove(): " << endl;
	//ns0.remove(2);
	//cout << "post remove(1) ns0: " << ns0 << endl;
	//cout << "testing insert(-1, 2)" << endl;
	//ns0.insert(-1, 2);
	//cout << "post insert(-1, 2): " << ns0 << endl;
	//cout << "************ HeapSort Tests ***********" << endl;
	////cout << "testing build_maxheap()" << endl;
	////buid_maxheap(ns0.elem, ns0.size());
	////cout << "testing heapsort()" << endl;
	////heapsort(ns0.elem, ns0.size());
	////cout << "results: " << ns0 << endl;
	//cout << "putting it all together. NumberStore_heapsort(ns0): " << endl;
	//NumberStore_heapsort(ns0);
	//cout << "post test" << ns0 << endl;
	//cout << "************** end ******************" << endl << endl;

	sort_now();

	//cout << "press enter to end";
	//cin.get();

	//t2 = clock();
	//float diff{(float)t2 - (float)t1};
	return 0;
}

