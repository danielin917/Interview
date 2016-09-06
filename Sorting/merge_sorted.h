#pragma once
#include<iostream>
using namespace std;

void swap(int& a, int& b){
	int c = a;
	a = b;
	b = c;
}

void merge_sorted(vector<int>& a, vector<int>& b){
	if(a.size() < b.size()){
		throw;
	}
	if(a.size() == 0 || b.size() == 0){
		return;
	}
	/*start of empty space*/
	int a_i, b_i, a_size;
	a_size = 0;
	b_i = b.size() - 1;
	int S =  a.size() -1;
	while(a[a_size] != 0){a_size++;}
	a_i = a_size - 1;
	for(int i = 0; i < a_size + b.size(); i++){
		if(a_i < 0 || (b_i >= 0 && b[b_i] > a[a_i])){
			swap(a[S--], b[b_i--]);
		}
		else{
			swap(a[S--], a[a_i--]);
		}
	}
}
