#include<iostream>
#include<stack>
#include<queue>
using namespace std;

template<typename T>
ostream& operator<<(ostream& out, const stack<T>& s){

	stack<T> temp= s;
	while(temp.size()){
		out <<	temp.top() << " ";		
		temp.pop();
	}
	return out;
}


template<typename T>
void permutations(queue<T>& q, stack<T>& s){
	int size = q.size();
	if(q.empty()){cout << s << '\n'; return;}
	for(unsigned int i = 0; i < size; i++){
		s.push(q.front()); q.pop();
		cout << "permcall" << i << endl;
		permutations(q, s);
		q.push(s.top()); s.pop();
	}
}


int main(){
	stack<int> mystack;
	queue<int> myqueue;
	myqueue.push(1);
	myqueue.push(9);
	myqueue.push(7);
	myqueue.push(3);
	permutations(myqueue,mystack);
}
