#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "message_book.h"

using namespace std;

int main(void)
{
	bool check = false;
	MessageBook messagebook;

	while ( true )
	{
		string order;
		vector<string> input;
		getline(cin, order);

		if ( order == "quit" )
		{
			return 0;
		}

		else if ( order == "list" )
		{
			vector<int> intvec = messagebook.GetNumbers();
			for ( vector<int>::iterator it = intvec.begin(); it != intvec.end(); it++ )
			{
				cout << *it << ": " << messagebook.GetMessage(*it) << endl;
			}
		}

		size_t pos;
		pos = order.find(' ');
		input.push_back(order.substr(0, pos));
		order.erase(0, pos + 1);

		if ( input[0] == "add" )
		{
			pos = order.find(' ');
			input.push_back(order.substr(0, pos));
			order.erase(0, pos + 1);
			if ( isInt(input[1]) )
			{
				messagebook.AddMessage(stoi(input[1]), order);
			}
		}
		else if ( input[0] == "delete" )
		{
			if ( isInt(order) )
			{
				messagebook.DeleteMessage(stoi(order));
			}
		}
		else if ( input[0] == "print" )
		{
			if ( isInt(order) )
			{
				cout << messagebook.GetMessage(stoi(order)) << endl;
			}
		}

	}

	return 0;
}