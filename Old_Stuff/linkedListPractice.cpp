#include<iostream>

using namespace std;
template<typename T>
struct Node{
	T data;
	Node<T>* next;
	Node():next(NULL){}
};

template<typename T>
class List{
	unsigned int count;
	public:
	Node<T>* head;
	
	List():head(NULL), count(0){}
	void push(T value){
		Node<T> * pushed = new Node<T>;
		pushed -> next = head;
		pushed -> data = value;
		head = pushed;
		count++;
	}
	void pop(){
		if(head){
			Node<T>* to_be_deleted = head;
			head = head -> next;
			delete to_be_deleted;
			count--;
		}
		else{
			throw;
		}
	}
	T top(){
		if(head){
			return head-> data;
		}
		else{
			throw;
		}
	}
	unsigned int size(){
		return count;
	}
};
template <typename T>
void DeleteNodesAfter(T value, Node<T>* head){
	if(!head)
		return;	
	Node<T>* present = head;

	while(present && present -> next){
		if(present->next->data == value){
			Node<T>* dead_node = present-> next;
			present -> next = present -> next -> next;
			delete dead_node;
		}
		present = present -> next;
	}

}
template <typename T>
void RemoveDuplicates(Node<T>* head){
	Node<T>* k = head;
	while(k && k-> next){
		DeleteNodesAfter(k->data, k);
		k = k -> next;
	}
}

int main(){
	int array[] ={1,5,3,7,6,3,8,6,3,2,9,9,0,2,4,23,4,7,4,8}; 
	int arrayLength = sizeof(array)/sizeof(*array);
	List<int> list;
	for(int i = 0; i < arrayLength; i++){
		list.push(array[i]);
	}
	Node<int>* i = list.head;
	while(i){
		cout << i -> data << " ";
		i = i -> next;
	}
	cout << endl;
	
	RemoveDuplicates(list.head);
	
	i = list.head;
	while(i){	
		cout << i -> data << " ";
		i = i -> next;
	}
	cout << endl;
}
