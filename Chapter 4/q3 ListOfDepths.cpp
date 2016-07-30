/*
List of depths: Given a binary tree, design an algorithm which creates a linked list
of all the nodes at each depth (i.e. if you have a tree with depth D, you will have D linked lists)
*/
#include<iostream>
#include<vector>
#include "binaryTree.h"
#define SIZE 100
using namespace std;
vector<node> LL [SIZE];
void ListOfDepths(int depth, node *root){
	if(root == NULL)
		return;
	LL[depth].push_back(*root);
	ListOfDepths(depth+1,root->left);
	ListOfDepths(depth+1,root->right);
}
int main(void){
	node *root = NULL;
	createTree(&root);
	ListOfDepths(0,root);
	int i=0;
	while(LL[i].size()){
		int j=0;
		while(j<LL[i].size()){
			cout<<LL[i][j].value<<" ";
			j++;
		}
		cout<<endl;
		i++;
	}
	return 0;
}