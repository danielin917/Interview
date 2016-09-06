#include<iostream>
#include "max_stack.h"
#include "print_tree_level.h"
#include "../Binary_Trees/tree_lib.h"
#include<vector>

using namespace std;

int main(){
vector<int> a_i = {20, 0, 18, 4, 1, 13, 14, 7, 8, 9, 12, 10};/*inorder*/
vector<int> a_p = {1, 4, 0, 20, 18, 7, 13, 14, 9, 8, 10, 12};/*preorder*/
unique_ptr<BinaryTreeNode<int>> root = construct_in_pre(a_i, a_p, 0, 0, a_i.size());
vector<vector<int>> x = levels(root);

for(int i =0; i < x.size(); i++){
	for(int j = 0; j <x[i].size(); j++){
		cout << x[i][j] << " ";
	}
	cout << endl;
}
}
