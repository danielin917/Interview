#pragma once

#include<iostream>
#include<stdlib.h>
#include<time.h>
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

template<typename T>
void arrayRandomizer(T* array, int length)
{
	srand(time(NULL));
	for(int i = 0; i < length; i++)
	{
		int swap = rand() % length;
		referenceSwap(array[i], array[swap]);
		swap = rand() % length;
		referenceSwap(array[i], array[swap]);
	}	
}
