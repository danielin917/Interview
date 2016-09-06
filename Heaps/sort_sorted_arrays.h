#pragma once
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class pair_cmp{

public:

bool operator()(const pair<int, int>& a, const pair<int, int>& b){
	return a.first > b.first;
}

};

vector<int> sort_sorted_arrays(vector<vector<int>> double_array){
	priority_queue<pair<int, int>, vector<pair<int, int>>, pair_cmp> pq;
	vector<int> index_vector;
	vector<int> sorted_vector;
	int num_active = 0;
	/*
 	* Set all indexes to zero unless empty
 	*/
	for(int i = 0; i < double_array.size(); i++){
		if(double_array[i].size()){
			index_vector.push_back(0);
			num_active++;
			pair<int, int> x;
			x.first = double_array[i][0];
			x.second = i;
			pq.push(x);
		}
	}

	while(num_active){
		pair<int, int> next = pq.top();
		pq.pop();
		sorted_vector.push_back(next.first);
		int index = index_vector[ next.second];
		if(index + 1 < double_array[next.second].size()){
			next.first = double_array[next.second][index + 1];
			pq.push(next);
			index_vector[next.second]++;
		}
		else{
			num_active--;
		}
	}
	return sorted_vector;
}
