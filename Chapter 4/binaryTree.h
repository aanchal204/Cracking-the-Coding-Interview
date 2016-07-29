#include<vector>
#include<iostream>
using namespace std;
typedef struct node{
	int value;
	struct node *left, *right;
}node;
void insert(node **root, int val);
void preOrder(node *root);
void createTree(node **root);