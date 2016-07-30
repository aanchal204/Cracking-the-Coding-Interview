/*
Check Subtree : T1 and T2 are very large binary trees, with t1 much bigger than T2. Create an algorithm to
determine if T2 is a subtree of T1.
A tree T2 is a subtree of T1 if there exists a node n in T1 such that the subtree of n is identical to T2.
That is, if you cut off the tree at node n, the two trees will be identical.
*/

#include<iostream>
#include "binaryTree.h"
bool isIdentical(node *root1, node *root2){
	if(root1 == NULL){
		if(root2 == NULL)
			return true;
		return false;
	}
	if(root2 == NULL){
		if(root1 == NULL)
			return true;
		return false;
	}
	return isIdentical(root1->left,root2->left) 
		&& isIdentical(root1->right,root2->right) 
		&& (root1->value == root2->value);
}
bool checkSubtree(node *root1, node *root2){
	if(root1 == NULL)
		return false;
	if(root1->value == root2-> value)
		return isIdentical(root1, root2);
	return checkSubtree(root1->left , root2) || checkSubtree(root1->right,root2);
}
int main(void){
	node * root1, *root2;
	createTree(&root1);
	createTree(&root2);
	if(checkSubtree(root1,root2))
		cout<<"T2 is a subtree of T1"<<endl;
	else
		cout<<"T2 is not a subtree of T1"<<endl;
	return 0;
}