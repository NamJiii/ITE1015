#include<iostream>
using namespace std;

int i=0;
int j=0;
int size=0;

int rightup(){
	i--;
	j++;
	if(i==-1){
		i=size-1;
	}
	if(j==size){
		j=0;
	}
	return 0;
}

int down(){
	i++;
	if(i==size){
		i=0;
	}
	return 0;
}

int main(){
	int num=1;
	int tempi, tempj;
	cin >> size;
	if(size<3 || size%2==0){
		return 0;
	}

	int **array = new int *[size];
	for(int k=0; k<size; k++){
		array[k] = new int[size];
	}

	for(int a=0;a<size;a++){
		for(int b=0;b<size;b++){
			array[a][b]=0;
		}
	}

	i=0;
	j=size/2;

	while(num<=size*size){
		array[i][j]=num;
		tempi=i;
		tempj=j;
		rightup();
		if(array[i][j]!=0){
			i=tempi;
			j=tempj;
			down();
		}
		num++;
	}

	for(int a=0;a<size;a++){
		for(int b=0;b<size;b++){
			cout<< array[a][b] << " ";
		}
		cout << endl;
	}

	for(i=0; i<size;i++){
		delete[] array[i];
	}
	delete[] array;
}
