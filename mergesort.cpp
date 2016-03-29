#include<iostream>

using namespace std;

template<typename T>
void merge(T left[], T right[], T array[], int totalLength){
	
	int leftLength = totalLength/2 + totalLength % 2;
	int lCount = 0;
	int rCount = 0;

	for(int i = 0; i < totalLength; i++){
		if(rCount == totalLength/2 ||( lCount < leftLength && left[lCount] < right[rCount])){
			array[i] = left[lCount]; 
			lCount ++;
		}
		else{
			array[i] = right[rCount];
			rCount++;
		}
	}
}
template<typename T>
void mergesort(T array[], int length){
	if(length == 1)
		return;
	int leftLength = length/2 + length % 2;
	T* left = new T [leftLength];
	T* right = new T [length/2];
	for(int i = 0; i < leftLength; i++){
		left[i] = array[i];
	}
	for(int j = leftLength; j < length; j++){
		right[j - leftLength] = array[j];
	}

	mergesort(left,leftLength);
	mergesort(right, length/2);
	merge(left, right,array, length); 	
	delete[] left;
	delete[] right;
}
int main(int argc, char* argv[]){

int list[] = {1,4,5,4,8,9,6,2,43,4,7,8,5,6,9,3,23,75,8,12,3,7,56,4}; 
int length = sizeof(list)/sizeof(*list);

mergesort(list, length);

for(int i = 0; i < length; i++){
	cout << list[i] << " ";
}
cout << endl;

}



	



