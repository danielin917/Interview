#include <iostream>

using namespace std;

int main(){
	int a = 2;
	int * b = &a;
	cout << "int:" << sizeof(int) << '\n';
	cout << "double:" << sizeof(double) << '\n';
	cout << "Pointer:" << sizeof(b) << '\n';
	cout << "Short:" << sizeof(short) << '\n';
	return 0;
}
