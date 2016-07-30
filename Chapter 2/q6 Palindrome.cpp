/*Palindrome: Implement a function to check if a linked list is a palindrome
Approach : Use 2 pointers: left and right
Recursively call the function until right reaches the end
Compare left and right pointers
Move left ahead and right backwards

Can also be done iteratively using a stack or reversing the linked list
*/
#include "linkedList.h"
#include<iostream>
using namespace std;
bool isPalindrome(node *right, node **left){
	// base condition
	if(right->next == NULL){
		if(right->val == (*left)->val){
			*left = (*left)->next;
			return true;
		}else
			return false;
	}
	bool res = isPalindrome(right->next, left);
	if(res){
		if(right->val == (*left)->val){
			*left = (*left)->next;
			return true;
		}
		return false;
	}
	return false;
}
int main(void){
	node *head = createLL();
	node **curr = &head;
	if(isPalindrome(head,curr))
		cout<<"Is a palindrome"<<endl;
	else
		cout<<"Is not a palindrome"<<endl;
	return 0;
}