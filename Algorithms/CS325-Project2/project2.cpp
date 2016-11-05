//Mark Giles
//George Sustare
//Ryan Fleming
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <climits>
#include <string.h>
#include <fstream>

using namespace std;

//algorithm 1
//brute force
int changeslow(int VSize, int in[], int out[], int A) {
	if (A == 0) {
		return 0;
	}
	int result = INT_MAX;

	for (int i = 0; i < VSize; i++) {
		if (in[i] <= A) {
			int sub_result = changeslow(VSize, in, out, A - in[i]);
			
			if (sub_result != INT_MAX && sub_result + 1 < result) {
				result = sub_result + 1;
			}
		}
	}
	
	return result;
}
//algorithm 2
//greedy
int changegreedy(int VSize, int in[], int out[], int A){
//to really know the most valuable coins we have to sort it
	sort(in, in);
//worst case O(n)
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


//algorithm 3
//dynamic programming
int changedp(int VSize, int V[], int outputArray[], int A)
{
	int i, j = 0;
	//make table indexed by values of change
	int **T;
	T = (int**) malloc(sizeof(int*)*VSize);
	for (i = 0; i < VSize; i++)
	{
		//keep track of indices of maximum subarray
		T[i] = (int*) malloc(sizeof(int)*(A + 1));
		for (j = 0; j <= A; j++)
		{
			if (i == 0)
			{
				//correct coin value
				T[i][j] = j;
			}
			//if coin value is too high
			else if (V[i] > j)
			{
				//go back up one row
				T[i][j] = T[i - 1][j];
			}
			//or its the smaller of the row above or the column back one coin value
			else
			{
				if (T[i - 1][j] > (T[i][j - V[i]] + 1))
					T[i][j] = (T[i][j - V[i]] + 1);
				else	
					T[i][j] = T[i - 1][j];
			}
		}
	}
	//minimum number of coins needed
	int minimum = 0;
	//go backwars through table
	i = VSize - 1;
	j = A;
	while (i >= 1 && j > 0)
	{
		if(T[i][j] == T[i - 1][j])
		{
			//no coin in index, go up one row
			i--;
		}
		//if there is a coin in index
		else
		{
			//go back to previous coin value
			j -= V[i];	 	
			//add this voic to outputArray
			outputArray[i]++;
			minimum++;
			//take out coin value from amount needed	
			A -= V[i];
		}
	}
	//fill amount remaining with pennies
	outputArray[0] = A;
	minimum += A;
	//cleanup
	for (i = 0; i < VSize; i++)
	{
		delete T[i];
	}
	delete T;	
	return minimum;
}

void resetArray(int arrayLength, int array[]) {
	int i = 0;
	for (i = 0; i < arrayLength; i++) {
		array[i] = 0;
	}
}

int main(int argc, char *argv[]) {
	FILE *inputFile;
	char c,
		 stringArray[512],
		 stringValue[512],
		 outputFilename[512];
	int m = -1,
		A = -1,
		VSize = 0,
		V[256],
		outputArray[256],
		i = 0,
		intValue = -1,
		arrayComplete = 0;
	ofstream outputFile;
	for (i = 0; i < strlen(argv[1]); i++) {
		if (argv[1][i] == '.') {
			outputFilename[strlen(outputFilename)] = '\0';
			break;
		} else if (argv[1][i] != '?' && argv[1][i] != 'L') {
			outputFilename[strlen(outputFilename)] = argv[1][i];
		}
	}
	strcat(outputFilename, "change.txt");
	inputFile = fopen(argv[1], "r");
	outputFile.open(outputFilename);

	while ((c = getc(inputFile)) != ']') {
		if (c == ',') {
			V[VSize] = atoi(stringArray);
			VSize = VSize + 1;
			memset(stringArray, 0, strlen(stringArray));
		} else if (c != '[') {
			stringArray[strlen(stringArray)] = c;
		}
	}
	V[VSize] = atoi(stringArray);
	VSize = VSize + 1;
	memset(stringArray, 0, strlen(stringArray));

	while ((c = getc(inputFile)) != EOF) {
		stringArray[strlen(stringArray)] = c;
	}
	A = atoi(stringArray);

    outputFile << "  Testing: V = [";
	for (i = 0; i < VSize; i++) {
		outputFile << V[i];
		if (i < VSize - 1) {
			outputFile << ",";
		}
	}
	outputFile << "] and A = " << A << "\n";
	
	// Clearing output array for next algorithm
	resetArray(VSize, outputArray);

	// Brute Force Algorithm
    outputFile << "**************************************" << endl;
    outputFile << "       Brute Force  Algorithm" << endl;
	outputFile << "**************************************" << endl;
	m = changeslow(VSize, V, outputArray, A);
    outputFile << "C: [";
    for (int i = 0; i < VSize; ++i){
        outputFile << outputArray[i];
    }
    outputFile << "]" << endl;
    outputFile << "m = " << m << endl;

	// Clearing output array for next algorithm
	resetArray(VSize, outputArray);
	// Clearing m for next algorithm
	m = -1;

	// Greedy Algorithm
    outputFile << "**************************************" << endl;
    outputFile << "           Greedy Algorithm" << endl;
	outputFile << "**************************************" << endl;
	m = changegreedy(VSize, V, outputArray, A);
    outputFile << "C: [";
    for (int i = 0; i < VSize; ++i){
        outputFile << outputArray[i];
    }
    outputFile << "]" << endl;
    outputFile << "m = " << m << endl;
	
	// Clearing output array for next algorithm
	resetArray(VSize, outputArray);
	// Clearing m for next algorithm
	m = -1;

	// Dynamic Programming
    outputFile << "**************************************" << endl;
    outputFile << "    Dynamic Programming Algorithm" << endl;
	outputFile << "**************************************" << endl;
	m = changedp(VSize, V, outputArray, A);
	outputFile << "C: [";
	for (int i = 0; i < VSize; i ++) {
		outputFile << outputArray[i];
	}
	outputFile << "]" << endl;
	outputFile << "m = " << m << endl;
	fclose(inputFile);
	outputFile.close();
	return 0;
}
