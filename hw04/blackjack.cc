#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool IsInt (string str){
    string cards = "0123456789";
    int flag;
    int error = 0;
    if (str == ""){
        return false;
    }
    
    for (unsigned int i = 0; i < str.length() ; i++){
    	flag = 0;
        for (int j = 0; j < 14; j++){
            if (str[i] != cards[j]){
                flag++;
            }
            if(flag>13) error++;
        }
    }
    if (error==0){
        return true;
    }
    else {
        return false;
    }
}

bool IsCard(vector<string> s){
	bool result = true;

	for(vector<string>::iterator it = s.begin(); it != s.end(); ++it){
		if(IsInt(*it)) result *= (stoi(*it)<=10);
		else result *= (*it == "A" || *it == "J" || *it == "Q" || *it == "K");
	}
	return result;
}

int Total(vector<string> s){
	int total = 0;
	
	if(!IsCard(s)) return -1;
	
	for(vector<string>::iterator it = s.begin()+1; it != s.end(); ++it){
		if(IsInt(*it)) total += stoi(*it);
		else if(*it == "A") total += 11;
		else total +=10;
	}
	return total;
}

int NumA(vector<string> s){
	int numA = 0;

	for(vector<string>::iterator it = s.begin(); it != s.end(); ++it){
		if(*it == "A") numA++;
	}
	return numA;
}

int Judgement(string s){
	vector<string> command;
	
	while(true){
		int space;
		space = s.find(' ');
		command.push_back(s.substr(0,space));
		if (space >= s.length()){
			break;
		}
		else{
			s.erase(0, space + 1);
		}
	}
	
	int numA = NumA(command);
	int total = Total(command);
	
	if(total==-1) return total;
	
	for(int i=0; i<numA; i++){
		if(total>21) total -=10;
		else return total;
	}
	return total;
}


int main(){
	string commands;
	int result;
	while (true){
		getline(cin, commands);
		if(commands.size() == 1){
			return -1;
		}
		
		result = Judgement(commands);
		if (result == -1) return -1;
		else if (result == 21){
			cout << "BlackJack" << endl;
		}
		else if (result > 21){
			cout << "Exceed" << endl;
		}
		else{
			cout << result << endl;
		}
	}
}
