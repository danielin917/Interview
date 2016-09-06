#pragma once
#include<vector>

using namespace std;

int find_next(vector<int>& vec, int it, int target){
	while(it < vec.size() && vec[it] < target){
		it++;
	}
	return it < vec.size() ? it : -1;
}

vector<int> intersection(vector<int>& vec_a, vector<int>& vec_b){
	vector<int> intersect;
	int it_a = 0;
	int it_b = 0;
	while(it_a < vec_a.size()){
		int found = find_next(vec_b, it_b, vec_a[it_a]);
			if(found == -1){
				return intersect;
			}
			else if(vec_b[found] == vec_a[it_a]){
				intersect.push_back(vec_a[it_a]);
				it_a++;
				it_b = found + 1;
			}
			else{
				it_b = found;
				it_a = find_next(vec_a, it_a, vec_b[it_b]);
				if(it_a == -1)
					return intersect;
		}
	}
	return intersect;

}
