#include <stdio.h>
#include <stdlib.h>

// multi dimentional array
// 3 arrays of arrays with 5 items (3x5)
// effectively a spreadsheet with 3 rows and 5 coluns
int grid [3][5] = {
	{1,2,3,4,5},
	{6,7,8,9,10},
	{11,12,13,14,15}
};

int main_XX(int arc, char** argv){
	int row = 0;
	int column = 0;
	
	for (row = 0; row <3; ++row){
		printf( "------- row %d -------\n", row);
		for (column = 0; column < 5; ++column){
			printf("column[%d], value =%d\n",column, grid[row][column]);
		}
	}
	return 0;
}