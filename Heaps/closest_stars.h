#pragma once
#include<queue>
#include<cmath>
#include<vector>
using namespace std;

struct Coord{
int x, y, z;
};

double square_root(double x){
	double U = x;
	double L = 0;
	double root = U/2;
	while(abs((root*root) - x) > 0.00001){
		if(root*root < x){
			L = root;
		}
		else{
			U = root;
		}
		root = L + (U - L)/2;
	}
	return root;
}
struct Star: public Coord{
	int x,y,z;
	double dist;
	Star(Coord a): x(a.x), y(a.y), z(a.z){
		dist = square_root(x*x + y*y + z*z);
	}
};


class starcmp{
public:
bool operator()(const Star& a, const Star& b) const{
	return a.dist < b .dist;
}
};

vector<Star> k_closest(vector<Coord> file, int k){
priority_queue<Star,vector<Star>, starcmp> pq;
for(int i = 0; i < file.size(); i++){
	Star s(file[i]);
	pq.push(s);
	if(pq.size() > k){
		pq.pop();
	}
}
vector<Star> vec;
while(pq.size()){
	vec.emplace_back(pq.top());
	pq.pop();
}
return vec;
}
