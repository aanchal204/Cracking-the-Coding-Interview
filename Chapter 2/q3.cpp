/*
Delete middle node:
Implement an algorithm to delete a node in the middle of a singly linked list.
We are given pointer to that node.
Note: We are not given a pointer to the head of the LL
*/
#include "linkedList.h"
#include<iostream>
using namespace std;
void deleteMiddleNode(node *middle){
	middle->val = middle->next->val;
	middle->next = middle->next->next;
}
int main(void){
	node * head = createLL();
	printLL(head);
	int x;
	cout<<"Enter node number to be deleted"<<endl;
	cin>>x;
	node *middle = head;
	for(int i=1;i<x;i++)
		middle = middle->next;
	deleteMiddleNode(middle);
	printLL(head);
	return 0;
}