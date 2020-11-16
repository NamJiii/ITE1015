#include<iostream>
#include<stdio.h>
using namespace std;

string primeFactorization(unsigned unit_number){
	int time;
	int i=1;
	while(1){
		i++;
		time =0;
		if(unit_number%i==0){
			while(unit_number%i==0 && unit_number!=1){
			unit_number/=i;
			time++;
			}
			cout << i << "^" << time;
			if(unit_number==1)
				return "";
			cout << " x ";
		}
	}
}

int main(int argc, char** argv){
	if(argc<1) return -1;
	unsigned int number;
	sscanf(argv[1],"%u",&number);
	cout << primeFactorization(number) << endl;
	return 0;
}
