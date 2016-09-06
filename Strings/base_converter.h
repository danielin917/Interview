#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;


int from_hex(char a){
	unordered_map<char, int> hex({{'A', 10},{'B', 11},{'C',12},{'D',13},{'E',14},{'F',15}});
	if(a > '9')
		return hex[a];
	else
		return a - '0';
}
int convert_str_int(string num, int b){
	if(num.length() == 0){
		return 0;
	}
	bool neg = num[0] == '-';
	int i = neg ? 1 : 0;
	int sum = from_hex(num[i++]);
	for(; i < num.length(); i++){
		sum *= b;
		sum +=from_hex(num[i]);
	}
	if(neg)
		sum = -sum;
	return sum;
}
char convert_hex(int num){
	vector<char> hex= {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	return hex[num];/*we assume correct input, we will get a nice seg fault otherwise*/
}
void swap(char& a, char& b){
	char c = a;
	a = b;
	b = c;
}
string reverse(string str){
	for(int i = 0; i < str.length()/2; i++){
		swap(str[i], str[str.length() - i - 1]);
	}
	return str;
}
string convert_int_str(int num, int b){
	string num_str = "";
	int x = num;
	while(x){
		int digit_int = x % b;
		char digit = convert_hex(digit_int);
		num_str += digit;
		x /= b;
	}
	if(num < 0)
		num_str += '-';
	num_str = reverse(num_str);
	return num_str;
}

string base_converter(string num, int b1, int b2){
	int x = convert_str_int(num, b1);
	return convert_int_str(x, b2);
}
