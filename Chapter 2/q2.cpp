/*
Return kth to the last: Implement an algorithm to find the kth to last element 
of a singly linked list
*/
#include "linkedList.h"
#include<iostream>
using namespace std;
node* kthToLast(node *head, int k){
	node *current, *runner;
	current = runner = head;
	for(int i=0;i<k;i++){
		runner = runner->next;
	}
	while(runner!=NULL){
		current = current->next;
		runner = runner->next;
	}
	return current;
}
int main(void){
	node * head = NULL;
	int x,k;
	cout<<"Enter elements of LL (-1 to stop)."<<endl;
	cin>>x;
	do{
		insertAtTail(&head,x);
		cin>>x;
	}while(x!=-1);
	printLL(head);
	cout<<"Enter k:"<<endl;
	cin>>k;
	node *newNode = kthToLast(head,k);
	cout<<"The kth to the last node is "<<newNode->val<<endl;
	return 0;
}