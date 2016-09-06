#pragma once
#include<algorithm>
#include<iostream>
using namespace std;

int levenshtein_distance(string a, string b){
	if(a.length() == 0){
		return b.length();
	}
	if(b.length() == 0){
		return a.length();
	}
	if(a[a.length() - 1] != b[b.length() - 1]){
		/*insert*/
		int ins = levenshtein_distance(a + b[b.length() - 1], b);
		/*delete*/
		int del = levenshtein_distance(a.substr(0, a.length() - 1), b);
		/*sub*/
		a[a.length() - 1] = b[b.length() - 1];
		int sub = levenshtein_distance(a,b);
		return 1 + min(min(ins, del),sub);
	}
	else{
		return levenshtein_distance(a.substr(0,a.length()-1), b.substr(0,b.length() -1));
	}
}
/*
 *better speed
 */

int l_distance(string a, string b, vector<vector<int>>& dp){
	if(a.length() == 0){
		return b.length();
	}
	if(b.length() == 0){
		return a.length();
	}
	if(dp[a.length() - 1][a.length() - 1] == -1){
		if(a[a.length() - 1] != b[b.length() - 1]){
			/*insert*/
			int ins = levenshtein_distance(a + b[b.length() - 1], b);
			/*delete*/
			int del = levenshtein_distance(a.substr(0, a.length() - 1), b);
			/*sub*/
			a[a.length() - 1] = b[b.length() - 1];
			int sub = levenshtein_distance(a,b);
			dp[a.length() - 1][b.length() - 1] =  1 + min(min(ins, del),sub);
		}
		else{
			dp[a.length() - 1][b.length() - 1] = levenshtein_distance(a.substr(0,a.length()-1), b.substr(0,b.length() -1));
		}
	}
	return dp[a.length() - 1][b.length() - 1];
}


int l_dist(string a, string b){
	vector<vector<int>> dp;
	for(int i = 0; i < a.length(); i++){
		dp.emplace_back(vector<int>());
		for(int j = 0; j < b.length(); j++){
			dp[i].emplace_back(-1);
		}
	}
	return l_distance(a, b, dp);
}
