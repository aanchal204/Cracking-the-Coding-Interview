/*
Stack of plates: Imagine a stack of plates. If the stack gets too high, it might topple.
Therefore, in real life, we would likely start a new stack when the previous stack exceeds some
threshold. Implement a data structure setOfStacks that mimics this. setOfStacks must be composed
of several stacks and could create a new stack once the previous one exceeds the capacity.
setOfStacks.push() and setOfStacks.pop() should behave identically to a single stack
*/
#include<iostream>
using namespace std;
#define NUM_STACK 10
#define SIZE 3	//size of each stack
class Stack{
public:
	int *arr;
	int top;

	Stack(){
		arr = new int[SIZE]();
		top = -1;
	}
	bool isEmpty(){
		return top==-1;
	}
	bool isFull(){
		return top == SIZE-1;
	}
	bool push(int val){
		
		if(top == SIZE-1){
			cout<<"Stack overflow!"<<endl;
			return false;
		}
		else{
			arr[++top] = val;
			return true;
		}
			
	}
	int pop(){
		if(isEmpty()){
			cout<<"Empty Stack"<<endl;
			return -1;
		}else
			return arr[top--];
	}

	int peek(){
		if(isEmpty()){
			cout<<"Empty stack"<<endl;
			return -1;
		}else
			return arr[top];
	}
};
class setOfStacks{
public:
	Stack stacks[NUM_STACK];
	int current;
	setOfStacks(){
		/*for(int i=0;i<NUM_STACK;i++)
			stacks[i] = new Stack;*/
		current = 0;
	}
	bool isFull(){
		return current == NUM_STACK-1 && stacks[current].isFull();
	}
	bool isEmpty(){
		return current == 0 && stacks[current].isEmpty();
	}
	void push(int val){
		if(isFull())
			cout<<"All Stacks are full"<<endl;
		else{
			if(!stacks[current].isFull()){
				stacks[current].push(val);
			}else{
				cout<<"Created new stack"<<endl;
				current++;
				stacks[current].push(val);
			}
		}
	}
	int peek(){
		if(isEmpty()){
			cout<<"All stacks are empty"<<endl;
			return -1;
		}else{
			if(stacks[current].isEmpty()){
				current--;
			}
			return stacks[current].peek();
		}
	}
	int pop(){
		if(isEmpty()){
			cout<<"All stacks are empty"<<endl;
			return -1;
		}else{
			if(stacks[current].isEmpty())
				current--;
			return stacks[current].pop();
		}
	}
};
int main(void){
	setOfStacks st;
	st.push(10);
	st.push(9);
	st.push(18);
	st.push(1);
	cout<<st.pop()<<endl;
	cout<<st.pop()<<endl;
	cout<<st.pop()<<endl;
	cout<<st.pop()<<endl;
	cout<<st.pop()<<endl;
	return 0;
}