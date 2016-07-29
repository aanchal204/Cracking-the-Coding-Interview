/*
Valid BST:  Implement a function to check if a binary tree is a binary search tree

BST: left <= current < right
*/

#include<iostream>
#include<climits>
#include "binaryTree.h"
using namespace std;
bool isBST(node *root, int min, int max){
	if(root == NULL)
		return true;
	if(root->value <= min || root->value > max)
		return false;
	return isBST(root->left,min,root->value) && isBST(root->right,root->value,max);
}
int main(void){
	node *root = NULL;
	createTree(&root);
	cout<<isBST(root,INT_MIN, INT_MAX)<<endl;
	return 0;
}