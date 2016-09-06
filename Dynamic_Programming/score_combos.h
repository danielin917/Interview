#pragma once
#include<iostream>
#include<vector>
using namespace std;

int number_of_combos(int score){
	vector<int> cache_twos;
	vector<int> cache_middle;
	vector<int> cache_final;
	cache_twos.push_back(1);
	cache_middle.push_back(1);
	cache_final.push_back(1);
	for(int i = 1; i <= score; i++){
		int combos_two = 0;/*since we want combos not perms we only take sets with 2s followed by 3s followed by 7s*/
		int combos_middle = 0;
		int combos_final = 0;
		if(i - 2 >= 0){
			combos_two = cache_twos[i - 2];
		}
		cache_twos.push_back(combos_two);
		if(i - 3 >= 0){
			combos_middle = cache_middle[i - 3];
		}
		cache_middle.push_back(combos_middle + combos_two);
		if(i - 7 >= 0){
			combos_final = cache_final[i - 7];
		}
		cache_final.push_back(combos_two + combos_middle + combos_final);
	}
	return cache_final[score];
}
