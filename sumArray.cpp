#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

/*print all pairs that sum to value*/

void printSumPairs(int array[], int sum, int length){
	unordered_map<int, vector<int>*> hashTable;	
	for(int i = 0; i < length; i++){
		auto search = hashTable.find(array[i]);
		if(search == hashTable.end()){
			hashTable[array[i]] = new vector<int>;	
		} 
		hashTable[array[i]] -> push_back(i);
		search = hashTable.find(sum - array[i]);
		if(search != hashTable.end()){
			vector<int>* compliments = search -> second;
			for(int j = 0; j < compliments -> size(); j++){
				cout << i << ":" << (*compliments)[j];
					cout << endl;
			}
		
		}
	}
	for(auto it = hashTable.begin(); it != hashTable.end(); it++){
		delete it -> second;
	}
}

int main(){
	int array[] = {3,4,7,3,2,6,4,-1,8,5,4,6,2,-7,1,43,45,1,8,5,3,0,5,2,15,16,-5, -2, -4};
	int length = sizeof(array)/sizeof(*array);
	printSumPairs( array, 7, length);
}
