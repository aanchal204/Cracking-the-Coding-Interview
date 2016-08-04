/*
Permutation without Duplicates: Write a method to compute all permutations of a string
of unique characters.
*/
#include<iostream>
#include<vector>
using namespace std;
vector<string> permute(string s){
	if(s.length() == 1){
		vector<string> res;
		res.push_back(s);
		return res;
	}
	//remove the first character
	//find the permutations of the remaining string
	//insert the first character in all possible position
	vector<string> res;
	char first = s[0];
	s = s.substr(1);
	vector<string> perm = permute(s);
	for(int i=0;i<perm.size();i++){
		string permutation = perm[i];
		int j;
		for(j=0;
			j<permutation.length();
			j++){
			string temp = permutation;
			temp.insert(temp.begin() + j,first);
			res.push_back(temp);
		}
		permutation.insert(permutation.end(),first);
		res.push_back(permutation);
	}
	return res;
}
void permUnique(string s){
	vector<string> permutations = permute(s);
	cout<<permutations.size()<<endl;
	for(int i=0;i<permutations.size();i++)
		cout<<permutations[i]<<endl;
}
int main(void){
	string s;
	cin>>s;
	permUnique(s);
	return 0;
}