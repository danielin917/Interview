#pragma once

#include<iostream>

using namespace std;

/*swap by object reference*/
template<typename T>
void referenceSwap(T& val_1, T& val_2)
{
	T copy = val_1;
	val_1 = val_2;
	val_2 = copy;
}

template<typename T>
void printArray(T* array, int length)
{
	for(int i = 0; i < length; i ++)
	{
		cout << array[i] << " ";
	}
	cout << endl;

}
