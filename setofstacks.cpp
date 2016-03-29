#include<iostream>
#include<stack>
#include<vector>

using namespace std;

template<typename T>
class Setofstacks{
	unsigned int count;
	const unsigned int MAX;
	vector<stack<T>*> stack_array;
	public:
	Setofstacks():count(0),MAX(100){}
	Setofstacks(unsigned int i):count(0),MAX(i){}
	void push(T pushed){
		if(stack_array.size() == 0 || stack_array.back()->size() == MAX){
			stack_array.push_back(new stack<T>());
		}
	       	stack_array.back() -> push(pushed);	
		count++;
	}
	void pop(){
		if(stack_array.size() > 0){
			stack_array.back() -> pop();
			if(stack_array.back() -> size() == 0){
				stack<T>* droppedStack = stack_array.back();
				stack_array.pop_back();	
				delete droppedStack;
			}	
			count--;
		}
		else{
			throw;		
		}
	}
	T& top(){
		if(stack_array.size() > 0){
			return stack_array.back() -> top();		
		}
		throw;
	}
	unsigned int size(){
		return count;
	}
};

int main(){
	Setofstacks<int> myStack = Setofstacks<int>(2);
	myStack.push(2);
	myStack.push(9);
	myStack.push(30);
	myStack.push(12);
	while(myStack.size()){
		cout << myStack.top() << endl;
		myStack.pop();
	}
}
