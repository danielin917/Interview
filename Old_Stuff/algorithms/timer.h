#pragma once

#include<ctime>

using namespace std;

/*
 *Simple timer
 */
class Timer{
	clock_t start_time;
	bool started;
	public:

	Timer(){}
	void start(){
		start_time = clock();
		started = true;
	}
	/*
	 *Functions for getting sec or ticks elapsed, returns -1 on failure
	 */
	float elapsed(){
		if(started)
			return float((clock() - start_time)/CLOCKS_PER_SEC);
		else	
			return -1;	
	}
	clock_t elapsed_ticks(){
		if(started)
			return clock() - start_time;
		else
			return -1;
	}
};
