/*
Random Node : You are implementing a binary tree class from scratch, which in addition to find, insert, and delete, 
has a method called getRandomNode() that returns a random node from the tree. All nodes should be equally likely 
to be chosen. Design and implement an algorithm to get RandomNode() and explain how you would implement
the rest of the methods
*/
#include<iostream>
#include<vector>
#include<cstdlib>		//random
using namespace std;
typedef struct node{
	int value;
	struct node *left, *right;
	int leftSize,rightSize;
}node;
void insert(node **root, int val){
	node *newNode = new node;
	newNode->value = val;
	newNode->left = newNode->right = NULL;
	newNode->leftSize = newNode->rightSize = 0;
	if(*root == NULL)
		*root = newNode;
	else{
		node *temp = *root;
		node *prev;
		while(temp!=NULL){
			prev = temp;
			if(temp->value > newNode->value){
				temp->leftSize++;
				temp = temp->left;
			}
			else{
				temp->rightSize++;
				temp = temp->right;
			}
		}
		if(prev->value > newNode->value){
			prev->left = newNode;
		}
		else{
			prev->right = newNode;
		}
	}
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
node *getRandomNode(node *root){
	int r = rand()%(root->leftSize + root->rightSize + 1) + 1;
	cout<<r<<endl;
	if(r<=root->leftSize){
		//go left
		return getRandomNode(root->left);
	}else if(r == root->leftSize+1){
		return root;
	}else{
		return getRandomNode(root->right);
	}
}
int main(void){
	node *root = NULL;
	createTree(&root);
	node *randomeNode = getRandomNode(root);
	cout<<randomeNode->value<<endl;
	return 0;
}