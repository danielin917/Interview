#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
template<typename T>
struct Node{
	Node<T>* left;
	Node<T>* right;	
	T data;
};
template<typename T>
class BinaryTree{
	Node<T>* root;
	
	Node<T>* listCreator(Node<T>* head, Node<T>*& last, Node<T>*& finalHead){
		if(head){
			listCreator(head->left, last, finalHead);
			if(last){
				last -> right = head;
				head -> left = last;
			}
			else{
				finalHead = head;
			}
			last = head;
			listCreator(head->right, last, finalHead);	
		}
		return finalHead;
	}
	void performSum(Node<T>* head, T& sumSoFar){
		if(head){
			performSum(head -> left, sumSoFar);
			
			T buf = sumSoFar;
			sumSoFar += head -> data;
			head -> data += buf;		
			
			performSum(head -> right, sumSoFar);
		}
	}
	void inOrderTraversal(Node<T>* head){
		if(head){
			inOrderTraversal(head -> left);
			cout << head -> data << " ";
			inOrderTraversal(head -> right);
		}
	}
	void inorderPrint(Node<T>* root){
		if(!root->left && !root->right){
			cout << root -> data << " ";
			return;
		}
		if(root->left)
			inorderPrint(root -> left);
		cout << root -> data << " ";
		if(root->right)
			inorderPrint(root -> right);	
	}
	void nodeInsert(Node<T>* newNode, Node<T>* treeNode){
		if(!treeNode -> left && treeNode -> data > newNode -> data){
			treeNode -> left = newNode;	
		}
		else if(!treeNode -> right && treeNode -> data <= newNode -> data){
			treeNode -> right = newNode;
		}
		else if(treeNode -> data > newNode -> data){
			nodeInsert(newNode, treeNode -> left);
		}
		else{
			nodeInsert(newNode, treeNode -> right);
		}
	}
	T minFinder(Node<T>* parent){
		
		if(parent->left == NULL){
			return parent -> data;
		}
		return minFinder(parent -> left);
	}
	int depthSearch(Node<T>* parent, int count){
		count++;
		if(!parent){
			return 0;
		}
		if(!parent->left && !parent->right){
			return count;
		}
		return max(depthSearch(parent->left, count), depthSearch(parent->right, count));
	}
	Node<T>* deleteRecursively(Node<T>* parent, T data){
		if(parent == NULL){return parent;}//value not found	
		if(data > parent -> data){parent -> right = deleteRecursively(parent -> right, data); return parent;}
		else if(data < parent -> data){parent -> left = deleteRecursively(parent -> left, data); return parent;}
		else{
			if(parent->right == NULL && parent->left == NULL){
				delete parent;
				parent = NULL;
				return parent;
			}
			else if( parent -> right == NULL){
				Node<T>* temp = parent;	
				parent = parent -> left;
				delete temp;
				return parent;
			}
			else if( parent -> left == NULL){
				Node<T>* temp = parent;	
				parent = parent -> right;
				delete temp;
				return parent;
			}
			else{
				parent -> data =  minFinder(parent->right);	
				parent -> right = deleteRecursively(parent-> right, parent->data);
				return parent;
			}
		
		}
	}		
	public:
	
	BinaryTree():root(NULL){}
	void insert(T value){
		Node<T>* newNode = new Node<T>();
		newNode -> data = value;	
		if(root){
			nodeInsert(newNode, root);
		}
		else{
			root = newNode;
		}

	}
	
	void print(){
		inorderPrint(root);
		cout << endl;
	}
	T  minValue(){
		if(root)
			return minFinder(root);
		else
			throw;
	}
	int size(){
			
	}
	int maxDepth(){
		return depthSearch(root, 0);		
	}
	void removeRoot(){
		root = deleteRecursively(root, root -> data);
	}
	void removeValue(T value){
		root = deleteRecursively(root, value);
	}
	void print2(){
		inOrderTraversal(root);
		cout << endl;
	}
	void sumTree(){
		T x;
		x -= x;	
	
		performSum(root, x);
	}
	//After this call no longer binary tree
	Node<T>*  convertToList(){
		Node<T>* last = NULL;
		Node<T>* head = NULL;
		listCreator(root, last, head);
		last -> right = NULL;
		return head;
	}
};
template<typename T>
void traverseList(Node<T>* front){
	Node<T>* i = front;
	while(i != NULL){
		cout << i-> data << " ";
		i = i -> right;
	}
	cout << endl;

}
int main(){
	BinaryTree<int> tree;
	tree.insert(5);
	tree.insert(9);
	tree.insert(4);
	tree.insert(3);
	tree.insert(2);
	tree.insert(4);
	tree.insert(4);
	tree.insert(6);
	tree.print();
	cout << tree.minValue() <<endl;
	cout << tree.maxDepth() <<endl;
	tree.removeValue(4);
	tree.print();	
	tree.insert(19);
	tree.print();
	tree.sumTree();
	tree.print2();
	Node<int>* front = tree.convertToList();
	traverseList(front);
}
