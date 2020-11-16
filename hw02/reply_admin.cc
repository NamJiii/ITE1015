#include<iostream>
#include<string>
#include<stdio.h>
#include<cstring>

using namespace std;

const int NUM_OF_CHAT = 200;
int getChatCount(string *_chatList)
{
	int i;
	for (i=0 ; i< NUM_OF_CHAT; ++i){
		string s= _chatList[i];
		if(s.empty() == true){
			break;}
	}
	return i;
}

void printChat(string *_chatList){
	int count = getChatCount(_chatList);
	for(int i=0; i<count; ++i){
		cout << i << " " << _chatList[i] << endl;
	}
}

bool addChat(string *_chatList, string _chat){
	int count = getChatCount(_chatList);
	_chatList[count] = _chat;
	return true;
}

bool removeChat(string *_chatList, int _index){
	int count = getChatCount(_chatList);
	if (_index > count-1 || _index < 0){
		return true;
	}
	_chatList[_index] = "";
	for(int i=0; i<count;i++){
		if(_chatList[i].empty()){
			_chatList[i] = _chatList[i+1];
			_chatList[i+1] = "";
		}
	}
	return true;
}

int isInt(string a){
	string integers = ",-1234567890";
	int flag;
	int error=0;

	for(int i = 0; i<a.length(); i++){
		flag=0;
		for(int j=0; j<12; j++){
			if(a[i] != integers[j]){
				flag++;
			}
			if(flag>11) error++;
		}
	}
	if(error==0){
		return 1;
	}
	else{
		return 0;
	}
}

int main(void){
	string *chats = new string[NUM_OF_CHAT];

	addChat(chats, "Hello, Reply Administrator!");
	addChat(chats, "I will be a good programmer.");
	addChat(chats, "This class is awesome.");
	addChat(chats, "professor Lim is wise.");
	addChat(chats, "Two TAs are kind and helpful.");
	addChat(chats, "I think male TA loos cool.");

	while (true){
		int success = 0;
		string command;
		getline(cin, command);

		if(command.find("#quit") == 0){
			break;
		}
		else if(command.find("#remove") == 0){
			int comma;
			int hyphen;
			comma = command.find(',');
			hyphen = command.find('-');

			if(comma == -1 && hyphen == -1 && command.length()>7){
				success = removeChat(chats, stoi(command.substr(8,command.length())));
			}

			else if (comma != -1 && hyphen != -1){
				break;}

			else if (comma != -1){
				int count = 0;
				int array[command.length()];

				char* result = strtok(&command[8],",");
				while(result != NULL){
					array[count++] = stoi(result);
					result = strtok(NULL,",");
				}

				for ( int i=0 ; i< count; i++){
					success = removeChat(chats, array[i]-i);
				}
			}

			else if (hyphen != -1){
				int front, back;
				front = stoi(command.substr(8,hyphen));
				back = stoi(command.substr(hyphen + 1, command.length()));

				for(int i=0; front <= back ; front++, i++){
					success = removeChat(chats, front - i);
				}
			}

			else { continue;
			}
		}
		
		if(success) printChat(chats);

		if(command[0] != '#'){
			addChat(chats, command);
			printChat(chats);
		}
	}
	delete[] chats;

	return 0;
}
