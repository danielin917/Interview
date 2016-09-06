#pragma once

#include<iostream>
#include<cassert>

using namespace std;


/*
 *Takes too long takes M unions on N objects
 */
class QuickFinder{
	/*
	 *p and q are connected if they have the same id
	 */	
	int* id_array;	
	int size;
	public:
	QuickFinder(int n){
		id_array = new int[n];
		size = n;
		for(int i = 0; i < n; i++)
			id_array[i] = i;
	}
	bool find(int p, int q){	
		assert(p < size && q < size);
		return(id_array[p] == id_array[q]);
	}
	void unite(int p, int q){
		assert(p < size && q < size);
		int x = id_array[p];
		for(int i = 0; i < size; i++)
		{
			if(x == id_array[i])
			{
				id_array[i] = id_array[q];
			}	
		}	
	}
};


/*
 *Still too slow, worst case N complexitt for find
 */

class QuickU{
	/*
	 * tree[i] is  parent of i
	 */
	int* tree;
	int size;
	
	int root(int p)
	{
		assert(p < size);
		int root = tree[p];
		while(root != p){
			p = root;
			root = tree[p];
		}
		return root;
	}	
	public:
	QuickU(int n)
	{
		tree = new int[n];
		size = n;
		for(int i = 0; i < n; i++)
		{
			tree[i] = i;
		}
	}
	
	bool find(int p, int q)
	{
		assert(p < size && q < size);
		return(root(p) == root(q));	
	}
	/*
	 *Append q tree to the root of p
	 */	
	void unite(int p, int q)
	{	
		assert(p < size && q < size);
		tree[root(q)] = root(p);
	}


};
/*
 *Quick union while avoiding tall trees based on tree weight, this way the least amount of nodes have length added to their path to the root
 */
class QuickUWeight{
	int* tree;
       	int* weight;
	int size;
		
	int root(int p)
	{
		assert(p < size);
		int root = tree[p];
		while(root != p){
			p = root;
			root = tree[p];
		}
		return root;
	}	
	public:
	QuickUWeight(int n)
	{
		tree = new int[n];
		weight = new int[n];
		size = n;
		for(int i = 0; i < n; i++)
		{
			tree[i] = i;
			weight[i] = 1;
		}
	}
	
	bool find(int p, int q)
	{
		assert(p < size && q < size);
		return(root(p) == root(q));	
	}
	
	/*
	 *Append the smaller tree to the root of the larger tree
	 */
	void unite(int p, int q)
	{	
		assert(p < size && q < size);
		int i = root(q);
		int j = root(p);
		if(weight[i] < weight[j]){
			tree[i] = j;
			weight[j] += weight[i];	
		}
		else{
			tree[j] = i;
			weight[i] += weight[j];
		}	
	}			

};
/*
 *Still use weight to decide on which trees to combine but now compress tree branches on root queries
 */
class QuickUCompress{	
	int* tree;
       	int* weight;
	int size;
	/*we compress root as we query down*/
	int rootAndCompress(int p)
	{
		assert(p < size);
		int root = tree[p];
		if(root == p)
			return root;
		else{
			tree[p] = rootAndCompress(root);
			return tree[p];
		}
	}	
	public:
	QuickUCompress(int n)
	{
		tree = new int[n];
		weight = new int[n];
		size = n;
		for(int i = 0; i < n; i++)
		{
			tree[i] = i;
			weight[i] = 1;
		}
	}
	
	bool find(int p, int q)
	{
		assert(p < size && q < size);
		return(rootAndCompress(p) == rootAndCompress(q));	
	}
	
	/*
	 *Append the smaller tree to the root of the larger tree
	 */
	void unite(int p, int q)
	{	
		assert(p < size && q < size);
		int i = rootAndCompress(q);
		int j = rootAndCompress(p);
		if(weight[i] < weight[j]){
			tree[i] = j;
			weight[j] += weight[i];	
		}
		else{
			tree[j] = i;
			weight[i] += weight[j];
		}	
	}			
};
