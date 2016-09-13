#pragma once
#include<set>
#include<unordered_map>
#include<string>
#include<unordered_set>

using namespace std;

bool check_transform(string s, string t){
	int count = 0;
	for(int i = 0; i < s.length(); i++){
		if(s[i] == t[i])
			count++;
		if(count > 1)
			return false;
	}
	return true;
}

unordered_map<string, unordered_set<string>> create_graph(const set<string>& D){
	unordered_map<string, unordered_set<string>> graph;
	for(auto it = D.begin(); it != D.end(); ++it){
		for(auto ir = it; ir != D.end();){
			++ir;
			if(check_transform(*ir,*it)){
				graph[*it].emplace(*it);
			}
		}
	}
	return graph;
}
bool dfs(const string& start, const string& target, unordered_map<string, unordered_set<string>>& graph){
	bool ret = 0;
	if(target == start){
		return true;
	}
	for(auto it = graph[start].begin(); it != graph[start].end(); it++){
		string search = *it;
		graph[start].erase(it);
		ret |= dfs(search, target, graph);
	}
	return ret;
}
int check_if_produces(string s, string t, const set<string>& D){
	if(s.length() != t.length()){
		return (s.length() - t.length());
	}
	set<string> D_avail;
	for(auto it = D.begin(); it != D.end(); it++){
		if((*it).length() == s.length()){
			D_avail.emplace(*it);
		}
	}
	unordered_map<string, unordered_set<string>> graph = create_graph(D_avail);
}
