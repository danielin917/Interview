#include<iostream>
#include<string>

using namespace std;

string DATE = "hh:mm:ss";
string PROFILE = "NAME:DAN,AGE:21,COUNTRY:USA";
int main(){

///////////////////////////////////////c++ strings/////////////////////////
	
//substr(loc, length)
string hour = DATE.substr(0,2);
string minute = DATE.substr(3,2);
string second = DATE.substr(6,2);

cout << hour << " " << minute << " " << second << endl;
string pString;
int loc = PROFILE.find(":");
pString = PROFILE.substr(loc+ 1 );

loc = pString.find(",");
string name = pString.substr(0, loc); 
loc = pString.find(":");
pString = pString.substr(loc+1);

loc = pString.find(",");
string age = pString.substr(0, loc);
loc = pString.find(":");
pString = pString.substr(loc+1);

string country = pString;

cout << name << " " << age << " " <<  country << endl;

////////////////////////////////////////c-strings//////////////////////////////



}
