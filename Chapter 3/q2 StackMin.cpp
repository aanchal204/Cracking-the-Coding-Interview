/*Stack Min: 
How would you design a stack which, in addition to push and pop, has a function min that 
returns the minimum element? Push, pop and min should operate in O(1) time*/
#include<iostream>
#include<climits>
#define SIZE 100
using namespace std;
typedef struct stack{
	int *arr;
	int top;
	int *minPtr;
}stack;
stack* init(void){
	stack *st = new stack;
	st->arr = new int[SIZE]();
	st->top = -1;
	st->minPtr = new int[SIZE]();
	return st;
}
bool isEmpty(stack *st){
	return st->top==-1;
}
int peek(stack *st){
	if(isEmpty(st)){
		cout<<"Empty stack"<<endl;
		return -1;
	}else
		return st->arr[st->top];
}
void push(stack *st,int val){
	
	if(st->top == SIZE-1)
		cout<<"Stack overflow!"<<endl;
	else{
		if(isEmpty(st))
			st->minPtr[st->top + 1] = st->top + 1;
		else{
			int min = st->arr[st->minPtr[st->top]];
			if(val < min)
				st->minPtr[st->top + 1] = st->top + 1;
			else
				st->minPtr[st->top + 1] = st->minPtr[st->top];
		}
		st->arr[++st->top] = val;
	}
}
int pop(stack *st){
	if(isEmpty(st)){
		cout<<"Empty Stack"<<endl;
		return -1;
	}else{
		return st->arr[st->top--];
	}
}
int minValue(stack *st){
	if(isEmpty(st)){
		cout<<"Empty stack!"<<endl;
		return -1;
	}
	return st->arr[st->minPtr[st->top]];
}
int main(void){
	stack *st = init();
	push(st,10);
	push(st,2);
	push(st,9);
	push(st,7);
	push(st,1);
	push(st,3);
	push(st,5);
	push(st,-45);
	cout<<minValue(st)<<endl;
	pop(st);
	pop(st);
	pop(st);
	pop(st);
	cout<<minValue(st)<<endl;
	return 0;
}