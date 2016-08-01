/*
Insertion : You are given two 32 bit integers M and N, and 2 bit positions i and j. Write a method to insert M into
N such that M starts at bit j and ends at bit i. You can assume that the bits j through i have enough space to fit 
all of M. That is, if you have M  = 10011, you can assume that there are atleast 5 bits between j and i.
You would not for example have j=3 and i=2 because M could not fully fit between bit 3 and 2.
*/
#include<iostream>
#include "bitOperations.h"
using namespace std;
int insertion(int m, int n, int i, int j){
	int mask = -1;
	mask = clearBitFromLeft(mask,j+1);
	mask = clearBitFromRight(mask,i-1);
	mask = ~mask;
	n = n & mask;
	m = m<<i;
	return m | n;
}
int main(void){
	int m,n,i,j;
	cout<<"Enter the 2 numbers(n and m)"<<endl;
	cin>>n>>m;
	cout<<"Enter the bit positions (i and j)"<<endl;
	cin>>i>>j;
	cout<<insertion(m,n,i,j)<<endl;
	return 0;
}