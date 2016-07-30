/*
Given two strings,write a method to decide if one is a permutation of the
other.
OR 
Given two strings,write a method to decide if they are anagrams of each other.
*/
#include<string>
#include<iostream>
using namespace std;
#define SIZE 128
bool isPermutation(string s1, string s2){
	int freq1[SIZE] = {0}, freq2[SIZE] = {0};
	if(s1.length() != s2.length())
		return false;
	for(int i=0;i<s1.length();i++){
		freq1[s1[i]]++;
		freq2[s2[i]]++;
	}
	for(int i=0;i<SIZE;i++)
		if(freq1[i] != freq2[i])
			return false;
	return true;
}
int main(void){
	string s1,s2;
	getline(cin,s1);
	getline(cin,s2);
	if(isPermutation(s1,s2))
		cout<<s1<<" and "<<s2<<" are permutations of each other"<<endl;
	else
		cout<<s1<<" and "<<s2<<" are not permutations of each other"<<endl;
	return 0;
}