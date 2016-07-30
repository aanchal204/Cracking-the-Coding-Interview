/*
Check Balanced: Implement a function to check if a binary function is
balanced or not. 
A balanced tree is defined to be a tree such that the difference in the heights
between the two subtrees of a node is never greater than one
*/

#include<iostream>
#include "binaryTree.h"
using namespace std;
int max(int a,int b){
	return a>b?a:b;
}
int getHeight(node *root){
	if(root == NULL)
		return 0;
	return max(getHeight(root->left) , getHeight(root->right) ) + 1 ;
}
bool isBalanced(node *root){

	if(root==NULL)
		return true;
	int leftHt = getHeight(root->left);
	int rightHt = getHeight(root->right);
	return isBalanced(root->left) && isBalanced(root->right) && (abs(leftHt-rightHt)<=1);
}
int main(void){
	node *root = NULL;
	createTree(&root);
	cout<<getHeight(root)<<endl;
	if(isBalanced(root))
		cout<<"Balanced"<<endl;
	else
		cout<<"Not Balanced"<<endl;
	return 0;
}