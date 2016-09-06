#include<iostream>

using namespace std;


template<typename T>
void fixup(T heap[], int heapsize, int loc){

	int target = (loc + 1)/2;
	target --;
	while(target >= 0){
		if(heap[target] < heap[loc]){
			T dummy = heap[loc];
			heap[loc] = heap[target];
			heap[target] = dummy;
		}
		else{return;}
		loc = target;
		if (target == 0){return;}
		target /= 2;
	}
}
template<typename T>
void heapify(T list[]){
	int heapsize = 0;
	int length = -1;
	while(list[++length]);

	while(heapsize < length){
		heapsize++;
		fixup(list, heapsize, heapsize - 1);
	}
}



template<typename T>
void fixDown(T heap[], int heapsize, int loc){
///////////////////////////////////////account for root = 1		
	int target = (loc + 1) * 2;
	target--;
///////////////////////////////////////
	while(target < heapsize){//because offest by one last elt will be in size place
		if(target + 1 < heapsize && heap[target + 1] > heap[target]){target++;}
		if(heap[target] > heap[loc]){
			T dummy = heap[loc];
			heap[loc] = heap[target];
			heap[target] = dummy;
		}
		else{return;}
		loc = target;
		target *= 2;
	}
	return;
}

template<typename T>
void heapsort(T list[]){
	int n = -1;
	while(list[++n]);
	int heapsize = n;
	heapify(list);
	
	for(int i = 0; i < n; i++){
		T dummy = list[0];
		list[0] = list[n - i -1];
		list[n - i - 1] = dummy;	
		fixDown(list, --heapsize, 0);
	} 
}


int main(){

	int list[] = {24,5,46,4,5,7,3,256,7,54,846,8,4,35,56,7,48,6};
	char list2[] = {'2','t','x','p','a','v','a','b','6','3','9','o','w','s'};
	heapsort(list);
	heapsort(list2);
	int length = -1;
	while(list[++length]);
	for(int i = 0; i < length; i ++){
		cout << list[i] << " ";
	}
	length = -1;
	while(list2[++length]);
	cout << endl;	
	for(int i = 0; i < length; i ++){
		cout << list2[i] << " ";
	}
}
