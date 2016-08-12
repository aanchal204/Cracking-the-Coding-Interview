/*
Sorted Search, No size: You are given an array like data structure that lacks a size method. It does, however, have 
an elementAt(i) method that returns the element at index i in O(1) time. If i is beyond the bounds of the 
data structure, it returns -1. Given a Listy, that contains positive, sorted integers, find the index
at which element x occurs. If x occurs multiple times, you may return any index.
*/
#include<iostream>
#include<vector>
using namespace std;
int elementAt(vector<int> listy, int index){
	if(index < listy.size())
		return listy[index];
	return -1;
}
int length(vector<int> listy){
	int len = 1;
	while(elementAt(listy,len) != -1)
		len = len<<1;
	return len;

}
int find(vector<int> listy, int x){
	int size = length(listy);
	cout<<size<<endl;
	int low,high,mid;
	low = 0;
	high = size;
	while(low<=high){
		mid = (low + high)/2;
		if(elementAt(listy,mid) == x)
			return mid;
		if(x < elementAt(listy , mid) || elementAt(listy,mid) == -1)
			high = mid-1;
		else
			low = mid+1;
	}
	return -1;
}
int main(void){
	int x,pos;
	vector<int> listy;
	cout<<"Enter elements (-1 to stop)"<<endl;
	cin>>x;
	while(x!=-1){
		listy.push_back(x);
		cin>>x;
	}
	cout<<"Enter element to be searched"<<endl;
	cin>>x;
	pos = find(listy,x);
	if(pos != -1)
		cout<<x<<" was found a position "<<pos<<endl;
	else
		cout<<x<<" was not found"<<endl;
	return 0;
}