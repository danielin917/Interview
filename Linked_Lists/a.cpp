#include<iostream>
using namespace std;

class x{
	public:
	virtual void foo(){cout << "hello" <<endl;}
};
class y: public x{
	public:
	virtual void foo(){cout << "bye" <<endl;}
};

int main(){
	x* obj = new y;
	obj -> foo();
}
