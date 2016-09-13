#include<iostream>
#include "maze_search.h"
#include "check_if_produces.h"
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

int main(){
	int height;
	string eol;
	vector<vector<bool>> bitmap;
	cin >> height;
	getline(cin, eol);
	for(int i = 0; i < height; i++){
		string line;
		string token;
		bitmap.push_back(vector<bool>());
		getline(cin, line);
		stringstream ss(line);
		while(getline(ss, token, ' ')){
			cout << token << " ";
			bitmap[i].push_back(token != "0");
		}
		cout << endl;
	}
	vector<Coord> path = maze_search(bitmap, Coord{0, 5}, Coord{7, 23});
	cout << path.size() << endl;
	for(int j = 0; j < path.size(); j ++){
		cout << path[j].first << ":" << path[j].second << endl;
	}
}
