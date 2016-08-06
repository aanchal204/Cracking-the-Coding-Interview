/*
Eight Queens : Write an algorithm to print all ways of arranging 8 queens on an 8x8 chess board
so that none of them share the same row, column or diagonal.
*/
#include<iostream>
using namespace std;
bool check(int *arr, int row){
	for(int i=0;i<row;i++){
		if(arr[i] == arr[row] ||
			abs(row-i) == abs(arr[row]-arr[i]))
			return 0;
	}
	return 1;
}
void print(int *arr, int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			if(arr[i] == j)
				cout<<"Q";
			else
				cout<<".";
		cout<<endl;
	}
}
void solve(int *arr, int row, int n){
	if(row == n){
		print(arr,n);
		cout<<endl;
		return;
	}
	for(int col=0;col<n;col++){
		arr[row] = col;
		if(check(arr,row)){
			solve(arr,row+1,n);
		}
	}
}
void eightQueens(int n){
	int *arr = new int[n];
	solve(arr, 0, n);
}
int main(void){
	int n;
	cin>>n;
	eightQueens(n);
	return 0;
}