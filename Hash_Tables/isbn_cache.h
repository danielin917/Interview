#include<iostream>
#include<unordered_map>
#include<list>
#include<memory>
#include<string>

using namespace std;


template<typename T>
struct l_node{
	T val;
	shared_ptr<my_list_node> next;
	weak_ptr<my_list_node> prev;
}

class Disk{
unordered_map<string, int> data;

int get_price(string isbn){
	if(data.find(isbn) != data.end()){
		return data[isbn];
	}
	else{
		return -1;
	}
}
void save_price(string isbn, int price){
	data[isbn] = price;
}
};

class Isbn_Cache{
size_t size;
unordered_map<string, l_node*> cache;
l_node* front;
l_node* back;
void insert(string isbn, int price){
	
}
void remove(string isbn){

}
int lookup(){

}

};
