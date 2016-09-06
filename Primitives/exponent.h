#pragma once
#include<unordered_map>

using namespace std;
//keep cache o(logn) space o(logn) time
double exponent(double num, int power, unordered_map<int, double>& cache){
	if(power == 0){
		return 1;
	}
	if(power == 1){
		return num;
	}
	bool cached = cache.find(power) != cache.end();
	if(cached){
		return cache[power];
	}
	double prod;
	if(power % 2){
		 prod = exponent(num,power/2, cache) * exponent(num, power/2,cache) * num;
	}
	else{
		 prod = exponent(num, power/2, cache);
	}
	cache[power] = prod;
	return prod;
}

double exp(double num, int power){
	unordered_map<int,double>map;
	if(power < 0){
		power = -power; num = 1.0/num;
	}
	return exponent(num, power, map);
}
/*iterative solution with much less overhead*/

int power(double x, int power){
	int val = 1.0;
	if(power < 0){
		power = -power; x = 1.0/x;
	}
	while(power){
		if(power & 1){/*check for odd*/
			val *= x;
		}
		x*=x;
		power>>1;
	}
	return val;
}
