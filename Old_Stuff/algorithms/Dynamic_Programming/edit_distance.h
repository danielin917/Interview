#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int distance_helper(string str1, string str2, int count)
{
	if(str2.size() == 0)
	{
		return count + str1.size();
	}
	if( str1.size() && str1[str1.size() - 1] == str2[str2.size() -1])
	{
		str1 = str1.substr(0, str1.size() - 1);
		str2 = str2.substr(0, str2.size() - 1);	
		count = distance_helper(str1, str2, count);
	}
	else
	{
		count++;
		int erase = distance_helper(str1.substr(0, str1.size() - 1, str2, count);
		string r = str1;
		r[r.size() -1] = str2[str2.size() - 1];
		int replace = distance_helper(r, str2, count);
		int insert = distance_helper(str1 + str2[str2.size() - 1], str2, count);
		count = erase < replace ? erase : replace;
		count = count < insert ? count : replace;
	}
	return count;
}


/*
 *Minimum Number Operations to Convert str1 to str2
 */
int edit_distance(string str1, string str2)
{
	return distance_helper(str1, str2, 0);		
}
