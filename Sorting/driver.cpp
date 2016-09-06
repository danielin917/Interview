#include<iostream>
#include<vector>
#include "intersection.h"
#include "merge_sorted.h"
using namespace std;

int main(){
	/*
	vector<int> vec_a = {1,3,5,7,8,10,11};
	vector<int> vec_b = {0,2,5,5,5,6,8,9,11};
	vector<int> intersect = intersection(vec_a, vec_b);
	for(int i = 0; i <intersect.size() ; i++){
		cout << intersect[i] << endl;
	}
*/
	vector<int> a = {1,3,4,5,6,8,9,0,0,0,0};
	vector<int> b = {3,5,7,8};
	for(int i = 0; i < a.size(); i++){
		cout << a[i] << " ";
	}
	cout <<endl;
}
