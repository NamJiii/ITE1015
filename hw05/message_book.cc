#include <iostream>
#include <string>
#include <map>
#include <vector>

#include "message_book.h"

using namespace std;

MessageBook::MessageBook()
{
}

MessageBook::~MessageBook()
{
}

void MessageBook::AddMessage(int number, const string& message)
{
	if ( messages_.find(number) != messages_.end() )
	{
		messages_[number] = message;
	}
	else
	{
		messages_.insert(make_pair(number, message));
	}
}

void MessageBook::DeleteMessage(int number)
{
	messages_.erase(number);
}

vector<int> MessageBook::GetNumbers()
{
	vector<int> intvector;
	for ( map<int, string>::iterator it = messages_.begin(); it != messages_.end(); ++it )
	{
		intvector.push_back(it->first);
	}
	return intvector;
}

const string& MessageBook::GetMessage(int number) const
{
	map<int, string>::const_iterator it = messages_.find(number);
	return ( it->second );
}

bool isInt(string a)
{
	string integers = "1234567890";
	int flag;
	int error = 0;

	for ( unsigned int i = 0; i < a.length(); i++ )
	{
		flag = 0;
		for ( int j = 0; j<10; j++ )
		{
			if ( a[i] != integers[j] )
			{
				flag++;
			}
			if ( flag>9 ) error++;
		}
	}
	if ( error == 0 )
	{
		return true;
	}
	else
	{
		return false;
	}
}