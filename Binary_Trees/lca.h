#include <iostream>
#include<cmath>
#include "tree_lib.h"

using namespace std;

template<typename T>
int get_depth(BinaryTreeNode_p<T>* node){
	int depth = 0;
	while(node = node -> parent){depth++;}
	return depth;
}
template<typename T>
BinaryTreeNode_p<T>*lowest_common(const unique_ptr<BinaryTreeNode_p<T>>& node1_,
																const unique_ptr<BinaryTreeNode_p<T>>& node2_){
	BinaryTreeNode_p<T>* node1 = node1_.get();
	BinaryTreeNode_p<T>* node2 = node2_.get();

	int depth1 = get_depth(node1);
	int depth2 = get_depth(node2);
	int difference = depth1 - depth2;
	if(difference < 0){
		swap(node1, node2);
		difference = -difference;
	}
	while(difference){
		node1 = node1->parent;
		difference--;
	}
	while(node1 != node2){
		node1 = node1-> parent;
		node2 = node2-> parent;
	}
	return node1;
}

