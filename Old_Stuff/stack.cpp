#include<iostream>

using namespace std;


template<typename T>
class Node{
	public:
	T data;
	Node * next;
};
template<typename T>
class Stack{
	Node<T> * front;
	unsigned int count;
	public:
	Stack(): front(NULL), count(0){}
	void push(T value){
		Node<T>* pushed = new Node<T>();		
		pushed -> next = front;
		pushed -> data = value;
		front = pushed;
		count ++;
	}
	void pop(){
		if(front){	
			T value = front -> data;
			Node<T> * popped = front;
			front = front -> next;
			delete popped;	
		}
		else{
			throw;		
		}
		count --;
	}
	T& top(){
		if(front)
			return front -> data;
		else
			throw;
	}
	unsigned int size(){
		return count;
	}
};

int main(){
	Stack<int> myStack;
	int x = 2;
	myStack.push(x);
	myStack.push(x);
	myStack.push(4);
	myStack.push(9);
	myStack.push(0);
	while(myStack.size()){
		x = myStack.top();
		cout << x << endl;
		myStack.pop();
	}
}
