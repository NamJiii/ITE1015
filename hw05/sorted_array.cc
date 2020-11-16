#include "sorted_array.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string inputs;
	getline(cin, inputs);

	string *argv = new string[inputs.length()];
	string token;
	size_t pos;
	int argc = 0;

	while ( true )
	{
		pos = inputs.find(' ');
		token = inputs.substr(0, pos);

		argv[argc++] = token;

		if ( pos >= inputs.length() ) break;
		else inputs.erase(0, pos + 1);
	}

	SortedArray *sortedarray = new SortedArray;

	for ( int i = 0; i < argc; ++i )
	{
		sortedarray->AddNumber(stoi(argv[i]));
	}
	inputs = "";
	pos = 0;
	token = "";
	argc = 0;

	while ( true )
	{
		getline(cin, inputs);

		if ( inputs == "quit" )
		{
			return 0;
		}

		else if ( inputs == "ascend" )
		{
			sortedarray->GetSortedAscending();
			cout << endl;
		}

		else if ( inputs == "descend" )
		{
			sortedarray->GetSortedDescending();
			cout << endl;
		}

		else if ( inputs == "max" )
		{
			sortedarray->GetMax();
			cout << endl;
		}

		else if ( inputs == "min" )
		{
			sortedarray->GetMin();
			cout << endl;
		}
		
		else
		{
			while ( true )
			{
				pos = inputs.find(' ');
				token = inputs.substr(0, pos);

				argv[argc++] = token;

				if ( pos >= inputs.length() ) break;
				else inputs.erase(0, pos + 1);
			}

			for ( int i = 0; i < argc; ++i )
			{
				sortedarray->AddNumber(stoi(argv[i]));
			}
			inputs = "";
			pos = 0;
			token = "";
			argc = 0;
		}
	}
}