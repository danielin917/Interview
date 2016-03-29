#pragma once
#include <cstdio>
#include "MyLib.h"
using namespace std;
template<typename T>
int partition(T* array, int start, int end)
{	
	T pivot_val = array[end];
	int swap_index = start;
	for(int i = start; i < end; i ++)
	{
		if(array[i] <= pivot_val)
		{
			referenceSwap(array[i], array[swap_index]);	
			swap_index++;
		}
	}
	referenceSwap(array[end], array[swap_index]);
	return swap_index; 
}

template<typename T>
void quickSort(T* array, int start, int end)
{
	if(end <= start)
		return;
	int pivot_index = partition(array, start, end);
	int end_r = end;
	int end_l = pivot_index - 1;
	
	quickSort(array, pivot_index + 1, end_r);
	quickSort(array, start, end_l);
}
