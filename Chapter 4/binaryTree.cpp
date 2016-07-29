#include "binaryTree.h"
void insert(node **root, int val){
	node *newNode = new node;
	newNode->value = val;
	newNode->left = newNode->right = NULL;
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