/*
Parens: Implement an algorithm to print all valid(i.e. properly opened and closed) combinations
of n pairs of parenthesis.
*/
#include<iostream>
#include<vector>
using namespace std;
void generate(vector<string>& result, int left, int right, string s){
	if(left == 0 && right == 0){
		result.push_back(s);
		return ;
	}
	string temp = s;
	//add a left parenthesis only if available
	if(left>0){
		temp = s + '(';
		generate(result , left - 1 , right , temp);
	}
	// add a right parenthesis only if right are available than left i.e. more left ones are already used
	if(right>left){
		temp = s + ')';
		generate(result , left , right-1 , temp);
	}
}
void parens(int n){
	vector<string> result;
	generate(result,n,n,"");
	for(int i=0;i<result.size();i++)
		cout<<result[i]<<endl;
}
int main(void){
	int n;
	cin>>n;
	parens(n);
	return 0;
}