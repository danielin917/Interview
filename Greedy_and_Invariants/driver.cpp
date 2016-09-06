#include<iostream>
#include "assign_tasks.h"
#include<vector>
#include "three_sum.h"
using namespace std;

int main(){
	/*#1
	vector<int> tasks = {5, 2, 1,6, 4, 4};
	vector<pair<int, int>> assignment = assign_tasks(tasks);
	for(int i = 0; i < assignment.size(); i++){
		cout << assignment[i].first << ":" << assignment[i].second << endl;
	}
	*/
	vector<int> a = {1,5,2,-6,4,1,3,10,26,-14};
	cout << three_sum(a, 47) << endl;
}
