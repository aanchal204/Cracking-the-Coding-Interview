/*
Zero Matrix: Write a space efficient algorithm, such that if an element in MxN is 0, 
the entire row and column containing it are 0.
*/
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int> > zeroMatrix(vector<vector<int> >arr, int m, int n){
	bool isFirstRowZero, isFirstColZero;
	isFirstColZero = isFirstRowZero = false;
	//first Row
	for(int i=0;i<n;i++){
		if(arr[0][i] == 0){
			isFirstRowZero = true;
			break;
		}
	}
	//first colummn
	for(int j=1;j<m;j++){
		if(arr[j][0] == 0){
			isFirstColZero = true;
			break;
		}
	}
	// rest of the matrix
	for(int i=1;i<m;i++){
		for(int j=1;j<n;j++){
			if(arr[i][j] == 0){
				arr[i][0] = arr[0][j] = 0;
			}
		}
	}
	// we have stored the info about which row and column needs to be made zero, in the first row and column
	for(int i=0;i<n;i++){
		if(!arr[0][i]){
			for(int j=0;j<m;j++)
				arr[j][i] = 0;
		}
	}
	for(int i=0;i<m;i++){
		if(!arr[i][0]){
			for(int j=0;j<n;j++)
				arr[i][j] = 0;
		}
	}
	if(isFirstRowZero)
		for(int i=0;i<n;i++)
			arr[0][i] = 0;
	if(isFirstColZero)
		for(int i=0;i<m;i++)
			arr[i][0] = 0;
	return arr;
}
void printMatrix(vector<vector<int> >arr, int m, int n){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main(void){
	int m,n,x;
	cout<<"Enter size of matrix(mxn)"<<endl;
	cin>>m>>n;
	vector<vector<int> >arr;
	for(int i=0;i<m;i++){
		vector<int> row;
		for(int j=0;j<n;j++){
			cin>>x;
			row.push_back(x);
		}
		arr.push_back(row);
	}
	arr = zeroMatrix(arr,m,n);
	printMatrix(arr,m,n);
}