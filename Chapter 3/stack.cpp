#include "stack.h"
#include<iostream>
using namespace std;
stack* init(void){
	stack *st = new stack;
	st->top = -1;
	return st;
}
bool isEmpty(stack *st){
	return (st->arr).empty();
}
void push(stack *st,int val){
	(st->arr).push_back(val);
}
int pop(stack *st){
	if(isEmpty(st)){
		cout<<"Empty Stack"<<endl;
		return -1;
	}
	int res = (st->arr).back();
	(st->arr).pop_back();
	return res;
}
int peek(stack *st){
	if(isEmpty(st)){
		cout<<"Empty stack"<<endl;
		return -1;
	}else
		return (st->arr)[(st->arr).size()-1];
}