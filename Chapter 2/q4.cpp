/*
Partition:
Write code to partition linked list around a value x, such that
nodes less than x come before all the nodes greater than or equal to x.
If x is in the list, the values of x only need to be after the elements less
than x.
Example
3-->5-->8-->5-->10-->2-->1 (x = 5)
3-->1-->2-->10-->5-->5-->8

My approach : Traverse the Linked list with 2 pointers: prev and current
When an element >=x is encountered, stop moving the prev pointer
Henceforth, when an element < x is encountered, swap with the previous 
and move ahead both the pointers
*/
#include "linkedList.h"
#include<iostream>
using namespace std;
void partition(node **head, int x){
	node *curr,*prev;
	curr = prev = *head;
	while(curr!=NULL && curr->val < x){
		prev = prev->next;
		curr = curr->next;
	}
	if(curr == NULL)	//all elements are smaller than x
		return;
	while(curr!=NULL){
		if(curr->val < x){
			//swap with previous
			int temp = prev->val;
			prev->val = curr->val;
			curr->val = temp;
			prev = prev->next;

		}
		curr = curr->next;
	}
}
int main(void){
	node *head = createLL();
	printLL(head);
	int x;
	cout<<"Enter partition:"<<endl;
	cin>>x;
	partition(&head,x);
	printLL(head);
	return 0;
}