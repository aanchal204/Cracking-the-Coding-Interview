/*
Tower Of Hanoi: In the classic problem of towers of hanoi, you have 3 towers and N disks of different
sizes which can slide onto any tower. The puzzle starts with disks sorted in ascending order of size
from top to bottom i.e. each disk sits on top of an even larger disk. You have the following constraints:
1. Only one disk can be moved at a time
2. A disk is slid off the top of one tower onto another tower
3. A disk cannot be placed on top of a smaller disk

Write a program to move the disks from the first tower to the last using stacks.
*/
#include<iostream>
using namespace std;
void solve(int n, string source, string aux, string dest){
	if(n==1){
		cout<<"Move the disk from "<<source<<" to "<<dest<<endl;
		return ;
	}
	solve(n-1 , source , dest, aux);
	cout<<"Move the disk from "<<source<<" to "<<dest<<endl;
	solve(n-1 , aux , source , dest);
}
void towerOfHanoi(int n){
	solve(n,"A","B","C");
}
int main(void){
	int n;
	cin>>n;
	towerOfHanoi(n);
	return 0;
}