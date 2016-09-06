#pragma once
#include<vector>

using namespace std;

vector<int> spiral_help(vector<vector<int>> matrix, int step){
	vector<int> inorder;
	if(2*step >= matrix.size()){
		return {};
	}
	if(matrix.size() - 2*step == 1){
		inorder.push_back(matrix[step][step]);
	}
	for(int i = step; i < matrix.size() - step - 1; i++){
		inorder.push_back(matrix[step][i]);
	}
	for(int i = step; i < matrix.size() - step - 1; i++){
		inorder.push_back(matrix[i][matrix.size() - step - 1]);
	}
	for(int i = matrix.size() - step - 1; i > step; i--){
		inorder.push_back(matrix[matrix.size() - step - 1][i]);
	}
	for(int i = matrix.size() - step - 1; i > step; i--){
		inorder.push_back(matrix[i][step]);
	}
	vector<int> inner = spiral_help(matrix, step + 1);
	inorder.insert(inorder.end(), inner.begin(), inner.end());
	return inorder;
}
