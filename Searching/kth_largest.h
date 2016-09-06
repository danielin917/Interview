#pragma once
#include<queue>

using namespace std;

int find_kth_largest(vector<int> array, int k){
	priority_queue<int, vector<int>> pq;
	for(int i = 0; i < array.size(); i++){
		pq.push(array[i]);
	}
	int val;
	for(int i = 0; i < k; i++){/*klog(n)*/
		val = pq.top();
		pq.pop();
	}
	return val;
}
