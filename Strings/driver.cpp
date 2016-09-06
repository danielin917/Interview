#include<iostream>
#include "atoi.h"
#include "int_to_string.h"
#include "base_converter.h"
#include "replace_remove.h"
#include<string>
#include<limits>
using namespace std;

int main(){
	vector<char> a = {'x','x','a','a','b','x','x','a','a','x','b','x'};
	replace_remove(a,a.size()-3);
	for(int i = 0; i < a.size(); i++){
		cout << a[i] << " ";
	}
	cout << endl;
}
