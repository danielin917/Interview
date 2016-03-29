#include<iostream>

using namespace std;

template<typename T>
int recursiveSearch(T list[], int min, int high, T value){
	if(high == min){
		if(list[min] == value)
			return min;
		else return -1;
	}
	int mid =  min + (high - min)/2;
	if(list[mid] > value){
		return recursiveSearch(list, min, mid - 1, value);
	}
	else if( list[mid] < value){
		return recursiveSearch(list, mid + 1, high, value);
	}
	else{
		return mid;
	}
}
template<typename T>
int binarySearch(T list[], T value,int length){
	return recursiveSearch(list, 0, length - 1, value);	

}


int main(){
	int array[] = {1,2,4,5,6,7,8,9,10,14,17,48};
	int loc = binarySearch(array, 11, 12);
	cout << loc <<endl;
}

