#pragma once

#include<iostream>

using namespace std;


template<typename T>
void printArray(T* array, int length)
{
	for(int i = 0; i < length; i ++)
	{
		cout << array[i] << " ";
	}
	cout << endl;

}
