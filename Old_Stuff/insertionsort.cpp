#include<iostream>

using namespace std;

template<typename R>
void insertionSort(R list[]){
	int length = 0;
	while(list[length++]);
	length -= 1;
	for(int i = 0; i < length; i++){
		int k = i;
		while(k){
			if(list[k] < list[k-1]){	
				R dummy = list[k];
				list[k] = list[k-1];
				list[k-1] = dummy;
			}
			else{
				break;
			}
			k--;	
		}			
	}
}

template<typename T>
void printArray(T list[]){
	int length = 0;
	while(list[length++]);
	length -= 1;
	for(int i = 0; i < length; i++){
		cout << list[i] << " ";
	}
	cout <<endl;
}




int main(){

	int list1[] = {1,4,2,5,7,98,5,2,5,43,7,45,13,47,254,3,6,7,1,2,1234,3,46,5,2,42,54,97,57,45,6,7,43};
	char list2[] = {'r', '3','a','b','y','w','p','1','t','b','l','5','o'};
	
	insertionSort(list1);
	printArray(list1);
	insertionSort(list2);
	printArray(list2);

}


