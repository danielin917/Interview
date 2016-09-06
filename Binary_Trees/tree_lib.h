#pragma once
#include<iostream>
#include<memory>
#include<vector>

using namespace std;

template<typename T>
struct BinaryTreeNode{
	T data;
	unique_ptr<BinaryTreeNode<T>> left, right;
};
template<typename T>
struct BinaryTreeNode_p: BinaryTreeNode<T>{
	unique_ptr<BinaryTreeNode_p<T>> left, right;
	BinaryTreeNode_p<T>* parent;
};

template<typename T>
void print_in_order(unique_ptr<BinaryTreeNode<T>>& root ){
	if(root == nullptr)
		return;
	print_in_order(root -> left);
	cout << root -> data << " ";
	print_in_order(root -> right);
}

template<typename T>
void print_pre_order(unique_ptr<BinaryTreeNode<T>>& root ){
	if(root == nullptr)
		return;
	cout << root -> data << " ";
	print_pre_order(root -> left);
	print_pre_order(root -> right);
}
template<typename T>
int find_index(vector<T> data, T needle, int start, int length){
	for(int i = start; i < start + length; i++){
		if(data[i] == needle){
			return i;
		}
	}
	return -1;
}

template<typename T>
unique_ptr<BinaryTreeNode<T>> construct_in_pre(vector<T>& in_order, vector<T>& pre_order,
						int it, int pt, int length){/*it is the current inorder starting index, pt is the current pre_order starting index*/
	if(length == 0){
		return nullptr;
	}
	unique_ptr<BinaryTreeNode<T>> root {new BinaryTreeNode<T>};
	root -> data = pre_order[pt];
	int i_root = find_index(in_order, pre_order[pt], it, length);
	int l_length = i_root - it;
	int r_length = length - l_length - 1;
	root -> left = construct_in_pre(in_order, pre_order, it, pt + 1, l_length);
	root -> right = construct_in_pre(in_order, pre_order,i_root + 1, pt + l_length + 1, r_length);
	return root;

}

template<typename T>
unique_ptr<BinaryTreeNode_p<T>> construct_in_pre(vector<T>& in_order, vector<T>& pre_order,
						int it, int pt, int length, BinaryTreeNode_p<T>* p){/*it is the current inorder starting index, pt is the current pre_order starting index*/
	if(length == 0){
		return nullptr;
	}
	unique_ptr<BinaryTreeNode_p<T>> root {new BinaryTreeNode_p<T>};
	root -> data = pre_order[pt];
	root -> parent = p;
	int i_root = find_index(in_order, pre_order[pt], it, length);
	int l_length = i_root - it;
	int r_length = length - l_length - 1;
	root -> left = construct_in_pre(in_order, pre_order, it, pt + 1, l_length, root.get());
	root -> right = construct_in_pre(in_order, pre_order,i_root + 1, pt + l_length + 1, r_length, root.get());
	return root;

}
