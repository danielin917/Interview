#pragma once

#include<iostream>
#include<cassert>
using namespace std;

/*
 *Takes too long takes M unions on N objects
 */
class QuickFinder{
	/*
	 *p and q are connected if they have the same id
	 */	
	int* id_array;	
	int size;
	public:
	QuickFinder(int n){
		id_array = new int[n];
		for(int i = 0; i < n; i++)
			id_array[i] = i;
	}
	bool find(int p, int q){
		return(id_array[p] == id_array[q]);
	}
	void unionize(int p, int q){
		assert(p < size && q < size);
		for(int i = 0; i < size; i++)
		{
			if(id_array[p] == id_array[i])
			{
				id_array[i] = id_array[q];
			}	
		}	
	}
};
