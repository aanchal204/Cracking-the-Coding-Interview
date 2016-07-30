/*
String Rotation: You have a function "isSubstring" which checks whether a string is substring of another.
Given two strings s1 and s2, write code to check if s2 is a rotation of s1 using only one call to "isSubstring".
*/
#include<string>
#include<iostream>
using namespace std;
bool isRotation(string s1, string s2){
	s1 = s1+s1;
	size_t pos = s1.find(s2);
	return pos!=(string::npos);
}
int main(void){
	string s1,s2;
	getline(cin,s1);
	getline(cin,s2);
	if(isRotation(s1,s2))
		cout<<s2<<" is a rotation of "<<s1<<endl;
	else
		cout<<s2<<" is not a rotation of "<<s1<<endl;
	return 0;
}