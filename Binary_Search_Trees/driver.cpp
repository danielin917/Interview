#include<iostream>
#include "../Binary_Trees/tree_lib.h"
#include "check_bst.h"

using namespace std;

int main(){
	vector<int> a = {4,2,5,1,6,3,7};
	vector<int> b = {1,2,4,5,3,6,7};
	unique_ptr<BinaryTreeNode<int>> r = construct_in_pre(a, b, 0, 0, a.size());
	cout << check_bst(r) << endl;
}
