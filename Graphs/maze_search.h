#pragma once
#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<unordered_set>

using namespace std;

struct Coord{
	int first;
	int second;

	bool operator==(const Coord& x) const{
		return x.first == first && x.second == second;
	}
};

struct c_hash{
	size_t operator()(const Coord& c) const{
		size_t hash = 0xFFFF;
		hash ^= c.first;
		hash ^= c.second;
		hash = hash>>4 ^ c.first;
		hash = hash<<4 ^ c.second;
		return hash;
	}
};

unordered_map<Coord , list<Coord>, c_hash> create_graph( vector<vector<bool>> bit_map){
	unordered_map<Coord, list<Coord>,c_hash> graph;
	for(int i = 0; i < bit_map.size(); i++){
		for(int j = 0; j < bit_map[i].size(); j++){
			Coord cur = {i,j};
			Coord loc;
			if(bit_map[i][j]){
				if(i > 0 && bit_map[i - 1][j]){
					graph[cur].emplace_back(Coord{i - 1, j});
				}
				if(j > 0 && bit_map[i][j - 1]){
					graph[cur].emplace_back(Coord{i, j -1});
				}
				if(i + 1 < bit_map.size() && bit_map[i + 1][j]){
					graph[cur].emplace_back(Coord{i + 1, j});
				}
				if(j + 1 < bit_map[i].size() && bit_map[i][j + 1]){
					graph[cur].emplace_back(Coord{i , j + 1});
				}
			}
		}
	}
	cout << graph.size() << endl;
	return graph;
}

vector<Coord> find_path_dfs(unordered_map<Coord, list<Coord>, c_hash>& graph,
					 																			Coord entry,
																								Coord exit,
																								vector<Coord> path,
																								unordered_set<Coord, c_hash> traveled){
	path.emplace_back(entry);
	if(entry == exit){
		return path;
	}
	if(traveled.find(entry) != traveled.end()){
		return {};
	}
	traveled.emplace(entry);
	for(auto i = graph[entry].begin(); i != graph[entry].end(); i++){
		vector<Coord> path_taken = find_path_dfs(graph, *i, exit, path, traveled);
		if(path_taken.size()){
			return path_taken;
		}
	}
	return {};
}

vector<Coord> maze_search(vector<vector<bool>> bit_map,
																		Coord entry,
																		Coord exit){
	unordered_map<Coord, list<Coord>, c_hash> graph = create_graph(bit_map);
	return find_path_dfs(graph, entry, exit, {}, {});
}
