#pragma once
#include<iostream>
#include "../Binary_Trees/tree_lib.h"
#include<stack>
using namespace std;

/*O(H) search for the key*/
void path_finder(BinaryTreeNode<int>*  root, int key, stack<BinaryTreeNode<int>*>& path){
	while(root != nullptr){
		if(root->data == key){
			path.push(root);
			return;
		}
		else if(root->data < key){
			path.push(root);	
			root = root -> right.get();
		}
		else{
			path.push(root);
			root = root->left.get();
		}
	}
}
int bst_min(BinaryTreeNode<int>* root){
	int min = root->data;
	while(root->left){
		root = root -> left.get();
		min = root -> data;
	}
	return min;
}

int find_greater(unique_ptr<BinaryTreeNode<int>>& root, int key){
	BinaryTreeNode<int>* r = root.get();
	stack<BinaryTreeNode<int>*> path;
	path_finder(r, key, path);
	while(path.size()){
		BinaryTreeNode<int>* check =  path.top();
		path.pop();
		if(check->right){
			return bst_min(check->right.get());
		}
		else if(path.top() -> data > check -> data){
			return path.top() -> data;
		}
	}
	return key;
}
