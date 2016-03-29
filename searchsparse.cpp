#include<iostream>
#include<string>
#include<vector>

using namespace std;

int findrecursively(string target, vector<string> list, int min, int max){
	if(min == max)
		return -1;
	int mid = min + (max - min)/2;
	int i = mid;
	bool midBelow = false;	
	while(list[i] == "" && i <= max){i++;}
	if(i > max){
		i = mid;
		while(list[i] == "" && i >= min){i--;}
		if(i < min){	
			cout << "can't find";
			return -1;
		}
	}

	if(list[i] < target)
		min = midBelow ? mid + 1 : i + 1;
	else if(list[i] > target)
		max = midBelow ? i - 1 : mid - 1;
	else{
		return i;
	}
	return findrecursively(target, list, min, max);


}

int find(string target, vector<string> list){
	int loc = findrecursively(target, list, 0, list.size() - 1);	
	return loc;
}
int main(){
vector<string> sparse;
sparse.push_back("a");
sparse.push_back("");
sparse.push_back("");
sparse.push_back("");
sparse.push_back("");
sparse.push_back("");
sparse.push_back("");
sparse.push_back("b");
sparse.push_back("");
sparse.push_back("");
sparse.push_back("c");
sparse.push_back("");
sparse.push_back("");
sparse.push_back("");
sparse.push_back("");
sparse.push_back("d");
sparse.push_back("");
sparse.push_back("");
sparse.push_back("");
sparse.push_back("");
sparse.push_back("");
sparse.push_back("e");
sparse.push_back("");
sparse.push_back("");
sparse.push_back("");
sparse.push_back("");
sparse.push_back("");
sparse.push_back("");
sparse.push_back("f");
sparse.push_back("");
sparse.push_back("");
sparse.push_back("");
sparse.push_back("");
sparse.push_back("");
sparse.push_back("g");
sparse.push_back("");
sparse.push_back("");
sparse.push_back("");
sparse.push_back("");
sparse.push_back("h");
int loc = find("d", sparse);

cout << loc << endl;
}
