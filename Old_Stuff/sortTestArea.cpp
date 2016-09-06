#include<iostream>


using namespace std;


//////////////////////////Testing Area Delete All Answers When Done//////////////////////////////


////////////////////////////////////Binarysearch/////////////////////////////////////////////////


////////////////////////////////////Selectionsort////////////////////////////////////////////////

////////////////////////////////////Insertionsort////////////////////////////////////////////////

////////////////////////////////////Heapsort/////////////////////////////////////////////////////

////////////////////////////////////Mergesort////////////////////////////////////////////////////
template <typename T>
void merge(T largeArray[], T leftArray[], T rightArray[], int leftLength, int rightLength){
	int leftNext = 0, rightNext = 0;
	for(int i = 0; i < (rightLength + leftLength); i++){
		if(leftNext == leftLength || rightNext < rightLength && leftArray[leftNext] > rightArray[rightNext]){
			largeArray[i] = rightArray[rightNext];
			rightNext++;
		}
		else{
			largeArray[i] = leftArray[leftNext];
			leftNext++;
		}
	}
}
template <typename T>
void mergeSort(T array[], int length){
	if(length == 1)
		return;
	bool isOdd = (length % 2) == 1;
	int leftLength = length/2;
	int rightLength = isOdd ? length/2 + 1 : length/2;
	T* leftArray = new T[leftLength];
	T* rightArray = new T[rightLength];
	for(int i = 0; i < leftLength; i++){
		leftArray[i] = array[i];
	}
	for(int j = 0; j < rightLength; j++){
		rightArray[j] = array[leftLength + j];
	}
	mergeSort(leftArray, leftLength);
	mergeSort(rightArray, rightLength);
	merge(array, leftArray, rightArray, leftLength, rightLength);
	delete leftArray;
	delete rightArray;
}
template <typename T>
int partition(T array[], int lo, int hi){
	T pivot = array[hi];
	int i = lo;
	for(int j = lo; j < hi; j++){
		if(array[j] < pivot){
			T dummy = array[j];
			array[j] = array[i];
			array[i] = dummy;
			i ++;
		}
	}
	T dummy = array[hi];
	array[hi] = array[i];	
	array[i] = dummy;
	return i;
}

template <typename T>
void quicksort(T array[], int lo, int hi){	
	if(lo >= hi)
		return;
	int pivot = partition(array, lo, hi);
	quicksort(array, lo, pivot - 1);
	quicksort(array, pivot + 1, hi);
	
}


////////////////////////////////////Quicksort////////////////////////////////////////////////////

int main(){

	int array1[] = {7,1,34,64,7,14,3,9,7,0,325,1,52,4,8,9,53,2,85,18,38,6,3,157,73,53,278,2,6,4};
	char array2[] = {'a','c','y','1','q','r','v','s','t','q','j','t','l'};

	int length1 = sizeof(array1)/sizeof(*array1);
	int length2 = sizeof(array2)/sizeof(*array2);

	//mergeSort(array1, length1);
	quicksort(array1, 0, length1 -1);
	for(int i = 0; i < length1; i++){
		cout << array1[i] << " ";
	}
	cout << endl;

}
