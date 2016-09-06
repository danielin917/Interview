#include<iostream>
#include<string>
#include<limits>
using namespace std;
/*abs() is contained in <cmath> library*/
int my_abs(int x){
	if(x < 0){/* remember the possibility over overflow */
		x *= -1;
	}
	return x;
}

void char_swap(char& a, char& b){
	char z = a;
	a = b;
	b = z;
}
void reverse_string(string& str){
	for(int i = 0; i < str.length()/2; i++){
		char_swap(str[i], str[str.length() - i - 1]);
	}
}

string int_to_string(int num){
	if(num == 0){
		return "0";
	}
	bool neg = num < 0;
	string num_str;
	while(num){
/*
 *We abs the modded number so we don't overflow, we could do a special case where we only do one
 *extra operation but this is simpler and does not cost much extra
 */
		char letter = '0' + my_abs(num % 10);
		num_str += letter;
		num /= 10;
	}
	if(neg){
		num_str += '-';
	}
	reverse_string(num_str);
	return num_str;
}
