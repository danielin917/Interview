#pragma once

/*
template<typename T>
class MyVector{
	T* array;
	int length;
	int filled;
	void merge();
public:
	Merge	
}
*/

template<typename T>
void merge(T* array, T* left, T* right, int l_length, int r_length)
{
	int a_length = l_length + r_length;
	int l_index, r_index;
	l_index = r_index = 0;
	for(int i = 0; i < a_length; i++)
	{
		if(r_index == r_length || (l_index != l_length && left[l_index] < right[r_index]))
		{
			array[i] = left[l_index];
			l_index++;
		}
		else
		{
			array[i] = right[r_index];
			r_index++;
		}
	}
}
template<typename T>
void mergeSort(T* array, int length)
{
	if(length == 1)
		return;
	int l_length = length/2;
	int r_length = length/2 + length % 2;
	T* left= new T[l_length];	
	T* right = new T[r_length];
	for(int i = 0; i < l_length ; i++)
	{
		left[i] = array[i];
	}
	for(int j = 0; j < r_length; j++)
	{
		right[j] = array[l_length + j];
	}
	mergeSort(left, l_length);
	mergeSort(right, r_length);
	merge(array, left, right, l_length, r_length);
	delete[] left;
	delete[] right;
}
