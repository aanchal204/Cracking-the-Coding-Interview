/*
Next Number: Given a positive integer, print the next smallest and the next largest number
that has the same number of 1s in the binary representation.
getNext : flip the rightmost non-trailing zero to one
count the number of 1s on the right
shift all the 1s on the right of this zero, to the extreme right
*/
#include<iostream>
#include "bitOperations.h"
using namespace std;
int getNext(int num){
	int temp = num;
	int count0,count1;
	count0 = count1 = 0;
	while((temp & 1) == 0 && temp){
		temp /= 2;
		count0++;
	}
	while(temp & 1){
		temp /= 2;
		count1++;
	}
	if(count0+count1 == 0)	
		return 0;
	int pos = count0 + count1;
	//set the pos bit to 1
	num = setBit(num,pos);
	//clear all bits on the right side
	num = clearBitFromRight(num,pos-1);
	//insert count1-1 bits on the right
	num |= (1<<(count1-1))-1;
	return num;
}
int getPrev(int num){
	int temp = num;
	int count0,count1,pos;
	count0 = count1 = 0;
	while((temp&1)){
		temp /= 2;
		count1 ++;
	}
	while((temp&1) == 0 && temp){
		temp/=2;
		count0++;
	}
	pos = count0 + count1;
	//set pos bit to 0
	num = clearBit(num,pos);
	//clear the bits on the right side
	num = clearBitFromRight(num,pos-1);
	//insert c1+1 bits on the immediate right of pos
	int mask = ((1<<(count1+1)) - 1);
	num |= mask<<(count0-1);
	return num;
}
int main(void){
	int num;
	cin>>num;
	cout<<"The next largest number:"<<getNext(num)<<endl;
	cout<<"The next smallest number:"<<getPrev(num)<<endl;
	return 0;
}