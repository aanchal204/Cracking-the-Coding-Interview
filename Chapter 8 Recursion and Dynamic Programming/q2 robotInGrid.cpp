/*
Robot in a grid: Imagine a robot sitting in the upper left corner of a grid with r rows and c columns.
The robot can move in only 2 directions : right and down, but certain cells are off-limit such that
the robot cannot step on them.Design an algorithm to find a path for the robot from the upper left
to the bottom right.

0 : off-limit cell
*/
#include<iostream>
#include<stdlib.h>
#define SIZE 100
using namespace std;
void createGrid(int row, int col,int grid[][SIZE]){
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			int random = rand()%100 + 1;
			if(random%3)
				grid[i][j] = 1;
			else
				grid[i][j] = 0;
		}
	}
	grid[0][0] = grid[row-1][col-1] = 1;
}
bool findPath(int row, int col, int grid[][SIZE],int curr_r, int curr_c){
	if(curr_r == row-1 && curr_c == col-1){
		grid[curr_r][curr_c] = 2;
		return true;
	}
	if(!grid[curr_r][curr_c])
		return false;
	bool right, down;
	right = down = false;
	if(curr_c < col-1)
		right = findPath(row,col,grid,curr_r,curr_c+1);
	if(curr_r < row-1 && !right)
		down = findPath(row,col,grid,curr_r+1,curr_c);
	if(right || down){
		grid[curr_r][curr_c] = 2;
		return true;
	}
	grid[curr_r][curr_c] = 0;
	return false;
}
int main(void){
	int grid[SIZE][SIZE];
	int row,col;
	cin>>row>>col;
	createGrid(row,col,grid);
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++)
			cout<<grid[i][j];
		cout<<endl;
	}
	// cout<<findPath(row, col,grid,0,0)<<endl;
	if(findPath(row,col,grid,0,0)){
		cout<<"Path exists"<<endl;
	}else
		cout<<"Path doesnt exist."<<endl;
	//while printing, the cells with 2 indicate the path
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++)
			cout<<grid[i][j];
		cout<<endl;
	}
	return 0;
}