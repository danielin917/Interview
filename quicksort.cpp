#include<iostream>
#include<ctime>//time
#include<cstdlib>//rand

using namespace std;

template <typename T>
int binarySearch(T value, T array[], int lo, int hi){
	int index = -1;
	if( lo == hi){
		if(array[lo] == value){
			return lo;
		}
		else{
			return -1;	
		}
	}
	
	int halfPoint = (hi - lo)/2 + lo;
	if(array[halfPoint] == value){
		return halfPoint;	
	}
	else if(array[halfPoint] > value){
		index = binarySearch(value, array, lo, halfPoint - 1); 
	}
	else{
		index = binarySearch(value, array, halfPoint + 1, hi);
	}
	return index;
}
template <typename T>
int partition(T array[], int lo, int hi){
	T pivot_val = array[hi];
       	int swap_index = lo; 

	for(int i = lo; i < hi; i++){
		if(array[i] <= pivot_val){
			T exchange = array[i];
			array[i] = array[swap_index];
			array[swap_index] = exchange;
			swap_index++;
		}
	}
	T swapper = array[swap_index];
	array[swap_index] = array[hi];
	array[hi] = swapper;

	return swap_index;
}

template <typename T>
void quicksort(T array[], int lo, int hi){	
	if(lo >= hi)
		return;
	int secondHalf = partition(array, lo, hi);		

	quicksort(array, secondHalf + 1, hi);
	quicksort(array, lo, secondHalf - 1);
}

int main(){
	int array[] = {2,6,4,7,8,9,5,0,3,2,1,6,7,4,9,6,8,90,4,6,34,346,47,85,7,6,456,23,25,45,8,54,54,5,8,23}; 
	int length = sizeof(array)/sizeof(*array);
	quicksort(array, 0, length - 1);
	for(int i = 0; i < length; i++){
		cout << array[i] << " ";
	
	}
	cout << endl;

	cout << binarySearch(456, array, 0, length -1) << endl;
}
