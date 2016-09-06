#pragma once
#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
using namespace std;
struct Two_Sum{
	int first, second;
	bool contained(const int& third){
		return third == first || third == second;
	}
};

/*
 *O(n^2) solution --This is with distinct numbers
 */
bool three_sum(vector<int> vec, int target){
	unordered_map<int, list<Two_Sum>> mapping;
	for(int i = 0; i < vec.size(); i++){
		for(int j = i + 1; j < vec.size(); j++){
			int sum = vec[i] + vec[j];
			mapping[sum].emplace_back(Two_Sum{i,j});
		}
	}
	for(int i = 0; i < vec.size(); i++){
		int needed = target -vec[i];
		auto it = mapping.find(needed);
		if(it != mapping.end()){
			for(auto it_list = mapping[needed].begin(); it_list != mapping[needed].end(); it_list++){
				if(!(*it_list).contained(i)){
					return true;
				}
			}
		}
	}
	return false;
}
