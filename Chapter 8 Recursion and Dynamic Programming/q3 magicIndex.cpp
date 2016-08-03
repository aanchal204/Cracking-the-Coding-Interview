/*
Magic Index : A magic index in an array A[0...n-1] is defined to be an index such that A[i] = i.
Given a sorted array of distinct integers, write a method to find a magic index, if one exists,
in an array.

Using binary search : if arr[mid] < mid : then all elements on the left A[i] < i, since the elements are distinct
similary, if arr[mid] > mid : all elements on right will be greater than their index

Follow up : What if the values in the array are not distinct?
if arr[mid] < mid : still there is a possibility that the left side may contain A[i] = i since the elements can 
repeat
eg: arr[5] = 3. it is possible to have arr[3] = arr[4] = 3
but here, we can limit the search from low ... 3
since its guaranteed, that elements from arr[mid]+1 ... mid : wont satisfy the condition

*/
#include<iostream>
#define SIZE 100
using namespace std;
int magicIndex(int *arr,int n){
	int low,high;
	low = 0;
	high = n-1;
	while(low<=high){
		int mid = (low+high)/2;
		if(arr[mid] == mid)
			return mid;
		if(mid > arr[mid])
			low = mid+1;
		else if(mid < arr[mid])
			high = mid-1;
	}
	return -1;
}
void createArray(int n, int *arr){
	for(int i=0;i<n;i++)
		cin>>arr[i];
}
int magicIndexWithDuplicates(int *arr, int low, int high){
	if(low > high)
		return -1;
	int mid = (low+high)/2;
	if(arr[mid] == mid)
		return mid;
	//go left
	int left = magicIndexWithDuplicates(arr,low,min(arr[mid],mid-1));
	if(left>=0)
		return left;
	//go right if magic index not found on left
	int right = magicIndexWithDuplicates(arr,max(arr[mid] , mid+1),high); 
	return right;
}	
int main(void){
	int arr[SIZE];
	int n;
	cin>>n;
	createArray(n,arr);
	cout<<magicIndex(arr,n)<<endl;
	createArray(n,arr);
	cout<<magicIndexWithDuplicates(arr,0,n-1)<<endl;
	return 0;
}