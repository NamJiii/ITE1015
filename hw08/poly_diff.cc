#include <iostream>
#include <string>
#include "poly_diff.h"

using namespace std;


int Differ::sumValue(int x) {
	int size = splited_.size();
	int result = 0;
	
    for(int i = 0; i < size; i++){
    	splited_[i].Differentiate();
    }
    for(int i = 0; i < size; i++){
    	result += splited_[i].sumValue(x);
    }
    return result;
    
}

void Differ::Spliting(std::string data){
	int pos;
	string str;
	
	while(true){
		pos = data.find("+");
		if ( pos == -1){
			Splited back(data);
			splited_.push_back(back);
			break;
		}
		str = data.substr(0, pos);
		
		Splited splited(str);
		splited_.push_back(splited);
		
		data.erase(0,pos+1);
	
	}
}

Splited::Splited(string data) {

    int pos = data.find("x");
    int pos_ = data.find("^");
    string constant;
    string times;
    if(pos == -1 && pos_ == -1){
    	constant_ = stoi(data);
    	times_ = 0;
    }
    else if(pos != -1 && pos_ == -1){
    	times_ = 1;
    	if (pos == 0){
    		constant_ = 1;
    	}
    	else if (pos == 1 && data[0] == '-'){
    		constant_ = -1;
    	}
    	else {
    	   	constant = data.substr(0,pos);
    			constant_ = stoi(constant);
    	}
    }
    
    else {
   		times = data.substr(pos_+1);
   		times_ = stoi(times);
     	if (pos == 0){
     		constant_ = 1;
     	}
     	else if (pos == 1 && data[0] == '-'){
    		constant_ = -1;
    	}
     	else {
    	 	constant = data.substr(0,pos);
    		constant_ = stoi(constant);
     	}
    }

}


void Splited::Differentiate() {

		if (times_ <= 0){
    	constant_ = 0;
    }
    
    else {
    	constant_ = times_ * constant_;
   	 	times_ = times_ - 1;
    }
}


int Splited::sumValue(int x) {
    int result = 1;
    
    if (times_ == 0) {
    	result = constant_;
    }
    else {
		  for (int i = 0; i < times_; i ++){
		  	result *= x;
		  }
		  result = constant_ * result;
    }
    
    
   	return result;
}

