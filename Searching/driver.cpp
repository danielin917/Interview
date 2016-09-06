#include<iostream>
#include<vector>
#include "search_first.h"
#include "kth_largest.h"
using namespace std;

int main(){
	vector<int> a = {0, 1, 6, 6, 6, 6, 6, 6, 7, 9, 12, 14, 15, 17, 29, 37, 37, 37, 38, 38, 45};
	//  						 0  1  2  3  4  5  6  7  8  9  10  11  12  13  14  15  16  17  18  19  20
	int index = search_first(a, 6);
	cout << find_kth_largest(a, 1) << endl;

}
