/*Palindrome Permutation : Given a string, write a function to check if it is a permutation of a palindrome

Assumption : The palindrome is not case-sensitive 
The string contains only alphabetic characters
*/
#include<string>
#include<iostream>
#define SIZE 26
using namespace std;
bool isAlpha(char ch){
	if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z'))
		return true;
	return false;
}
bool checkPalPerm(string s){
	int mask = 0;	
	for(int i=0;i<s.length();i++)
	{
		if(isAlpha(s[i])){
			if(s[i]>='A' && s[i]<='Z')
				s[i] += 32;
			int bitPos = s[i]-'a';
			mask = mask^(1<<bitPos);
		}
	}
	//to be a palindrome, there should be atmost one bit with value 1, all other bits must be 0
	return (((mask-1)&(mask)) == 0);
}
int main(void){
	string s;
	getline(cin,s);
	if(checkPalPerm(s))
		cout<<"Is a permutation of a palindrome"<<endl;
	else
		cout<<"Not a permutation of a palindrome"<<endl;
	return 0;
}