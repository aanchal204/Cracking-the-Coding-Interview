/*
Pairwise Swap : Write a program to swap the odd and even bits in an integer
with as few instructions as possible
*/
#include<iostream>
#include "bitOperations.h"
using namespace std;
int pairwiseSwap(int num){
	//for a 32 bit integer, the mask should be 10101010101010101010101010101010 i.e. 0XAAAAAAAA
	//(mask & num) will select all the odd bits
	//~mask & num will select the even bits
	//>> logical right shift: to fill the sign bit with 0
	int mask = 0XAAAAAAAA;
	return ((mask&num)>>1) | (((~mask)&num)<<1);
}
int main(void){
	int num;
	cin>>num;
	int res = pairwiseSwap(num);
	cout<<intToBinary(num)<<endl;
	cout<<intToBinary(res)<<endl; 
	return 0;
}