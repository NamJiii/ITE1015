#include"reply_admin.h"

ReplyAdmin::ReplyAdmin(){
	chats = new string [NUM_OF_CHAT];
	addChat("Hello, Reply Administrator!");
	addChat("I will be a good programmer.");
	addChat("This class is awesome.");
	addChat("Professor Lim is wise.");
	addChat("Two TAs are kind and helpful.");
	addChat("I think male TA looks cool.");
}

ReplyAdmin::~ReplyAdmin(){
	delete[] chats;
}

int ReplyAdmin::getChatCount(){
	int i;
	for(i=0;i<NUM_OF_CHAT; ++i){
		string s = chats[i];
		if(s.empty()==true){
			break;
		}
	}
	return i;
}

bool ReplyAdmin::addChat(string _chat){
	int count = getChatCount();
	chats[count] = _chat;
	return true;
}

bool ReplyAdmin::removeChat(int _index){
	int count = getChatCount();
	if(_index>count-1 || _index < 0){
		return true;
	}
	chats[_index] = "";
	for(int i=0; i<count ; i++){
		if(chats[i].empty()){
			chats[i] = chats[i+1];
			chats[i+1] = "";
		}
	}
	return true;
}

bool ReplyAdmin::removeChat(int *_indices, int _count){
	int removed=0;
	for(int i = 0; i<_count; i++){
		removed += removeChat(_indices[i]-removed);
	}

	if(removed>0) return true;
	else return false;
}

bool ReplyAdmin::removeChat(int _start, int _end){
	int success = 0;
	if(_start<0) _start = 0;
	if(_end>getChatCount()) _end=getChatCount();
	for(int i=0; _start<= _end ; _start++, i++){
		success += removeChat(_start-i);}
	return success;
}

void ReplyAdmin::printChat(){
	for (int i=0;i<getChatCount(); i++){
		cout << i << " " << chats[i] << endl;
	}
}

