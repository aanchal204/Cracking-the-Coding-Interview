#include "linkedList.h"
#include<iostream>
using namespace std;
void insertAtTail(node **head, int x){
	node *newNode = new node;
	newNode->val = x;
	newNode->next = NULL;
	if(*head == NULL)	//LL is empty
		*head = newNode;
	else{
		node *temp = *head;
		while(temp->next!=NULL)
			temp = temp->next;
		temp->next = newNode;
	}
}
void printLL(node *head){
	while(head!=NULL){
		cout<<head->val<<" ";
		head = head->next;
	}
	cout<<endl;
}