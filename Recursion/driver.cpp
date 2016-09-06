#include<iostream>
#include<stack>
#include<vector>
#include "towers_of_hanoi.h"
using namespace std;

int main(){
stack<int> a;

for(int i = 9; i > 0; i--){
	a.push(i);
}

stack<int> b;
stack<int> c;

towers_of_hanoi(a,b,c, 9);

while(b.size()){
	cout << b.top() << endl;
	b.pop();
}
}
