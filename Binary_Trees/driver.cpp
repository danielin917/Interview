#include<iostream>
#include<vector>
#include<memory>
#include "height_balanced.h"
#include "tree_lib.h"
#include "lca.h"
#include <queue>
using namespace std;


int main(){
	vector<int> a_i = {13,4,2,9,5,10,8,12,11,1,6,3,7};/*inorder*/
	vector<int> a_p = {1,2,4,13,5,9,8,10,11,12,3,6,7};/*preorder*/
	BinaryTreeNode_p<int>* parent = nullptr;
	unique_ptr<BinaryTreeNode_p<int>> root_a = construct_in_pre(a_i, a_p, 0, 0, a_i.size(), parent);

	//cout << height_balanced(root_a) << endl;

	vector<int> b_i = {9, 4, 10, 3, 6, 5, 7, 8};
	vector<int> b_p = {3, 4, 9, 10, 5, 6, 7, 8};
	unique_ptr<BinaryTreeNode<int>> root = construct_in_pre(b_i, b_p, 0, 0, b_i.size());
	BinaryTreeNode_p<int>* n1 = root_a.get();
	n1 = n1->left.get();
	BinaryTreeNode_p<int>* n2 = n1;
	n1 = n1->left.get();
	n2 - n2->right.get();
	n2 = n2->right.get();
	n2 = n2->right.get();
	BinaryTreeNode<int>* val = lowest_common(n1->left, n2->left);
	cout << val-> data << endl;
}
