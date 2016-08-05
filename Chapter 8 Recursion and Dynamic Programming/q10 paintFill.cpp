/*
Paint Fill : Implement the paint fill function that one might see on several image editing programs.
That is, given a screen represented by a two dimensional array of colors, a point and a new color, fill
in the surrounding area until the color changes from the orignal color.
*/
#include<iostream>
using namespace std;
#define SIZE 100
char screen[SIZE][SIZE];
void paint(int r, int c, char ncolor, char ocolor){
	if(r<0 || c<0 || r>=SIZE || c>=SIZE)
		return;
	if(screen[r][c] == ocolor){
		screen[r][c] = ncolor;
		paint(r,c+1,ncolor,ocolor);
		paint(r+1,c,ncolor,ocolor);
		paint(r,c-1,ncolor,ocolor);
		paint(r-1,c,ncolor,ocolor);
	}
}
void paintFill(int r, int c, char ncolor){
	if(screen[r][c] == ncolor)
		return;
	screen[r+1][c+1] = 'x';
	paint(r,c,ncolor,screen[r][c]);
	for(int i=0;i<SIZE;i++){
		for(int j=0;j<SIZE;j++)
			cout<<screen[i][j];
		cout<<endl;
	}
}
int main(void){
	int r,c;
	cin>>r>>c;
	char ncolor;
	cin>>ncolor;
	paintFill(r,c,ncolor);
	return 0;
}