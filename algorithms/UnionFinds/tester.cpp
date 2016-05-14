#include<iostream>
#include<cstdlib>
#include "quick_union.h"
#include "../timer.h"
using namespace std;

int main(){

int N = 100000;
int R = 100000;
int J = 50;
int seed = 1701;
QuickFinder q1(N);

QuickU q2(N);

QuickUWeight q3(N);

QuickUCompress q4(N);

Timer t;

/*
 *Simple test
 */
srand(seed);
t.start();
for(int i = 0; i < R; i ++){
	q1.unite(rand() % N, rand() % N);
}
for(int i = 0; i < J; i++){
	cout << "test" << i << ":" << q1.find(rand() % N, rand() % N) << endl;
}
cout << "Simple: " << t.elapsed() << " seconds" << endl;

/*
 *Tree test
 */
srand(seed);
t.start();
for(int i = 0; i < R; i ++){
	q2.unite(rand() % N, rand() % N);
}
for(int i = 0; i < J; i++){
	cout << "test" << i << ":" << q2.find(rand() % N, rand() % N) << endl;
}
cout << "Tree: " << t.elapsed() << " seconds" << endl;
/*
 *Weighted tree test
 */
srand(seed);
t.start();
for(int i = 0; i < R; i ++){
	q3.unite(rand() % N, rand() % N);
}
for(int i = 0; i < J; i++){
	cout << "test" << i << ":" << q3.find(rand() % N, rand() % N) << endl;
}
cout << "Weighted: " << t.elapsed() << " seconds" << endl;
/*
 *Compressed Weighted tree test
 */
srand(seed);
t.start();
for(int i = 0; i < R; i ++){
	q4.unite(rand() % N, rand() % N);
}
for(int i = 0; i < J; i++){
	cout << "test" << i << ":" << q4.find(rand() % N, rand() % N) << endl;
}
cout << "Compressed: " << t.elapsed() << " seconds" << endl;

}

