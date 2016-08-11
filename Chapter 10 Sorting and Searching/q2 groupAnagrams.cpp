/*
Group Anagrams: Write a method to sort an array of strings so that all the anagrams are next to
each other.
*/
#include<iostream>
#include<map>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;
string getKey(string str){
	sort(str.begin(), str.end());
	return str;
}
void groupAnagrams(vector<string> arr){
	int len = arr.size();
	map<string, vector<string> > hashMap;
	for(int i=0;i<len;i++){
		string key = getKey(arr[i]);
		hashMap[key].push_back(arr[i]);
	}
	int j=0;
	for(map<string, vector<string> >::iterator it = hashMap.begin();
		it!=hashMap.end();
		it++){
		for(int i=0;i<(it->second).size();i++)
			arr[j++] = it->second[i];
	}
	for(int i=0;i<len;i++)
		cout<<arr[i]<<endl;
}
int main(void){
	int n;
	cout<<"Enter size of array"<<endl;
	cin>>n;
	vector<string> arr;
	string str;
	for(int i=0;i<n;i++){
		cin>>str;
		arr.push_back(str);
	}
	groupAnagrams(arr);
	return 0;
}