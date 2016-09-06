#include "sort_sorted_arrays.h"
#include <vector>

using namespace std;
void swap(int& a, int&b){
	int z = a;
	a = b;
	b = z;
}
void reverse(vector<int>& vec){
	for(int i = 0; i < vec.size()/2; i++){
		swap(vec[i], vec[vec.size() - 1 - i]);
	}

}

void sort_inc_dec(vector<int>& id_vec){
	if(id_vec.size() < 2)
		return;
	bool increasing = true;
	vector<vector<int>> double_array;
	vector<int> section;
	for(int i = 1; i < id_vec.size(); i++){
		if(increasing){
			if(id_vec[i] >= id_vec[i - 1]){
				section.push_back(id_vec[i]);
			}
			else{
				double_array.push_back(section);
				section.clear();
				section.push_back(id_vec[i]);
				increasing = false;
			}
		}
		else{
			if(id_vec[i] <= id_vec[i - 1]){
				section.push_back(id_vec[i]);
			}
			else{
				reverse(section);
				double_array.push_back(section);
				section.clear();
				section.push_back(id_vec[i]);
				increasing = true;
			}
		}
	}
	id_vec = sort_sorted_arrays(double_array);
}
