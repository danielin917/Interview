#include<iostream>
#include<cstdlib>
using namespace std;

int StepPerm(int N);
int main(int argc, char* argv[]){
	cout << StepPerm(atoi(argv[1]));


}
//assumes if N is given as 0 then 1 is expected
int StepPerm(int N){
	if(N < 0)
		return 0;
	else if(N == 0){
		return 1;
	}
	return StepPerm(N-1) + StepPerm(N-2) + StepPerm(N-3);
}
