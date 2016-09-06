#pragma once
#include<vector>
#include<iostream>

using namespace std;

int max_buy_sell_once(const vector<int>& prices){
	int profit_max = 0;
	if(prices.size() == 0)
		return profit_max;
	int lowest = prices[0];
	for(int i = 1; i < prices.size(); i++){
		if(prices[i] - lowest > profit_max)
			profit_max = prices[i] - lowest;

		if(prices[i] < lowest)
			lowest = prices[i];
	}
	return profit_max;
}
