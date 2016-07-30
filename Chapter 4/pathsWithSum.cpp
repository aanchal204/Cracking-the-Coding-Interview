/*
Paths with Sum : You are given a binary tree in which each node contains an integer value. Design an algorithm
to count the number of paths that sum to a given value. The path does not need to start or end at the root
or the leaf, but it must go downwards.
*/
#include<iostream>
#include<unordered_set>	//hash table
#include "binaryTree.h"
int pathsWithSumUtil(node *root, int target, int current, unordered_multiset<int> hashTable){
	if(root == NULL)
		return 0;
	int totalPaths = 0;
	current += root->value;
	totalPaths += hashTable.count(current - target);
	if(current == target)
		totalPaths++;
	hashTable.insert(current);
	int leftPath,rightPath;
	leftPath = rightPath = 0;
	leftPath = pathsWithSumUtil(root->left,target,current,hashTable);
	rightPath = pathsWithSumUtil(root->right,target,current,hashTable);
	hashTable.erase(current);
	return totalPaths + leftPath + rightPath;
}
int pathsWithSum(node *root, int target){
	unordered_multiset<int> hashTable;
	return pathsWithSumUtil(root,target,0,hashTable);
}
int main(void){
	node *root = NULL;
	createTree(&root);
	int target;
	cout<<"Enter the desired sum"<<endl;
	cin>>target;
	int paths = pathsWithSum(root,target);
	cout<<paths<<endl;
	return 0;
}