/*
Queue via Stacks: Implement a queue using stacks
*/
#include<iostream>
#include "stack.h"
using namespace std;
class Queue{
public:
	stack * newStack;
	stack * oldStack;

	Queue(void){
		newStack = init();
		oldStack = init();
	}

	bool isQEmpty(void){
		return isEmpty(newStack) && isEmpty(oldStack);
	}

	//transfer elements from newStack to oldStack
	void transfer(void){
		while(!isEmpty(newStack)){
			int x = pop(newStack);
			push(oldStack,x);
		}
	}

	void add(int val){
		push(newStack,val);
	}

	int remove(void){
		if(isQEmpty()){
			cout<<"Queue is empty!"<<endl;
			return -1;
		}else if(isEmpty(oldStack)){
			transfer();
			int res = pop(oldStack);
			return res;
		}else{
			return pop(oldStack);
		}
	}

	int Qpeek(void){
		if(isQEmpty()){
			cout<<"Queue is empty!"<<endl;
			return -1;
		}else if(isEmpty(oldStack)){
			transfer();
			return peek(oldStack);
		}else
			return peek(oldStack);
	}
};
int main(void){
	Queue q;
	q.add(1);
	q.add(2);
	q.add(3);
	q.add(4);
	q.add(5);
	cout<<q.Qpeek()<<endl;
	cout<<q.remove()<<endl;
	cout<<q.remove()<<endl;
	return 0;
}