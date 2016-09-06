#pragma once
#include<iostream>
#include"linked_list.h"
#include<memory>
using namespace std;
template<typename T>
shared_ptr<ListNode<T>> reverse(shared_ptr<ListNode<T>> head, int length){
	shared_ptr<ListNode<T>> cur = head;
	shared_ptr<ListNode<T>> fut = head;
	shared_ptr<ListNode<T>> prev = head;
	for(int i = 0; i < length; i ++){
		fut = cur -> next;
		cur -> next = prev;
		prev = cur;
		cur = fut;
	}
	head -> next = cur;
	return prev;
}
template<typename T>
void reverse_sublist(shared_ptr<ListNode<T>> sentinel, int start, int end){
	if(!sentinel -> next){
		return;
	}
	shared_ptr<ListNode<T>> cur = sentinel;
	shared_ptr<ListNode<T>> prev = sentinel;
	for(int i = 0; i < start; i++){
		prev = cur;
		cur = cur->next;
	}
	prev -> next = reverse(cur, end - start + 1);
}
