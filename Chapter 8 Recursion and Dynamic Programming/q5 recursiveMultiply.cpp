/*
Recursive Multiply : Write a recursive function to multiply 2 positive integers without
using the * operator. You can use addition, subtraction and bit shifting, but you should
minimise the number of those operations.

Approach : Russian Peasant Multiplication
axb = (2a)x(b/2) if b is even
	= (2a)x(b/2) + a if b is odd
Recurse over this until b becomes 1
*/
#include<iostream>
using namespace std;
int recursiveMultiply(int a, int b){
	if(b == 1)
		return a;
	if(b&1)
		return a + recursiveMultiply(a<<1 , b>>1);
	return recursiveMultiply(a<<1,b>>1);

}
int main(void){
	int a,b;
	cin>>a>>b;
	cout<<recursiveMultiply(a,b)<<endl;
	return 0;
}