#pragma once

#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<queue>

using namespace std;

class str_cmp{
public:
bool operator()(const string& a, const string& b){
	return a.length() > b.length();
}
};

vector<string> k_longest_strings(stringstream& ss, int k){
	string word;
	priority_queue<string, vector<string>,  str_cmp> min_heap;
	while(ss >> word){
		min_heap.push(word);
		if(min_heap.size() > k){
			min_heap.pop();
		}
	}
	vector<string> long_vec;
	while(min_heap.size()){
		long_vec.push_back(min_heap.top());
		min_heap.pop();
	}
	return long_vec;
}
