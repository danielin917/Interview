#include<iostream>
#include<sstream>
#include "dutch_flag.h"
#include "buy_sell_once.h"
#include "sample_array.h"
#include "spiral_array.h"
using namespace std;

void print_array(vector<int> vec){
	for(int i = 0; i < vec.size(); i++){
		cout << vec[i] << " ";
	}
	cout << endl;
}
int string_int(string str){
	bool neg = false;
	if(str.empty()){
		throw;
	}
	if(str[0] == '-')
		neg = true;
	int sum = 0;
	int ind = neg ? 1: 0;
	sum += str[ind] - '0';
	ind++;
	for(int i = ind; i < str.length(); i++){
		sum *= 10;
		sum += str[i];
	}
	if(neg){
		sum *= -1;
	}
	return sum;
}
vector<vector<int>> create_matrix(){
	int height;
	string eol;
	vector<vector<int>> matrix;
	cin >> height;
	getline(cin, eol);
	for(int i = 0; i < height; i++){
		matrix.push_back(vector<int>());
		string line, token;
		getline(cin, line);
		stringstream ss(line);
		while(getline(ss, token, ' ')){
			matrix[i].push_back(string_int(token));
		}
	}
	return matrix;
}
int main(){
	vector<int> a = {4,6,3,7,8,9,1,2,6,3,4,5,1,8,9,2,6,3,5,1,3,8,0,4,3,2,7,2,54,8,6,2,3,5,4,5,8,2,4};
	vector<int> b = {9, 50,4,13,2,6,2,0,15};
	vector<vector<int>> matrix= create_matrix();
	print_array(spiral_help(matrix, 0));
}
