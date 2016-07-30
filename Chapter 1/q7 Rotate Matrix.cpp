/*Rotate Matrix: Given an image represented by an NxN matrix where each pixel in the image is 4 bytes,
write a method to rotate the image by 90 degrees.

Rotate anticlockwise 90 degrees -> take transpose, reverse each column
*/
#include<iostream>
#include<vector>
using namespace std;
void printMatrix(vector<vector<int> >arr, int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}
vector<vector<int> > transpose(vector<vector<int> > arr, int n){
	vector<vector<int> > temp;
	for(int i=0;i<n;i++){
		vector<int> row;
		for(int j=0;j<n;j++){
			row.push_back(arr[j][i]);
		}
		temp.push_back(row);
	}
	return temp;
}
vector<vector<int> > revCol(vector<vector<int> > arr, int n){
	for(int col=0;col<n;col++){
		for(int i=0;i<n/2;i++){
			int temp = arr[i][col];
			arr[i][col] = arr[n-i-1][col];
			arr[n-i-1][col] = temp;
		}
	}
	return arr;
}
vector<vector<int> > rotateMatrix(vector<vector<int> > arr, int n){
	arr = transpose(arr,n);
	arr = revCol(arr,n);
	return arr;
}
int main(void){
	int n,x;
	cout<<"Enter size of matrix"<<endl;
	cin>>n;
	vector< vector<int> > arr;
	cout<<"Enter the matrix in row-first form"<<endl;
	for(int i=0;i<n;i++){
		vector<int> row;
		for(int j=0;j<n;j++){
			cin>>x;
			row.push_back(x);
		}
		arr.push_back(row);
	}
	arr = rotateMatrix(arr,n);
	printMatrix(arr,n);
	return 0;
}