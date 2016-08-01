/*
Flip Bit to Win : You have an integer and you can flip exactly one bit from a 0
to 1. Write a code to find the length of the longest sequence of 1s 
you could create.
*/
#include "bitOperations.h"
#include<iostream>
#include<vector>
using namespace std;
int flipBit(string bin){
	vector<int> zeroPos;
	zeroPos.push_back(-1);
	for(int i=0;i<bin.size();i++)
		if(bin[i] == '0')
			zeroPos.push_back(i);
	zeroPos.push_back(bin.size());
	int max = 1;	
	for(int i=1;i<zeroPos.size()-1;i++){
		int len = (zeroPos[i+1] - zeroPos[i-1]) - 1;
		max = len > max ? len : max;
	}
	return max;
}
int main(void){
	int num;
	cin>>num;
	string bin = intToBinary(num);
	cout<<bin<<endl;
	cout<<flipBit(bin)<<endl;
	return 0;
}