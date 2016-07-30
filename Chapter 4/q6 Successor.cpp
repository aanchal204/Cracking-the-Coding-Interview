/*
Successor : Write an algorithm to find the next node(i.e. inorder successor) of a given node 
in a binary search tree. You may assume that each node has a link to its parent node

Approach : If a right node exists, return the left most node in the right sub tree
else, go to the parent until the child is a left child of the parent
*/
#include<iostream>
using namespace std;
typedef struct node{
	int value;
	struct node *left, *right,*parent;
}node;
void insert(node **root, int val){
	node *newNode = new node;
	newNode->value = val;
	newNode->left = newNode->right = NULL;
	newNode->parent = NULL;
	if(*root == NULL)
		*root = newNode;
	else{
		node *temp = *root;
		node *prev;
		while(temp!=NULL){
			prev = temp;
			if(temp->value > newNode->value){
				
				temp = temp->left;
			}
			else{
				temp = temp->right;
			}
		}
		newNode->parent = prev;
		if(prev->value > newNode->value)
			prev->left = newNode;
		else
			prev->right = newNode;
	}
}
void preOrder(node *root){
	if(root == NULL)
		return;
	cout<<root->value<<" ";
	preOrder(root->left);
	preOrder(root->right);
}
void createTree(node **root){
	cout<<"Enter elements of array (-1 to stop):"<<endl;
	int x;
	cin>>x;
	do{
		insert(root,x);
		cin>>x;
	}while(x!=-1);
}
node * leftMostChild(node *root){
	while(root->left)
		root = root->left;
	return root;
}
node *successor(node *root){
	if(root->right){
		return leftMostChild(root->right);
	}
	node *parent = root->parent;
	while(parent!=NULL && parent->left!=root){
		root = parent;
		parent = root->parent;
	}
	return parent;
}
int main(void){
	node *root = NULL;
	createTree(&root);
	node *succ = successor(root);
	if(succ)
		cout<<succ->value<<endl;
	else
		cout<<"No successor"<<endl;
	return 0;
}