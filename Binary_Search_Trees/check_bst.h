#include<iostream>
#include "../Binary_Trees/tree_lib.h"
#include<memory>
#include<queue>

using namespace std;
struct Tree_Vals{
	bool bst;
	int min;
	int max;
};

int max(unique_ptr<BinaryTreeNode<int>>& root){
	if(root ->right){
		return max(root->right);
	}
	return root -> data;
}

unique_ptr<Tree_Vals> check_bst_help(unique_ptr<BinaryTreeNode<int>>& root){
	unique_ptr<Tree_Vals> L = nullptr;
	unique_ptr<Tree_Vals> R = nullptr;
	if(root -> left){
		L = move(check_bst_help(root -> left));
		if(L -> bst == false || L -> max > root -> data){
			L -> bst = false;
			return L;
		}
	}
	if(root -> right){
		R = move(check_bst_help(root -> right));
		if(R -> bst == false || R -> min < root -> data){
			R -> bst = false;
			return R;
		}
	}
	unique_ptr<Tree_Vals> C {new Tree_Vals};
	C -> min = root -> data;
	C -> max = root -> data;
	C -> bst = true;
	if(L){
		C -> min = L -> min;
	}

	if(R){
		C -> max = R -> max;
	}
	return C;

}

bool check_bst(unique_ptr<BinaryTreeNode<int>>& root){
	return check_bst_help(root) -> bst;
}

