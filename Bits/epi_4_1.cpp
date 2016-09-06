#include<iostream>

using namespace std;


int mod_p_two(int x, int pow);
int propagate_right_most(int x);
bool check_power_of_two(int x);

int main(){
	int x = 63;
	int result = check_power_of_two(x);
	cout << result << endl;
}


int propagate_right_most(int x){
	/*propagated right but now the highest bit is 0 */
	int y = x - 1;
	return y | x;	
}

int mod_p_two(int x, int pow){
	/*propagate the bits right(since power of two only one bit was initially set)*/
	int exp_p = pow - 1;
	return exp_p & x;
	
}
/*basically we are checking if there is more than 1 bit flipped*/
bool check_power_of_two(int x){
	if(x == 0){
		return false;
	}
	int y = x &~(x-1);
	if(y == x){
		return true;
	}
	else{
		return false;
	}
}
