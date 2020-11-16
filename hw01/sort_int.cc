#include<iostream>
using namespace std;

void sort_int(int *arr,int num){
	int temp=0;
	for(int i=0;i<num;i++){
		for(int j=0;j<num;j++){
			if(arr[i]<arr[j]){
				temp = arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	for(int i=0;i<num;i++){
		cout << arr[i] << " ";
	}
}

int main(){
	int num;
	cin >> num;
	int *arr = new int[num];
	if(num<=0){
		return 0;
	}

	for(int i=0; i<num; i++){
		cin >> arr[i];
	}
	sort_int(arr,num);
	delete [] arr;
	return 0;
}
