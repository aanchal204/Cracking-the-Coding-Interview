/*
Loop Detection
Problem : Determine if a linkedlist has a loop. If it has a loop, find the start of loop.

Approach : Floyd's Cycle Finding Algo
*/
#include "linkedList.h"
#include<iostream>
#include<stdlib.h>
using namespace std;
node * createLoop(){
	node *head = createLL();
	int len = lengthLL(head);
	int pos = rand()%(len+1);
	if(pos != len){
		node *temp = head;
		for(int i=0;i<pos;i++)
			temp = temp->next;
		node *tail = head;
		while(tail->next)
			tail = tail->next;
		tail->next = temp;
	}
	return head;
}
node * isLoop(node *head){
	node *slow,*fast;
	slow = fast = head;
	while(slow && fast && fast->next){
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast){
			return slow;
		}
	}
	return NULL;
}
node *findLoop(node *head){
	node *fast = isLoop(head);
	if(fast){
		//move the slow back to the head, concurrently move fast and slow at same speed
		node *slow = head;
		while(slow != fast){
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
	}else{
		return NULL;
	}
}
int main(void){
	node *head = createLoop();
	// printLL(head);
	node *loop = findLoop(head);
	if(loop){
		cout<<"Loop present at: "<<loop->val<<endl;
	}
	else
		cout<<"Loop not present"<<endl;
	return 0;
}