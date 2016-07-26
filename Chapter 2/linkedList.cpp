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
int lengthLL(node *head){
	int len = 0;
	while(head!=NULL){
		len++;
		head = head->next;
	}
	return len;
}
node * createLL(void){
	node * head = NULL;
	int x;
	cout<<"Enter elements of LL (-1 to stop)."<<endl;
	cin>>x;
	do{
		insertAtTail(&head,x);
		cin>>x;
	}while(x!=-1);
	return head;
}