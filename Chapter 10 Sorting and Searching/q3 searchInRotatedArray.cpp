/*
Search in Rotated Array : Given a sorted array of n integers that has been rotated unknown number of times, 
write a code to find an element in the array. You may assume that the array was originally sorted in
increasing order.
*/
#include<iostream>
using namespace std;
int searchInRotatedArray(int *arr, int n, int x){
	int low = 0;
	int high = n-1;
	while(low <= high){
		int mid = (low + high)/2;
		if(arr[mid] == x)
			return mid;
		if(arr[mid] < arr[high]){	//right is strictly increasing
			if(x > arr[mid] && x <= arr[high])
				low = mid+1;
			else
				high = mid-1;
		}else{
			if(x < arr[mid] && x >= arr[low])
				high = mid-1;
			else
				low = mid+1;
		}		
	}
	return -1;
}
int main(void){
	int n;
	cout<<"Enter size of array"<<endl;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int x;
	cout<<"Enter element to be found"<<endl;
	cin>>x;
	int pos = searchInRotatedArray(arr,n,x);
	if(pos != -1)
		cout<<x<<" was found at position "<<pos<<endl;
	else
		cout<<x<<" was not found!"<<endl;
	return 0;
}