#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<string.h>
using namespace std;

void reverse(char* str);
int main(int argc, char* argv[]){
	char* message = argv[1];
	reverse(message);
	cout << message << '\n';
}
void reverse(char* str){
	int length = strlen(str);
	char x;
	for (unsigned int i = 0; i < length/2; i++){
		x = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = x;
	}
}
