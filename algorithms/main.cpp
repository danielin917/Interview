#include "MergeSort.h"
#include "MyLib.h"
#include <iostream>

using namespace std;


int main()
{
	int a[] = {4,7,2,4,7,8,54,3,68,245,14,2,6,4276,4357,1,5,66,653,1,5,43,5,7,3,54,15,43,25,86,76,9,9,32,537,53,87,5,0,1};
	int a_length = sizeof(a)/ sizeof(int);
	mergeSort(a, a_length);
	printArray(a, a_length);
	return 0;
}
