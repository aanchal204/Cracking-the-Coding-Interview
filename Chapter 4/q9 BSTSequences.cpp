/*
BST Sequences: A binary search tree was created by tranversing an array from left to right
and inserting each element.Given a binary search tree with distinct elements, print all possible
arrays that could have led to this tree.

Refer: http://stackoverflow.com/questions/21211701/given-a-bst-and-its-root-print-all-sequences-of-nodes-which-give-rise-to-the-sa
*/

#include<iostream>
#include<vector>
#include"binaryTree.h"
using namespace std;
vector<vector<int> > interleave(vector<int> leftSeq, vector<int> rightSeq,  vector<int> prefix){
	if(leftSeq.size() == 0 || rightSeq.size() == 0){
		vector<vector<int> > res;
		vector<int> prefix_clone(prefix);
		if(leftSeq.size())
			prefix_clone.insert(prefix_clone.end(),leftSeq.begin(),leftSeq.end());
		if(rightSeq.size())
			prefix_clone.insert(prefix_clone.end(),rightSeq.begin(),rightSeq.end());
		res.push_back(prefix_clone);
		return res;
	}
	vector<vector<int> > res;
	//take a value from left sequence and append to prefix and recurse
	int element = leftSeq.front();
	leftSeq.erase(leftSeq.begin());
	prefix.push_back(element);
	vector<vector<int> > temp;
	temp = interleave(leftSeq , rightSeq  , prefix);
	for(int i=0;i<temp.size();i++)
		res.push_back(temp[i]);
	//undo the changes i.e. pop the last element from prefix and insert in the beginning of leftSeq
	element = prefix.back();
	prefix.pop_back();
	leftSeq.insert(leftSeq.begin() , element);

	//do the same with the right sequence
	element = rightSeq.front();
	rightSeq.erase(rightSeq.begin());
	prefix.push_back(element);
	// temp = interleave(leftSeq,rightSeq,prefix);
	temp = interleave(leftSeq , rightSeq  , prefix);
	for(int i=0;i<temp.size();i++)
		res.push_back(temp[i]);
	element = prefix.back();
	prefix.pop_back();
	rightSeq.insert(rightSeq.begin(),element);
	return res;
}
vector<vector<int> > BSTSequences(node *root){
	vector<vector<int> > sequences;
	if(root == NULL){
		vector<int> v;
		sequences.push_back(v);
		return sequences;
	}
	//if a child node, no need to traverse the left and right subtrees
	if(root->left == NULL && root->right == NULL){
		vector<int> v;
		v.push_back(root->value);
		sequences.push_back(v);
		return sequences;
	}
	//find the left and right sequences and interleave them together
	vector<vector<int> > leftSeq = BSTSequences(root->left);
	vector<vector<int> > rightSeq = BSTSequences(root->right);
	vector<int> prefix;
	prefix.push_back(root->value);
	for(int i=0;i<leftSeq.size();i++){
		for(int j=0;j<rightSeq.size();j++){
			vector<vector<int> >res;
			res = interleave(leftSeq[i] , rightSeq[j] , prefix);
			for(int k=0;k<res.size();k++)
				sequences.push_back(res[k]);
		}
	}
	return sequences;
}

int main(void){
	node *root = NULL;
	createTree(&root);
	vector<vector<int> > sequences = BSTSequences(root);
	cout<<sequences.size()<<endl;
	for(int i=0;i<sequences.size();i++){
		for(int j=0;j<sequences[i].size();j++)
			cout<<sequences[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}