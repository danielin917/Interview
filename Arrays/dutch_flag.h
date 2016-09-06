#pragma once
#include<vector>
using namespace std;

void swap(int& a, int& b){
	int c = a;
	a = b;
	b = c;
}
int quick_partition(vector<int>& vec, int pivot){/* unstable version */
	int l = 0;
	int h = vec.size() - 1;
	int i = 0;
	while(h != l){
		if(vec[i] > pivot){
			swap(vec[i], vec[h]);
			h--;
		}
		else{
			swap(vec[i], vec[l]);
			l++;
			i++;
		}
	}
	return vec[l] <= pivot ? l : l - 1;
}
void dutch_partition(vector<int>& vec, int h, int pivot){
	int l = 0;
	int i = 0;
	while(h != l){
		if(vec[i] == pivot){
			swap(vec[i], vec[h]);
			h--;
		}
		else{
			swap(vec[i], vec[l]);
			l++;
			i++;
		}
	}
}
void dutch_flag(vector<int>& vec, int index){
	int pivot = vec[index];
	int center = quick_partition(vec, pivot);
	dutch_partition(vec, center, pivot);
}
