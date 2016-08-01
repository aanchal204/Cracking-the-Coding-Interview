/*
A monochrome screen is stored as a single array of bytes, allowing 8 consecutive pixels to be stored
 in one byte. The screen has a width w which is divisible by 8 (i.e. no byte will be split across
 rows). The height of the screen can ofcourse be derived from the length of the array and the
 width. Implement a function that draws a horizontal line from (x1,y) to (x2,y).
*/
#include<iostream>
#include "bitOperations.h"
#define SIZE 1000
using namespace std;
typedef unsigned char byte;
void drawLine(byte *arr,int width,int x1,int x2,int y){
	//first fill the "whole" bytes with 1s
	int start_byte,end_byte;
	start_byte = x1/8;
	end_byte = x2/8;
	if(x1%8)
		start_byte++;
	if(x2%8 != 7)
		end_byte--;
	for(int i = start_byte;i<=end_byte;i++)
		arr[(width/8)*y + i] = (byte)(~0);
	//for the remainder bits on the left and right side
	byte start_mask,end_mask;
	start_mask = (byte)((byte)(~0)>>(x1%8));
	end_mask = (byte)(~((byte)(~0)>>(x2%8 + 1)));
	if(x1/8 == x2/8){	
		byte mask = (byte)(start_mask & end_mask);
		arr[(width/8)*y + x1/8] |= mask;
	}else{
		if(x1%8){
			arr[(width/8)*y + start_byte - 1] |= start_mask;
		}
		if(x2%8 != 7)
			arr[(width/8)*y + end_byte + 1] |= end_mask;
	}
}
int main(void){
	int width,x1,x2,y;
	byte arr[SIZE];
	cout<<"Enter the width"<<endl;
	cin>>width;
	cout<<"Enter x1,x2 and y"<<endl;
	cin>>x1>>x2>>y;
	drawLine(arr,width,x1,x2,y);
	for(int i=0;i<5;i++){
		for(int j=0;j<width/8;j++)
			cout<<intToBinary(arr[i*width/8 + j])<<" ";
		cout<<endl;
	}
	return 0;
}
/*
Enter the width
32
Enter x1,x2 and y
0 31 2
*/