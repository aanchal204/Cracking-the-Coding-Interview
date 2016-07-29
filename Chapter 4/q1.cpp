/*
Route between nodes: Given a directed graph, design an algorithm to find out whether there is a route
between two nodes.
*/

#include<vector>
#include<list>
#include<iostream>
#define SIZE 100
using namespace std;
vector<list<int> > adjList;

bool routeExists(int end, bool *visited, int current){
	if(current == end)
		return true;
	visited[current] = true;
	bool res = false;
	for(list<int>::iterator i=adjList[current].begin();i!=adjList[current].end();i++){
		if(!visited[*i])
			res = res | routeExists(end,visited,*i);
	}
	return res;
}
int main(void){
	bool visited[SIZE] = {0};
	int x,y,nodes;
	cout<<"Enter the number of vertices"<<endl;
	cin>>nodes;
	adjList.resize(nodes+1);
	cout<<"Enter edges: (-1 -1 to stop)"<<endl;
	cin>>x>>y;
	do{
		adjList[x].push_back(y);
		cin>>x>>y;
	}while(x!=-1 && y!=-1);
	cout<<"Enter nodes to find if a route exists between them"<<endl;
	cin>>x>>y;
	cout<<routeExists(y,visited,x);
	return 0;
}