#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>

using namespace std;

string RadixNotation(unsigned int number, unsigned int radix){
	char rst[31]="";
	int cnt=0;
	while(1){
		unsigned int tmp = number % radix;
		cnt++;
		if(tmp<10){
			rst[0] = tmp+48;
		}
		else{
			rst[0] = tmp+87;
		}
		number /= radix;

		if(number<=0) break;

		memmove(rst+1,rst,cnt);
	}
	return rst;
}

int main(int argc, char** argv){
	if (argc<2) return -1;
	unsigned int radix;
	sscanf(argv[1], "%u",&radix);
	if(radix<2 || radix>36) return -1;
	for(int i=2;i<argc;++i){
		unsigned int number;
		sscanf(argv[i], "%u", &number);
		cout << RadixNotation(number, radix) << endl;
	}
	return 0;
}
