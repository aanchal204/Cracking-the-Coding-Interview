/*
	Q1: Is Unique: Implement an algorithm to determine if a string has all unique characters. 
*/
#include<string>
#include<iostream>
using namespace std;
#define SIZE 128
bool hasUnique(string s){
	bool arr[SIZE] = {0};
	for(int i=0;i<s.length();i++){
		if(arr[s[i]])
			return false;
		arr[s[i]] = true;
	}
	return true;
}
int main(void){
	string s;
	getline(cin,s);	//input a string with spaces
	if(hasUnique(s))
		cout<<"Has unique characters"<<endl;
	else
		cout<<"Doesnt have unique characters"<<endl;
	return 0;
}
/*
What if you cannot use additional data structures?
-> compare the character with every other character to find duplicates
or sort the string and then compare the adjacent characters
*/