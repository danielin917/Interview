#pragma once
#include<stack>

using namespace std;

void towers_of_hanoi(stack<int>& src, stack<int>& dest, stack<int>& helper, int n){
	if(n == 0){
		return;
	}
	else if(n == 1){
		dest.push(src.top());
		src.pop();
	}
	else{
		towers_of_hanoi(src, helper, dest, n - 1);
		dest.push(src.top());
		src.pop();
		towers_of_hanoi(helper, dest, src, n -1);
	}
}

