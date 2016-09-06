#include<iostream>
#include<vector>
#include<queue>
#include "../Binary_Trees/tree_lib.h"
using namespace std;

vector<vector<int>> levels(unique_ptr<BinaryTreeNode<int>>& root){
	queue<unique_ptr<BinaryTreeNode<int>>*> q;
	vector<vector<int>> array;
	vector<int> level;
	q.push(&root);
	q.push(nullptr);
	while(q.size()){
		unique_ptr<BinaryTreeNode<int>>* x = q.front();
		q.pop();
		if(x){
			level.emplace_back((*x)->data);
			if((*x)->left){
					q.push(&(*x)->left);
			}
			if((*x)->right){
				q.push(&(*x)->right);
			}
		}
		else{
			array.emplace_back(level);
			if(q.size()){
				q.push(nullptr);
				level = {};
			}
			else{
				break;
			}
		}
	}
	return array;
}
