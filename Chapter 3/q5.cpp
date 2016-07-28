/*
Queue via Stacks: Implement a queue using stacks

Approach: Use a secondary stack
Pop an element from the primary stack and insert it into the appropriate place in the
secondary stack
Insertion sort with a variation
*/
#include<iostream>
#include "stack.h"
using namespace std;
void sort(stack *primary){
	stack *secondary;
	secondary = init();
	while(!isEmpty(primary)){
		int element = pop(primary);
		while(!isEmpty(secondary) && peek(secondary)>element)
			push(primary, pop(secondary));
		push(secondary,element);
	}
	while(!isEmpty(secondary))
		push(primary,pop(secondary));
}
void print(stack *primary){
	while(!isEmpty(primary))
		cout<<pop(primary)<<" ";
	cout<<endl;
}
int main(void){
	int x;
	stack *primary;
	primary = init();
	cout<<"Enter elements for sorting (-1 to stop)"<<endl;
	cin>>x;
	do{
		push(primary,x);
		cin>>x;
	}while(x!=-1);
	sort(primary);
	print(primary);
	return 0;
}