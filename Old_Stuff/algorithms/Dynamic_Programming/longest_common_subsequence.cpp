#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int longest_subsequence(string a, string b);

int main()
{
	string a = "hellllllo";
	string b = "789097be78097809l98789087l0987809987";
	cout << longest_subsequence(a, b)<<endl;
}

/*
 *O(2^n)
 */
int longest_helper(string a, string b, int index_a, int index_b, int total){
	if(index_a >= 0 && index_b >= 0){
			int a_val, b_val, cont_val;
			a_val = b_val = cont_val = 0;
			if(a[index_a] == b[index_b]){	
				a_val = longest_helper(a, b, index_a - 1, index_b, 0); 
				b_val = longest_helper(a, b, index_a, index_b - 1, 0);		
				cont_val = longest_helper(a, b, index_a - 1, index_b - 1, total + 1);	
			}
			else{
				a_val = longest_helper(a, b, index_a - 1, index_b, 0);
				b_val = longest_helper(a, b, index_a, index_b - 1, 0);
			}
			return max(max(max(a_val, b_val), cont_val),total);
	}
	else{
		
		return total;
	}
}
/*
 *Using better substructure, add up totals as you go so you don't do checks on the same string pairings
 *
 *
 */
int longest_helper_better(string a, string b){
	int** d = new int*[a.length()];
	for(int i = 0; i < a.length(); i++){
		d[i] = new int[b.length()];
	}
	for(int i = 0; i < a.length(); i++){
		for(int j = 0; j < b.length(); j++){
			if(i == 0 || j == 0){
				d[i][j] = (a[i] == b[j]) ? 1 : 0; 
			}
			else if(a[i] == b[j]){
				d[i][j] = 1 + d[i-1][j-1];  
			}
			else{
				d[i][j] = max(d[i-1][j], d[i][j-1]);
			}
		}
	}
	return d[a.length() -1][b.length() -1];

}
int longest_subsequence(string a, string b)
{
	return longest_helper_better(a,b);
}
