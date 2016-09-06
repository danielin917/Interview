#pragma once
#include<iostream>
#include<string>

using namespace std;

int my_atoi(string num_str){
	//check for negative
	bool neg = false;
	int sum = 0;
	if(num_str[0] == '-'){
		neg = true;
	}
	int i = neg ? 1 : 0;
	while(i < num_str.length()){
		sum *= 10;
		int addition = num_str[i] - '0';
		sum += addition;
		i++;
	}
	sum *= neg ? -1 : 1;
	return sum;
}
