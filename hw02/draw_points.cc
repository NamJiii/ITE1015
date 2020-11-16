#include<iostream>
using namespace std;
char plane[200][200];
int maxx=0;
int maxy=0;

void initialize(){
	for(int i=0; i<200; i++){
		for(int j=0;j<200;j++){
			plane[i][j]='.';
		}
	}
}

void draw_points(int x,int y){
	if(maxx<x) maxx=x;
	if(maxy<y) maxy=y;

	plane[x][y] = '*';

	for(int i=0; i<=maxy;i++){
		for(int j=0;j<=maxx;j++){
			cout << plane[j][i];
		}
		cout<<endl;
	}
}

int main(){
	initialize();

	int x;
	int y;

	while(1){
		cin >> x >> y;
		if(x<0|| y<0) break;
		draw_points(x,y);
	}
	return 0;
}
