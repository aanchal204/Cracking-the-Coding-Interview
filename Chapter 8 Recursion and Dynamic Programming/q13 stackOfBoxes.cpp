/*
Stack of boxes: You have a stack of n boxes with width w, height h and depth d. The boxes cannot be rotated
but can only be stacked on top of one another if each box in the stack is strictly larger than the box above it
in width, height and depth. Implement a method to compute the height of the tallest possible stack.
The height of the stack is the sum of the heights of the boxes.
*/
#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct{
	int width,height,depth;
}box;
int compare(const void *a, const void *b){
	return ((box *)a)->height < ((box *)b)->height;
}
bool canPlace(box *arr, int lower, int higher){
	if(arr[lower].width > arr[higher].width && arr[lower].depth > arr[higher].depth && arr[lower].height > arr[higher].height)
		return true;
	return false;
}
int solve(box *arr, int index, int n, int *dp){
	if(dp[index])
		return dp[index];
	int maxHeight = 0;
	for(int i = index+1;i<n;i++){
		if(canPlace(arr,index,i)){
			int height = solve(arr,i,n,dp);
			maxHeight = height > maxHeight ? height : maxHeight;
		}
	}
	dp[index] = maxHeight + arr[index].height;
	return maxHeight + arr[index].height;
}
int stackOfBoxes(int n, box* arr){
	//sort the boxes according to the height
	//and try with each box as the lowest box in the stack
	qsort(arr,n,sizeof(box),compare);
	int maxHeight = 0;
	int *dp = new int[n];
	for(int i=0;i<n;i++){
		int height = solve(arr,i,n,dp);
		maxHeight = height > maxHeight ? height : maxHeight;
	}
	return maxHeight;
}
int main(void){
	int n,w,h,d;
	cin>>n;
	box *arr = new box[n];
	for(int i=0;i<n;i++){
		cin>>arr[i].width>>arr[i].height>>arr[i].depth;
	}
	cout<<"Tallest possible stack: "<<stackOfBoxes(n,arr)<<endl;
	return 0;
}