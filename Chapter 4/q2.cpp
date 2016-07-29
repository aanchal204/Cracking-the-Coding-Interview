/*
Minimal Tree: Given a sorted array with unique integer elements, write an algorithm to create a 
binary search tree with minimal height.
*/
#include<iostream>
#include<vector>
#include "binaryTree.h"
using namespace std;

void createBSTHelper(vector<int> arr, node **root){
	if(arr.empty())
		return;
	int mid = arr.size()/2;
	insert(root, arr[mid]);
	vector<int> left,right;
	int i;
	for(i=0;i<mid;i++)
		left.push_back(arr[i]);
	for(i++;i<arr.size();i++)
		right.push_back(arr[i]);
	createBSTHelper(left , root);
	createBSTHelper(right , root);
}

node * createBinarySearchTree(vector<int> arr){
	node * root = NULL;
	createBSTHelper(arr,&root);
	return root;
}

int main(void){
	vector<int>arr;
	cout<<"Enter elements of array (-1 to stop):"<<endl;
	int x;
	cin>>x;
	do{
		arr.push_back(x);
		cin>>x;
	}while(x!=-1);
	node *root = createBinarySearchTree(arr);
	preOrder(root);
	return 0;
}