#pragma once
#include<iostream>
#include<vector>

using namespace std;



/*simple binary search which calls find_first at end*/
template<typename T>
int search_first(const vector<T>& array, T target){
	int needle = -1;
	int L, U;
	L = 0;/* inclusive */
	U = array.size(); /*exclusive */
	while(L < U){
		int M = L + (U - L)/2;/* avoid overflow '__' */
		if(array[M] < target){
			L = M + 1;
		}
		else if(array[M] > target){
			U = M;
		}
		else{
			//return M; //This would be a normal binary search
			needle = M; //Instead we remember the location and keep looking
			U = M;
		}
	}
	return needle;
}
