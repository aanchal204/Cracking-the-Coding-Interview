/*
URLify :Write a method to replace all spaces in a string with '%20  
You may assume that the string has suf cient space at the end 
to hold the additional characters,and that you are given the "true" length of the string. 
*/
#include<string>
#include<iostream>
using namespace std;
void URLify(string s, int length){
	for(int i=0;i<length;i++){
		if(s[i] == ' ')
			cout<<"%20";
		else
			cout<<s[i];
	}
	cout<<endl;
}
int main(void){
	string s;
	int length;
	getline(cin,s);
	cin>>length;
	URLify(s,length);
	return 0;
}