#pragma once
#include<iostream>
#include<vector>

using namespace std;

void replace(vector<char>& a, int size){
	/*initialize shift*/
	int shift = 0;
	for(int i = 0; i < size; i++){
		if(a[i] == 'a')
			shift++;
	}
	int final_shift = shift;
	/*now we move elements to proper place*/
	for(int i = size - 1; i >= 0; i--){
		if(a[i] == 'a'){
			shift--;
		}
			a[i + shift] = a[i];
	}
	/*finally we expand a => dd*/
	for(int i  = 0; i < final_shift + size; i++){
		if(a[i] == 'a'){
			a[i] = 'd';
			a[i + 1] = 'd';
		}
	}
}
/*we return the new size of operational array*/
int remove(vector<char>& a, int size){
	int shift = 0;
	for(int i = 0; i < size; i++){
		if(a[i] == 'b'){
			shift++;
		}
		else{
			a[i - shift] = a[i];
		}
	}
	return size - shift;
}

void replace_remove(vector<char>& a, int size){
	int small_size = remove(a, size);
	replace(a, small_size);
}
