#include <iostream>
#include <string>
using namespace std;


////////////////////////demonstrates name hiding/////////////////
class name{
public:
virtual void foo(){
cout <<"name-hide!\n";
}
virtual void boom(){

cout << "do i pass\n";

}
};
class hider : public name{
public:
void foo(){

cout << "number2\n";
}
void boom(int x){
cout << x << "\n";
}


};

//////////Find number of tailing zeros//////////////////
int zero_tail_fac(int n){
int g = 0, h = 5;

while(n/h){

g += n/h;
h *= 5;

}

return g;
}
//////////array assignment///////////////////////////
void foo(string& x, string& y){

int j = 0;
int i = 0;
while(x[i++] = y[j++])
cout << i <<"\n";

}


int main(){
/*
hider hidden;
hidden.boom();
string a = ("abc");
string b = ("123");


char x[] = "abc";
char y[] = "123";
cout << x[4];
cout << "\n" << a[5];
foo(a,b);

*/

//cout << zero_tail_fac(5) << endl;

int i = 10;
int j = 2 ;







}
