/*
Three in one: Describe how you could use a single array to implement three stacks
*/
#include<iostream>
using namespace std;
#define NUM_STACK 3
#define SIZE 100*NUM_STACK
typedef struct stack{
	int *arr;
	int top[NUM_STACK+1];
}stack;
stack* init(void){
	stack *st = new stack;
	st->arr = new int[SIZE]();
	for(int i=0;i<NUM_STACK;i++)
		st->top[i] = i*100 - 1;
	return st;
}
void push(stack *st,int val, int stno){
	if(st->top[stno-1] == SIZE/NUM_STACK * stno - 1)
		cout<<"Stack overflow!"<<endl;
	else
		st->arr[++st->top[stno-1]] = val;
}
bool isEmpty(stack *st,int stno){
	stno--;
	return (st->top[stno] == stno*100 - 1);
}
int pop(stack *st,int stno){
	if(isEmpty(st,stno)){
		cout<<"Empty stack!"<<endl;
		return -1;
	}
	else{
		return st->arr[st->top[stno-1]--];
	}
}
int peek(stack *st, int stno){
	if(isEmpty(st,stno)){
		cout<<"Empty stack!"<<endl;
		return -1;
	}
	return st->arr[st->top[stno-1]];
}
int main(void){
	stack *st = init();
	push(st,10,1);
	push(st,10,2);
	push(st,10,3);
	push(st,15,1);
	push(st,20,1);
	cout<<peek(st,1)<<endl;
	cout<<peek(st,2)<<endl;
	cout<<pop(st,3)<<endl;
	cout<<peek(st,3)<<endl;
	cout<<isEmpty(st,2)<<endl;
	return 0;
}