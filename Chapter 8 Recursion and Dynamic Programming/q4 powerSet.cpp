/*
Power Set : Write a method to return all the subsets of a set.
*/
#include<iostream>
#define SIZE 100
using namespace std;
void createSet(int *arr, int n){
	for(int i=0;i<n;i++)
		cin>>arr[i];
}
void printSubsets(int *arr, int n){
	for(int i=0;i<(1<<n);i++){
		int num = i;
		int bit = 0;
		while(num){
			if(num&1){
				cout<<arr[bit]<<" ";
			}
			bit++;
			num >>= 1;
		}
		cout<<endl;
	}
}
int main(void){
	int n,arr[SIZE];
	cin>>n;
	createSet(arr,n);
	printSubsets(arr,n);
	return 0;
}