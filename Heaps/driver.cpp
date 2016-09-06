#include<iostream>
#include "k_longest_strings.h"
#include "sort_sorted_arrays.h"
#include "sort_inc_dec_arrays.h"
#include<sstream>
#include<vector>
#include<string>
#include "closest_stars.h"
using namespace std;

int main(){
	vector<Coord> c = {{2,2,2},{2,4,5},{7,8,8},{9,9,9},{2,1,2},{3,2,5},{9,2,1}};
	vector <Star> closest = k_closest(c, 3);
	for(int i = 0; i < closest.size(); i++){
		cout << closest[i].dist << " ";
	}
	cout << endl;
}

