#ifndef _MESSAGE_BOOK_H_
#define _MESSAGE_BOOK_H_
#include<vector>

using namespace std;

class MessageBook
{

public:
	MessageBook();
	~MessageBook();

	void AddMessage(int number, const string& message);
	void DeleteMessage(int number);
	vector<int> GetNumbers();
	const string& GetMessage(int number) const;


private:
	map<int, string> messages_;
};

bool isInt(string a);
#endif