/*
First common ancestor : Design an algorithm and write a code to find the first common ancestor of two
nodes in a binary tree. Avoid storing additional nodes in a data structure.
Note : This is not necessarily a binary search tree
*/

#include<iostream>
#include "binaryTree.h"
node * firstCommonAncestor(node *root, int n1, int n2){
	if(root == NULL)
		return NULL;
	if(root->value == n1 || root->value == n2)
		return root;
	node *leftFCA = firstCommonAncestor(root->left , n1, n2);
	node *rightFCA = firstCommonAncestor(root->right , n1, n2);
	if(leftFCA && rightFCA)
		return root;
	return (leftFCA) ? leftFCA : rightFCA;
}
int main(void){
	node *root = NULL;
	createTree(&root);
	int n1,n2;
	cout<<"Enter the 2 nodes:"<<endl;
	cin>>n1>>n2;
	node *fca = firstCommonAncestor(root,n1,n2);
	if(fca)
		cout<<"The first commmon ancestor is "<<fca->value<<endl;
	else
		cout<<"No first common ancestor found"<<endl;
	return 0;
}