#include "MergeSort.h"
#include "QuickSort.h"
#include "HeapSort.h"
#include "MyLib.h"
#include <iostream>

using namespace std;


int main()
{
	int a[] = {4,7,2,4,7,8,54,3,68,245,14,2,6,4276,5,2,346,2346,57,34,7,4,35,67,74,8467,9,5,3,4,514,64,57,3457,53,63,53,5736,35623,225};
	int a_length = sizeof(a)/ sizeof(int);
	
	cout << "Merge Sort" << endl;
	mergeSort(a, a_length);
	printArray(a, a_length);
	arrayRandomizer(a, a_length);
	
	cout << "Quick Sort" << endl;
	quickSort(a, 0, a_length - 1);
	printArray(a, a_length);
	arrayRandomizer(a, a_length);
	
	
	cout << "Heap Sort" << endl;
	heapSort(a, a_length);
	printArray(a, a_length);
	arrayRandomizer(a, a_length);

	return 0;
}
