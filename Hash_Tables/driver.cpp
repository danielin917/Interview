#include<iostream>
#include<string>
#include "anonymous_note.h"
#include "nearest_repeated.h"
using namespace std;

int main(){
	string letter = "This is a letter I'd wish to write";
	string magazine = "Cool beans. This is a magazine I'd want to cut up and use to write my letter. huzzah!";
	vector<string> v = {"hi", "my", "name", "is", "bob", "hi", "what", "is", "your", "name"};
	cout << nearest_repeated(v)<<endl;
}
