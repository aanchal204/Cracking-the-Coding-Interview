/*
Permutations with Duplicates : Write a method to compute all permutations of a string whose characters
are not necessarily unique. The list of permutations should not have duplicates.

*/
#include<iostream>
#include<vector>
#include<map>
using namespace std;
map<char,int> generateFreq(string s){
	map<char,int>freq;
	for(int i=0;i<s.length();i++){
		auto pos = freq.find(s[i]);
		if(pos != freq.end()){
			freq[s[i]] = pos->second + 1;
		}else
			freq[s[i]] = 1;
	}
	return freq;
}
void permute(map<char,int> freq, string prefix, int remaining, vector<string> & permutations){
	if(!remaining){
		permutations.push_back(prefix);
		return;
	}
	for(map<char,int>::iterator it = freq.begin();
		it!=freq.end();
		it++){
		char ch = it->first;
		int count = it->second;
		if(count > 0){
			freq[ch] = count - 1;
			permute(freq , prefix + ch , remaining - 1, permutations);
			freq[ch] = count;
		}
	}
}
void permDups(string s){
	vector<string> permutations;
	map<char,int> freq;
	freq = generateFreq(s);
	permute(freq , "" , s.length() , permutations);
	for(int i=0;i<permutations.size();i++)
		cout<<permutations[i]<<endl;
}
int main(void){
	string s;
	cin>>s;
	permDups(s);
	return 0;
}