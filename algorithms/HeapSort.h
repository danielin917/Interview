#pragma once
#include "MyLib.h"
/*
 *Note: Practice again. Remember what is acting off the base and what is index. Maybe make more vairables fore reference
 */

/*
 *|Tree Space ->| Unsorted Array Space|
 */
template<typename T>
void fixDown(T* array, int length, int cur_index)
{
	int next_index = (cur_index + 1) * 2 - 1;
	if(next_index < length)
	{	
		if(next_index + 1 < length)
			next_index = array[next_index + 1] > array[next_index] ? next_index + 1 : next_index;
		
		if(array[next_index] > array[cur_index]){
			referenceSwap(array[next_index], array[cur_index]);
			fixDown(array, length - (next_index - cur_index), next_index);
		}
		else{
			return;
		}
	}
}

template<typename T>
void heapify(T* array, int length)
{
	for(int i = 0; i < length; i++)
	{
		fixDown(&array[length - i - 1], i + 1, 0);
	}
}

template<typename T>
void heapSort(T* array, int length)
{
	heapify(array, length);
	for(int i = 0; i < length; i++)
	{
		referenceSwap(array[0], array[length - i - 1]);	
		fixDown(array, length - i - 1, 0);	
	}
}

