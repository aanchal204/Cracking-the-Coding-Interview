/*
Conversion : Write a function to determine the number of bits you would need to flip to convert integer A
to integer B.
*/
#include<iostream>
#include "bitOperations.h"
using namespace std;
int conversion(int a, int b){
	//do a^b : this will set bit to 1 on those positions where the bits differ in a and b
	//since x^(~x) = 1 and x^x = 0
	int res = a^b;
	//count the number of bits set in the binary representation
	int count = 0;
	while(res){
		if(res&1)
			count++;
		res/=2;
	}
	/*
	Can also do: this repeatedly sets the rightmost 1 to zero
	while(res){
		res = res&(res-1);
		count++;
	}*/
	return count;
}
int main(void){
	int a,b;
	cin>>a>>b;
	string s1,s2;
	cout<<conversion(a,b)<<endl;
	return 0;
}