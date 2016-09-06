#pragma once
#include<iostream>
#include<random>
#include<unordered_set>
using namespace std;
int prand(int seed){
	int hash = seed ^ 0xFFFFFFFF;
	for(int i = 0; i < 32; i++){
		hash = hash<<1 ^ ((hash>>4 & 1) ^ (hash>> 8 & 1) ^ (hash>>16 & 8));
	}
	return hash;
}
int hash_creator(const vector<int>& vec, int size){
	int seed = 0xFFFF;
	for(int i = 0; i < vec.size(); i++){
		seed ^= vec[i];
	}
	seed ^= size;
	return prand(seed);
}
/*
 *This uses 0(N) space, instead of mask swap to front and do operation on unchosen array and
 *bad worst case complexity
 */
vector<int> sample_array(vector<int> vec, int size){
	int hash = hash_creator(vec, size);
	vector<int> testers;
	vector<bool> mask(0, vec.size());
	while(testers.size() != size){
		int index = hash % vec.size();
		if(!mask[index]){
			testers.emplace_back(vec[index]);
			mask[index] = true;
		}
		hash = prand(hash);
	}
	return testers;
}
/*
 *improved
 */
vector<int> sample(vector<int> vec, int size){
	int start = 0;
	int length = size;
	int hash = hash_creator(vec, length);
	for(int i = 0; i < size; i++){
		swap(vec[i], vec[start + hash % length]);
		hash = prand(hash);
		length --; start++;
	}
	return vector<int>(vec.begin(), vec.begin() + size);
}
