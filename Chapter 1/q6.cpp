/*String compression: Implement a method to perform basic string compression using the counts
of repeated characters. For example the string aabcccaaaa will become a2b1c3a4. If the compressed string
would NOT become smaller than the original string, your method should return the original string. 
You can assume that the string has only uppercase and lowercase letters*/
#include<string>
#include<iostream>
using namespace std;
string compressString(string s){
	char curr = s[0];
	int count = 0;
	string compressedString = "";
	for(int i=0;i<s.length();){
		while(i<s.length() && s[i] == curr){
			count++;
			i++;
		}
		compressedString += curr;
		compressedString.append(to_string(count));
		count = 0;
		curr = s[i];
	}
	if(compressedString.length() >= s.length())
		return s;
	return compressedString;
}
int main(void){
	string s;
	getline(cin,s);
	cout<<compressString(s)<<endl;
	return 0;
}