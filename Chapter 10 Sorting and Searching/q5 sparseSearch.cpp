/*
Sparse Search : Given a sorted array of strings interspresed with empty srings, write a method to find the 
location of a given string.
*/
#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;
/*void randomSparse(vector<string> arr){
	for(vector<string>::iterator i=arr.begin();
		i!=arr.end();
		i++){
		int r = rand() % 2;
		if(r%3 == 0){
			cout<<"rand"<<endl;
			arr.insert(i,"");
		}
	}
}*/
int sparseSearch(vector<string> arr, string str){
	int low,high,mid;
	low = 0;
	high = arr.size()-1;
	while(low<=high){
		mid = (low + high)/2;
		if(arr[mid].compare("") == 0){
			int left,right;
			left = mid-1;
			right = mid+1;
			while(left>=low || right<=high){
				if(arr[left].compare("")){	//non empty
					mid = left;
					break;
				}if(arr[right].compare("")){
					mid = right;
					break;
				}
				left--;
				right++;
			}
			if(left < low && right > high)
				return -1;
		}
		if(arr[mid].compare(str) == 0)
			return mid;
		else if(arr[mid].compare(str) < 0)
			low = mid+1;
		else
			high = mid-1;
	}
	return -1;
}
int main(void){
	vector<string> arr;
	string str;
	cin>>str;
	while(str.compare("quit")){
		if(!str.compare("-"))
			arr.push_back("");
		else
			arr.push_back(str);
		cin>>str;
	}
	// randomSparse(arr);
	for(int i=0;i<arr.size();i++)
		cout<<arr[i]<<endl;
	cout<<"Enter string to be searched"<<endl;
	cin>>str;
	int pos = sparseSearch(arr,str);
	if(pos != -1)
		cout<<str<<" was found at position "<<pos<<endl;
	else
		cout<<str<<" was not found"<<endl;
	return 0;
}