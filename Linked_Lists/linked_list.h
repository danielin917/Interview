#pragma once
#include<memory>
#include<vector>
using namespace std;

template <typename T>
struct ListNode {
	T data;
	shared_ptr<ListNode<T>> next;
};
template <typename T>
class my_list{
	shared_ptr<ListNode<T>> sentinel;
public:
	my_list(): sentinel(shared_ptr<ListNode<T>>{new ListNode<T>}){
		sentinel -> next = nullptr;
	}
	my_list(const vector<T>& init_vec): sentinel(shared_ptr<ListNode<T>>{new ListNode<T>}){
		sentinel -> next = nullptr;
		for(int i = 0; i < init_vec.size(); i++){
			push_front(init_vec[init_vec.size() - i -1]);
		}
	}
	my_list(shared_ptr<ListNode<T>> head){
		sentinel->next = head;
	}
	void push_front(T _data){
		shared_ptr<ListNode<T>> n {new ListNode<T>};
		n -> data = _data;
		n -> next = sentinel -> next;
		sentinel -> next = n;
	}
	void pop_front(){
		if(sentinel -> next -> next){
			sentinel -> next = sentinel -> next -> next;
		}
		else{
			sentinel -> next = nullptr;
		}
		/*If we weren't using smart pointers we would have to
 		*destroy our front object
 		*/
	}
	shared_ptr<ListNode<T>> find(T target){
		shared_ptr<ListNode<T>> f = sentinel -> next;
		while(f){
			if(f -> data == target)
				return f;
			f = f->next;
		}
		return nullptr;
	}
	shared_ptr<ListNode<T>> get_sentinel(){
		return sentinel;
	}
};

/*Smart pointers ensure object is destroyed resulting in no memory leaks
 *
 *unique_ptrs are moved while shared_ptrs are copied
 *
 */
