#include"binary_search.h"
#include<iostream>
using namespace std;

BinarySearch::BinarySearch(){
	mArray= NULL ;
	mArrayCount= 0;
}

void BinarySearch::sortArray(){
	int temp=0;
	for(int i=0;i<mArrayCount;i++){
		for(int j=0;j<mArrayCount;j++){
			if(mArray[i]<mArray[j]){
				temp=mArray[i];
				mArray[i]=mArray[j];
				mArray[j]=temp;
			}
		}
	}
}

BinarySearch::BinarySearch(int *_array,int _arrayCount){
	mArray = new int[1024];
	for(int i=0;i<_arrayCount;i++){
		mArray[i]=_array[i];
	}
	mArrayCount=_arrayCount;
}

BinarySearch::~BinarySearch(){
	delete[] mArray;
}

int BinarySearch::getIndex(int _element){
	for(int i=0;i<mArrayCount;i++){
		if(mArray[i]==_element) return i;
	}
	return -1;
}
