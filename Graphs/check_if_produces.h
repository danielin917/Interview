#pragma once
#include<set>
#include<unordered_map>
#include<string>
#include<unordered_set>

#define FOUND 0
#define NOT_FOUND 1

using namespace std;

bool check_transform(string s, string t){
	int count = 0;
	for(int i = 0; i < s.length(); i++){
		if(s[i] != t[i])
			count++;
		if(count > 1)
			return false;
	}
	return true;
}

unordered_map<string, unordered_set<string>> create_graph(const set<string>& D){
	unordered_map<string, unordered_set<string>> graph;
	for(auto it = D.begin(); it != D.end(); ++it){
		auto ir = it;
		while(++ir != D.end())
			if(check_transform(*ir,*it)){
				graph[*it].emplace(*ir);
				graph[*ir].emplace(*it);
			}
	}
	return graph;
}
int bfs(const string& start, const string& target, unordered_map<string, unordered_set<string>>& graph, unordered_set<string>& visited){

}

int dfs(const string& start, const string& target, unordered_map<string, unordered_set<string>>& graph, unordered_set<string>& visited){
	int ret = 1;
	visited.emplace(start);
	if(target == start){
		return FOUND;
	}
	if(graph.find(start) == graph.end()){
		return NOT_FOUND;
	}
	for(auto it = graph[start].begin(); it != graph[start].end(); it++){
		string search = *it;
		if(visited.find(search) == visited.end()){
			ret &= dfs(search, target, graph, visited);
		}
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
	unordered_set<string> visited;
	return dfs(s,t,graph,visited);
}
