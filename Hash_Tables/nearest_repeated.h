#pragma once
#include<unordered_map>
#include<vector>
using namespace std;

int nearest_repeated(vector<string> vec){
	unordered_map<string, int> h;
	int min = -1;
	for(int i =0; i < vec.size(); i++){
		auto it = h.find(vec[i]);
		if(it != h.end()){
			if(i - it->second < min || min == -1){
				min = i -it->second;
			}
		}
		h[vec[i]] = i;
	}
	return min;
}
