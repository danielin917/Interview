#pragma once

#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

bool anonymous_possible(string magazine, string letter){
	unordered_map<char, int> needed_letters;
	if(letter.length() == 0){
		return true;
	}
	/*fill hash table with letters we'll need*/
	for(int i = 0; i < letter.length(); i++){
		auto it = needed_letters.find(letter[i]);
		if(it == needed_letters.end()){
			needed_letters[letter[i]] = 1;
		}
		else{
			needed_letters[letter[i]]++;
		}
	}
	for(int j = 0; j < magazine.length(); j++){
		auto it = needed_letters.find(magazine[j]);
		if(it != needed_letters.end()){
			if(needed_letters[magazine[j]] == 1){
				needed_letters.erase(it);
			}
			else{
				needed_letters[magazine[j]]--;
			}
		}
		if(needed_letters.size() == 0)
			return true;
	}
	return false;

}
