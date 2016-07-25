/*Remove duplicates: Given an unsorted linked list, remove the duplicates from it. */
#include<iostream>
#include<unordered_set>
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
/*
Unordered set calculates the hash value and places the elements in the buckets
*/
void removeDuplicateByHashing(node *head){
	unordered_set<int> hashTable;
	node *prev = head;
	head = head->next;
	hashTable.insert(prev->val);
	while(head!=NULL){
		auto search = hashTable.find(head->val);
		if(search != hashTable.end()){
			prev->next = head->next;
			head = head->next;
		}else{
			hashTable.insert(head->val);
			head = head->next;
			prev = prev->next;
		}
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
	// removeDuplicates(head);
	removeDuplicateByHashing(head);
	printLL(head);
	return 0;
}