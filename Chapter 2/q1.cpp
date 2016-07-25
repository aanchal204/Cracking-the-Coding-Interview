/*Remove duplicates: Given an unsorted linked list, remove the duplicates from it. */
#include<iostream>
#include "linkedList.h"
using namespace std;
void removeDuplicates(node *head){
	node* ptr1, *ptr2,*prev;
	ptr1 = head;
	while(ptr1!=NULL && ptr1->next != NULL){
		prev = ptr1;
		ptr2 = ptr1->next;
		while(ptr2!=NULL){
			if(ptr1->val == ptr2->val){
				prev->next = ptr2->next;
				ptr2 = prev->next;
			}else{
				prev = ptr2;
				ptr2 = ptr2->next;
			}
		}
		ptr1 = ptr1->next;
	}
}
int main(void){
	node * head = NULL;
	int x;
	cout<<"Enter elements of LL (-1 to stop)."<<endl;
	cin>>x;
	do{
		insertAtTail(&head,x);
		cin>>x;
	}while(x!=-1);
	printLL(head);
	removeDuplicates(head);
	printLL(head);
	return 0;
}