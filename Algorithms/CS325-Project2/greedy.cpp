#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;


int changegreedy(int VSize, int in[], int out[], int A){
// to really know the most valuable coins we have to sort it
        sort(in, in);
         	for (int i = 0; i < VSize; ++i){
         	}

// worst case O(n)
	int numCoins = 0;
	for(int i = VSize-1 ; A > 0; --i){
		while (A >= in[i]){
			A = A - in[i];	
			out[i] += 1;
			numCoins += 1;
		}	
	}
	return numCoins;
}

int main() {
	// Greedy algorithm
	cout << "changegreedy() test " << endl;
	cout << "**************************************" << endl << endl;
	cout << "testing with C = [1,2,4,8] and m = 15" << endl;
	int coins[4] = {1,2,4,8};
	int change = 15;
	int VSize = 4;
	int outputArray[4] = {0,0,0,0};
	int m = changegreedy(VSize, coins, outputArray, change);
	cout << "m = " << m << endl;
	cout << "[";
	for (int i = 0; i < VSize; ++i){
		cout << outputArray[i];
	}
	cout << "]" << endl;;
	
	cout << "**************************************" << endl << endl;
	cout << "testing with C = [1,3,7,12] and m = 29" << endl;
	int coins2[4] = {1,3,7,12};
	int change2 = 29;
	int VSize2 = 4;
	int outputArray2[4] = {0,0,0,0};
	int m2 = changegreedy(VSize2, coins2, outputArray2, change2);
	cout << "m = " << m2 << endl;
	cout << "[";
	for (int i = 0; i < VSize2; ++i){
		cout << outputArray2[i];
	}
	cout << "]" << endl;;
	
	cout << "**************************************" << endl << endl;
	cout << "testing with C = [1,3,7,12] and m = 29" << endl;
	int coins3[4] = {1,3,7,12};
	int change3 = 31;
	int VSize3 = 4;
	int outputArray3[4] = {0,0,0,0};
	int m3 = changegreedy(VSize3, coins3, outputArray3, change3);
	cout << "m = " << m3 << endl;
	cout << "[";
	for (int i = 0; i < VSize3; ++i){
		cout << outputArray3[i];
	}
	cout << "]" << endl;;
	// end Greedy Algorithm
	
    return 0;
}
