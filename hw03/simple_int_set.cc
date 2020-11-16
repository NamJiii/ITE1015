#include "simple_int_set.h"
#include <iostream>
using namespace std;

void SimpleIntSet::sortElements(){
	int temp=0;
	for(int i=0;i<mElementCount;i++){
		for(int j=0;j<mElementCount;j++){
			if(mElements[i]<mElements[j]){
				temp = mElements[i];
				mElements[i]=mElements[j];
				mElements[j]=temp;
			}
		}
	}
}

SimpleIntSet::SimpleIntSet(){
	mElements = NULL;
	mElementCount = 0;
}

SimpleIntSet::SimpleIntSet(int *_elements, int _count){
	mElements = new int[MAX_SIZE];
	for(int i=0;i<_count;i++){
		mElements[i]=_elements[i];}
	mElementCount = _count;
	sortElements();
}

SimpleIntSet::~SimpleIntSet(){
	delete[] mElements;
}

int* SimpleIntSet::elements() const{
	return mElements;
}

int SimpleIntSet::elementCount() const{
	return mElementCount;
}

SimpleIntSet *SimpleIntSet::intersectSet(SimpleIntSet&_operand){
	int oparr[MAX_SIZE];
	int* arr = new int[MAX_SIZE];
	int count=0;

	for(int i=0; i< _operand.elementCount();i++){
		oparr[i] = _operand.elements()[i];
	}

	for(int i=0 ; i< mElementCount;i++){
		for(int j=0 ; j<_operand.elementCount();j++){
			if(mElements[i] == oparr[j]){
					arr[count++] = mElements[i];
			}
		}
	}

	for(int i=0; i<count ; i++){
	mElements[i] = arr[i];
	}
	mElements[count] = '\0';
	mElementCount = count;

	sortElements();
	return this;
}

SimpleIntSet *SimpleIntSet::differenceSet(SimpleIntSet& _operand){
	int a = 0;
	int k = 0;

	int* arr = new int[MAX_SIZE];
	int arr2[MAX_SIZE];

	for(int i=0; i<mElementCount;i++){
		for (int j=0;j<_operand.elementCount();j++){
			if(mElements[i] == _operand.elements()[j]){
				arr2[k++] = mElements[i];
			}
		}
	}

	int temp;
	for (int i=0;i<mElementCount;i++){
		temp=0;
		for(int j=0;j<k;j++){
			if(mElements[i] != arr2[j]){
					temp++;
			}
		}
		if(temp==k)
		arr[a++] = mElements[i];
	}
	for(int i=0;i<a;i++){
		mElements[i]=arr[i];
	}
	mElements[a] = '\0';
	mElementCount = a;

	sortElements();
	return this;
}

SimpleIntSet *SimpleIntSet::unionSet(SimpleIntSet& _operand){
	int* arr = new int [2*MAX_SIZE];
	int cnt=0;

	for(int i=0; i<mElementCount;i++){
		arr[cnt++] = mElements[i];
	}
	for(int i=0;i<_operand.elementCount();i++){
		arr[cnt++] =_operand.elements()[i];
	}
	for(int i=0;i<cnt;i++){
		for(int j=i+1;j<cnt;j++){
			if(arr[i] == arr[j]){
				for(int k = j; k<cnt;k++){
					arr[k] = arr[k+1];
				}
				cnt--;
			}
			else
				j++;
		}
	}
	for(int i=0; i<cnt ; i++){
		mElements[i]=arr[i];
	}
	mElements[cnt] = '\0';
	mElementCount = cnt;
	return this;
}

void SimpleIntSet::printSet(){
	cout << "{";
	for(int i=0 ; i<elementCount() ; i++){
		cout << " " << elements()[i];
	}
	cout << " " << "}" << endl;
}

