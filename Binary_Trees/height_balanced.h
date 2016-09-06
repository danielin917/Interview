#pragma once
#include<iostream>
#include<memory>
#include<algorithm>
#include<cmath>
#include "tree_lib.h"

using namespace std;

template<typename T>
bool height_balanced(unique_ptr<BinaryTreeNode<T>>& root){
	return height_helper(root) != -1;
}
template<typename T>
int height_helper(unique_ptr<BinaryTreeNode<T>>& root){
	if(root == nullptr)
		return 0;
	int left = height_helper(root->left);
	int right = height_helper(root->right);
	if(left == -1 || right == -1 || abs(left -right) >= 2)
		return -1;
	return max(right, left) + 1;
}
