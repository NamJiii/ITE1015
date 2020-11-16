#include<iostream>
using namespace std;
int cnt=1;

int fibo(int count){
	int num;
	if(count==1){
		num=1;
	}
	else if(count<1){
		num=0;
	}
	else num = fibo(count-1)+fibo(count-2);

	if (count==cnt){
		cnt++;
		cout << num << " ";
	}
	return num;
}

int main(){
	int count;
	cin >> count;
	if(count<1){
		return 0;
	}
	fibo(count);
	return 0;
}
