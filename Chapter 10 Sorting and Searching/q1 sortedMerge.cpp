/*
Sorted Merge : You are given two sorted arrays A and B, where A has a large enouh buffer at the end to hold B.
Write a method to merge B into A in a sorted order.
*/
#include<iostream>
using namespace std;
void sortedMerge(int *a, int *b,int n, int m){
	int ptra, ptrb,i;
	ptra = n-1;
	ptrb = m-1;
	for(i=n+m-1;i>=0 && ptra!=-1 && ptrb!=-1;i--){
		if(a[ptra] > b[ptrb]){
			a[i] = a[ptra];
			ptra--;
		}else{
			a[i] = b[ptrb];
			ptrb--;
		}
	}
	while(ptrb!=-1){
		a[i--] = b[ptrb];
		ptrb--;
	}
	for(int i=0;i<n+m;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
int main(void){
	int n,m;
	cout<<"Enter size of A and B"<<endl;
	cin>>n>>m;
	int *a = new int[n+m];
	int *b = new int[m];
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<m;i++)
		cin>>b[i];
	sortedMerge(a,b,n,m);
	return 0;
}