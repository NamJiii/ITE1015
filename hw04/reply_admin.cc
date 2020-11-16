#include"reply_admin.h"

ReplyAdmin::ReplyAdmin(){
	std::list<string> chats;
	addChat("Hello, Reply Administrator!");
	addChat("I will be a good programmer.");
	addChat("This class is awesome.");
	addChat("Professor Lim is wise.");
	addChat("Two TAs are kind and helpful.");
	addChat("I think male TA looks cool.");
}

ReplyAdmin::~ReplyAdmin(){
}

bool ReplyAdmin::addChat(string _chat){
	if(_chat.find("#")==0) return true;
	chats.push_back(_chat);
	return true;
}

bool ReplyAdmin::removeChat(int _index){
	list<string>::iterator it = chats.begin();
	for(int i=0; i<_index;i++){
		it++;
	}
    chats.erase(it);
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
	list<string>::iterator ref_start, ref_end;
	ref_start = chats.begin();
	ref_end = chats.begin();
	for(int i=0; i<=_end; i++) ref_end++;
	for(int i=0; i<_start; i++) ref_start++;
	int size = chats.size();
	
	chats.erase(ref_start,ref_end);
	if(size>chats.size()) return true;
	else return false;
}

void ReplyAdmin::printChat(){
	int index = 0;
	for(list<string>::iterator it = chats.begin(); it != chats.end(); it++){
	cout << index << " " << *it << endl;
	index++;}
}

