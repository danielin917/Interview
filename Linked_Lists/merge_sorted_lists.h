#pragma once
#include<iostream>
#include "linked_list.h"
using namespace std;

template<typename T>
my_list<T> merge_sorted(my_list<T> a_lst, my_list<T> b_lst){
	shared_ptr<ListNode<T>> it_a = a_lst.get_sentinel();
	shared_ptr<ListNode<T>> it_b = b_lst.get_sentinel();
	shared_ptr<ListNode<T>> prev_a = it_a;
	it_a = it_a -> next;
	it_b = it_b -> next;
	while(it_a && it_b){
		if(it_a -> data <= it_b -> data){
			prev_a = it_a;
			it_a = it_a -> next; /*a is lowest so iterate a */
		}
		else{ /*place b listitem in a list before it_a*/
			prev_a -> next = it_b;
			shared_ptr<ListNode<T>> merged_b = it_b;
			it_b = it_b -> next;
			merged_b -> next = it_a;
			prev_a = merged_b;//remember to reset prev_a
		}
	}
	if(it_b){
		prev_a -> next = it_b; /* b list not finished attach it to end of merged list*/
	}
	return a_lst;
}
