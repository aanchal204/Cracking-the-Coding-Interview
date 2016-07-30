/*
Build Order: You are given a list of projects and a list of dependencies (which is a list of pair of projects, where
the second project is dependent on the first). All of a project's dependencies must be built before the project is.
Find a build order that will allow the projects to be built. If there is no valid order, return an error.
*/

#include<iostream>
#include<vector>
#include<utility>		//pair
#include<list>
using namespace std;
vector<int> buildOrder(vector<int> incomingedges,int nodes,vector<list<int> > adjList){
	vector<int> order;
	while(order.size()<nodes){
		bool flag = false;
		for(int i=1;i<=nodes;i++){
			if(incomingedges[i]==0){
				flag = true;
				order.push_back(i);
				incomingedges[i] = -1;
				for(list<int>::iterator j = adjList[i].begin();
					j!=adjList[i].end();
					j++){
					incomingedges[*j]--;
				}
			}
		}
		if(!flag)
			return order;
	}
	return order;
}

int main(void){
	int nodes;
	vector<list<int> > adjList;
	cout<<"Enter number of nodes"<<endl;
	cin>>nodes;
	int x,y;
	cout<<"Enter the dependencies (-1 -1 to stop):"<<endl;
	cin>>x>>y;
	vector<pair<int, int> > dependencies;
	vector<int> incomingedges(nodes+1, 0);
	adjList.resize(nodes+1);
	while(x!=-1 && y!=-1){
		dependencies.push_back(make_pair(x,y));
		incomingedges[y]++;
		adjList[x].push_back(y);
		cin>>x>>y;
	}
	vector<int>  order = buildOrder(incomingedges,nodes,adjList);
	if(order.size() == nodes){
		for(int i=0;i<order.size();i++)
			cout<<order[i]<<" ";
		cout<<endl;
	}else{
		cout<<"No build order possible"<<endl;
	}
	return 0;
}