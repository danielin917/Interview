#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
template<typename T>
class comp{
	public:
bool operator()(T x,T y ){
	return x < y *y%2;
}

};


int main(){

vector<int> nums;
nums.push_back(9);
nums.push_back(1);
nums.push_back(4);
nums.push_back(5);
nums.push_back(2);
nums.push_back(11);

sort(nums.begin(), nums.end(), comp<int>());

for(int i = 0; i < nums.size(); i++){
	cout << nums[i] << " ";
}
cout << endl;

}
