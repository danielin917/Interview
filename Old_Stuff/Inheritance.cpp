#include<iostream>

using namespace std;

class Base{
	public:
	virtual int add(int x, int y){
		return x + y;
	}
	void hello(){
		cout << "base" << endl;
	}
	virtual void bye(){
		cout << "base bye" << endl;
	}
	Base(){}
	virtual void pure() = 0;

};

class Derived : public Base{
	public:
	void add(){
		cout << "add" << endl;
	}
	void hello(){
		cout << "derived" << endl;
	}
	void bye(){
		cout << "derived bye" << endl;
	}
};


int main(){
Derived d;
Derived* d_ptr = &d;
Base* b_ptr = &d;

cout << "---------------" <<endl;
d_ptr -> hello();
b_ptr -> hello();
cout << "---------------" <<endl;
d_ptr -> bye();
b_ptr -> bye();
cout << "---------------" <<endl;

}
