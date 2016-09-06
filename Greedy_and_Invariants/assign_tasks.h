#pragma once
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<pair<int,int>> assign_tasks(vector<int> tasks){
	vector<pair<int, int>> assn;
	sort(tasks.begin(), tasks.end());
	for(int i = 0; i < tasks.size()/2; i++){
		pair<int, int> assignment;
		assignment.first = tasks[i];
		assignment.second = tasks[tasks.size() - i - 1];
		assn.push_back(assignment);
	}
	return assn;
}
