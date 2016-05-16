#include<iostream>

using namespace std;
void swap(int& a, int& b){
	int x = a;
	a = b;
	b = x;
}
void rotate_array(int r, int* array, int size){
	int step = r % size;
	int* storage = new int[step];
	/*
	 *fill storage(plan ahead for deleted spots)
	 */
	for(int i = 0; i < step; i++)
	{
		storage[i] = array[i];
	}
	for(int i = 0; i < size; i++)
	{
		swap(array[(i + step) % size], storage[i % step]);
	}	
}

int main(){

	int a[] = {1,2,3,4,5,6,7,8,9};
	int length = sizeof(a)/sizeof(*a);
	rotate_array(3, a, length);
	for(int i = 0; i < length; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}
