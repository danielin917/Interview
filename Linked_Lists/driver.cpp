#include<iostream>
#include<vector>
#include "linked_list.h"
#include "merge_sorted_lists.h"
#include "reverse_sublist.h"
#include "find_cycle.h"
using namespace std;

int main(){
	vector<int> a ={1,5,8,12,25,48,69,78,81,91};
	vector<int> b ={0,1,5,6,7,9,12,23,34,54,61,71,89,500};
	my_list<int> a_list(a);
	my_list<int> b_list(b);
	shared_ptr<ListNode<int>> a_ptr = a_list.get_sentinel();
//	reverse_sublist(a_ptr, 3, 7);

	shared_ptr<ListNode<int>> point1 = a_list.find(81);
	shared_ptr<ListNode<int>> point2 = a_list.find(12);
	point1 -> next = point2;
	shared_ptr<ListNode<int>> cycle = cyclic_test(a_ptr);
	if(cycle){
		while(cycle){
			cout << cycle -> data << endl;
			cycle = cycle->next;
			if(cycle -> data == 12)
				break;
		}
	}
	else{
		cout << "no cycle in list" << endl;
	}
}
