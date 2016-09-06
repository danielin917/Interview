#include<iostream>
#include<list>
#include<cstring>

using namespace std;

template<typename T>
class Hashobject{
	char* key;
	T value;
	public:
	char* get_key(){
		return key;
	}
	T& get_value(){
		return value;
	}
	Hashobject(char* k, T v): key(k), value(v){}
};

template<typename T>
class Hashtable{
	int TABLE_SIZE;
	list<Hashobject<T> >** table;
	int getIndex(char* key){
		int keyLen = strlen(key);
		int index = 0;
		for(int i = 0; i < keyLen; i++){
			index += (int)key[i];
		}	
		index %= TABLE_SIZE;
		return index;
	}
	public:
	void put(char* key, T value){
		int index = getIndex(key);
		Hashobject<T> pushed_value = Hashobject<T>(key, value);
		if(table[index] == NULL)
			table[index] = new list<Hashobject<T> >();
		table[index] -> push_back(pushed_value);
	}
	T& get(char* key){
		int index = getIndex(key);
		for(typename list<Hashobject<T> >::iterator it = table[index] -> begin(); it != table[index] -> end(); it++){
			if((*it).get_key() == key){
				return(*it).get_value();
			} 
		}
	}
	Hashtable():TABLE_SIZE(200){
		table = new list<Hashobject<T> >*[200];
		for(int i = 0; i < TABLE_SIZE; i++){
			table[i] = NULL;
		}
	}
	Hashtable(int init):TABLE_SIZE(init){
		table = new list<Hashobject<T> >*[init];
		for(int i = 0; i < TABLE_SIZE; i++){
			table[i] = NULL;
		}
	}

};

int main(){
Hashtable<int> h = Hashtable<int>(10);

h.put("hello", 19);
h.put("bye", 2);
h.put("yo", 6);
h.put("sup", 1);
h.put("dawg", 43);
h.put("nah", 54);
h.put("foo", 3);
h.put("bar", 25);
cout << h.get("hello")<< endl;
cout << h.get("bye")<< endl;
cout << h.get("yo")<< endl;
cout << h.get("sup")<< endl;
cout << h.get("dawg")<< endl;
cout << h.get("nah")<< endl;
cout << h.get("foo")<< endl;
cout << h.get("bar")<< endl;


}
