#include<iostream>

using namespace std;

template<typename T>
void pushBack(T arr[], int frontLen, int totalLen){
	for(int i = 1; i <= frontLen; i++){
		arr[totalLen - i] = arr[frontLen - i];
	}
}
template<typename T>
void merger(T dest[],int totalLength, T src[], int sourceLength){

	int dLength = totalLength - sourceLength;

	pushBack(dest, dLength, totalLength);
	
	int dCount = 0, sCount = 0;
	for(int i = 0; i < totalLength; i++){
		if(sCount == sourceLength || (dCount != dLength && dest[dCount + sourceLength] < src[sCount])){
		
			dest[i] = dest[dCount + sourceLength];
			dCount++;
		}
		else if(dest[dCount + sourceLength] >= src[sCount]){
		
			dest[i] = src[sCount];
			sCount++;
		}
	}
}


int main(){

	int array1[] = {1,2,4,5,6,9,14,36,0,0,0,0,0,0};
	int array2[] = {5,6,9,11,15,17};
	merger(array1, 14,  array2, 6);
	
	int length = sizeof(array1)/sizeof(*array1);
	
		for(int j = 0; j < length; j++){
			cout << array1[j] << " " << flush;
		}
	cout << endl;
}
