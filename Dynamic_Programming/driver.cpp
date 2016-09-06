#include<iostream>
#include "score_combos.h"
#include "levenshtein_distance.h"
using namespace std;

int main(){
	string a = "sunday";
	string b = "saturdays";
	string x = "a";
	x = x.substr(0,0);
	//cout << x << endl;
	cout << levenshtein_distance(a,b) << endl;
	cout << l_dist(a,b) << endl;
}
