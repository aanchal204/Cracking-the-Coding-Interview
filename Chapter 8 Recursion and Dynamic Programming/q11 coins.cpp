/*
Coins: Given an infinite number of quarters(25 cents), dimes(10 cents), nickels (5 cents) and pennies(1 cent)
write a code to calculate the number of ways to represent n cents.
*/
#include<iostream>
#include<vector>
#define SIZE 1000
using namespace std;
int coins(int n){
	int denomination[] = {0,25,10,5,1};
	int count[SIZE][5] = {{0}};
	for(int i=0;i<5;i++)
		count[0][i] = 1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<5;j++){
			if(i>=denomination[j]){
				count[i][j] = count[i][j-1] + count[i - denomination[j]][j];
			}
		}
	}
	return count[n][4];
}
int main(void){
	int n;
	cin>>n;
	cout<<coins(n)<<endl;
	return 0;
}