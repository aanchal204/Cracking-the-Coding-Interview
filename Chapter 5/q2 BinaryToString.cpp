/*
Binary to String: Given a real number between 0 and 1, print its binary representation.
If the number cannot be represented accurately in binary with atmost 32 bits,
print "Error"
*/
#include<iostream>
using namespace std;
string binaryToString(double num){
	if(num<=0 || num >= 1)
		return "Error";
	string bin = "0.";
	while(num){
		if(bin.size() >= 32)
			return "Error";
		num = num*2;
		if(num >= 1){
			bin = bin + "1";
			num -= 1;
		}else
			bin = bin + "0";
	}
	return bin;
}
int main(void){
	double num;
	cin>>num;
	cout<<binaryToString(num)<<endl;
	return 0;
}