#pragma once

#include<stack>

using namespace std;
/*
 *We could save time by only saving new maxes and maintaining a count of them
 *trying to push a number lower than the current max would not effect max cache
 */

template<typename T>
class Max_Stack{
stack<T> vals;
stack<T> max_vals;
public:
	void push(T data){
		vals.push(data);
		if(max_vals.empty() || data > max_vals.top()){
			max_vals.push(data);
		}
		else{
			max_vals.push(max_vals.top());
		}
	}
	T pop(){
		max_vals.pop();
		T ret = vals.top();
		vals.pop();
		return ret;
	}
	T max(){
		return max_vals.top();
	}
};
