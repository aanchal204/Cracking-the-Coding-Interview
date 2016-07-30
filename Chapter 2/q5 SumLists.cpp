/*
Sum lists: You have two numbers represented by linked list, where each node contains
a single digit. Digits are stored in reverse order.(1's digit is at the head)
Write a function that adds two such numbers and returns a number in similar
list format.
example:
7-->1-->6 + 5-->9-->2 = 2-->1-->9
which is (617 + 295  = 912)
What if digits are not stored in reverse order(i.e 1's digit is at tail)
(6--1-->7) + (2-->9-->5) = (9-->1-->2)
*/
#include "linkedList.h"
#include<iostream>
using namespace std;
int sumListsHelper(node *num1, node* num2, node **res){
	// base condition
	if(num1 == NULL && num2 == NULL)
		return 0;
	int carry=0,sum=0;
	carry = sumListsHelper(num1->next , num2->next, res);
	sum = num1->val + num2->val + carry;
	node *newnode = new node;
	newnode->val = sum%10;
	newnode->next = *res;
	*res = newnode;
	return sum/10;
}
void padZeros(node **head, int zero){
	for(int i=0;i<zero;i++){
		node *newnode = new node;
		newnode->val = 0;
		newnode->next = *head;
		*head = newnode;
	}
}
node * sumListsRecurse(node *num1, node *num2){
	int len1,len2;
	len1 = lengthLL(num1);
	len2 = lengthLL(num2);
	if(len1 > len2){
		padZeros(&num2,len1-len2);
		printLL(num2);
	}else if(len2 > len1){
		padZeros(&num1 , len2-len1);
		printLL(num1);
	}
	node *res = NULL;
	int carry = sumListsHelper(num1,num2,&res);
	if(carry){
		node *newnode = new node;
		newnode->val = carry;
		newnode->next = res;
		res = newnode;
	}
	return res;
}
node * sumLists(node *num1, node *num2){
	int carry = 0,sum;
	node *head = NULL, *curr;
	while(num1 || num2 || carry){
		sum = carry;
		if(num1)
			sum+=num1->val;
		if(num2)
			sum+=num2->val;
		carry = sum/10;
		sum %= 10;
		node *newnode = new node;
		newnode->val = sum;
		newnode->next = NULL;
		if(head == NULL){
			head = newnode;
			curr = head;
		}
		else{
			curr->next = newnode;
			curr = curr->next;
		}
		if(num1)
			num1 = num1->next;
		if(num2)
			num2 = num2->next;
	}
	return head;
}

int main(void){
	node *num1 = createLL();
	node *num2 = createLL();
	// node *res = sumLists(num1,num2);
	node *res = sumListsRecurse(num1,num2);
	printLL(res);
	return 0;
}