/*
Intersection: Given 2 singly linked lists, determine if the two lists intersect. Return the intersecting node.
Note that the intersection is based on the reference and not the value.
*/
#include "linkedList.h"
#include<iostream>
#include<stdlib.h>	//rand
using namespace std;
node *findIntersection(node *list1, node *list2){
	int len1,len2;
	len1 = lengthLL(list1);
	len2 = lengthLL(list2);
	node *ptr1,*ptr2;
	ptr1 = len1>=len2 ? list1 : list2;
	ptr2 = len1<len2 ? list1 : list2;
	for(int i=0;i<abs(len1-len2);i++)
		ptr1 = ptr1->next;
	while(ptr1 && ptr2){
		if(ptr1 == ptr2)
			return ptr1;
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	return NULL;
}
int main(void){
	node *list1 = createLL();
	node *list2 = createLL();
	// append the list1 at a random position in list2
	int len2 = lengthLL(list2);
	int pos = rand()%len2;
	if(pos){
		node *temp = list2;
		for(int i=0;i<pos;i++){
			temp = temp->next;
		}
		temp->next = list1;
	}
	printLL(list1);
	printLL(list2);
	node *intersection = findIntersection(list1,list2);
	if(intersection){
		cout<<"The lists intersect at "<<intersection->val<<endl;
	}
	else
		cout<<"The lists do not intersect"<<endl;
	return 0;
}