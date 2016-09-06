#pragma once
#include "linked_list.h"
#include "memory"
using namespace std;


template<typename T>
shared_ptr<ListNode<T>> cyclic_test(shared_ptr<ListNode<T>> head){
	shared_ptr<ListNode<T>> fast = head;
	shared_ptr<ListNode<T>> slow = head;
	bool started = false;
	while(slow != fast || !started){
		started = true;
		if(fast && fast->next){
			fast = fast->next->next;
			slow = slow->next;
		}
		else{
			break;
		}
	}
	if(slow != fast){
		return nullptr;
	}
	/*a cycle does exist*/
	shared_ptr<ListNode<T>> probe  = head;
	while(probe != slow){
		probe = probe-> next;
		slow = slow-> next;
	}
	return probe;
}
