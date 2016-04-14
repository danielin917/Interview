#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int longest_subsequence(string a, string b);

int main()
{
	string a = "hello";
	string b = "bell";
	cout << longest_subsequence(a, b)<<endl;
}


int longest_helper(string a, string b, int index_a, int index_b, int total){
	if(index_a < a.length() && index_b < b.length()){
			int a_val, b_val, cont_val;
			a_val = b_val = cont_val = 0;
			if(a[index_a] == b[index_b]){	
				a_val = longest_helper(a, b, index_a + 1, index_b, 0); 
				b_val = longest_helper(a, b, index_a, index_b + 1, 0);		
				cont_val = longest_helper(a, b, index_a + 1, index_b + 1, total + 1);
			}
			else{
				a_val = longest_helper(a, b, index_a + 1, index_b, 0);
				b_val = longest_helper(a, b, index_a, index_b + 1, 0);
			}
			return max(max(a_val, b_val), cont_val);
	}
	else{
		return total;
	}
}

int longest_subsequence(string a, string b)
{
	return longest_helper(a,b,0,0,0);
}
