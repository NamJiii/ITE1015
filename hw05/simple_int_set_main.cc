#include <iostream>
#include <stdlib.h>
#include "simple_int_set.h"

using namespace std;

enum EOperateType
{
	Invalid = -1,

	Add,
	Sub,
	Mul,
	Print,
};
typedef enum EOperateType OperateType;

int main(void)
{
	while ( true )
	{
		string inputs;
		getline(cin, inputs);

		if ( inputs == "0" ) break;

		string *argv = new string[inputs.length()]; // more than count
		string token;
		size_t pos;
		set<int> resultset;
		int argc = 0;

		while ( true )
		{
			pos = inputs.find(' ');
			token = inputs.substr(0, pos);

			argv[argc++] = token;

			if ( pos >= inputs.length() ) break;
			else inputs.erase(0, pos + 1);
		}

		SimpleIntSet *left = new SimpleIntSet;
		SimpleIntSet *right = new SimpleIntSet;

		std::set<int> elements;
		OperateType type = Invalid;
		for ( int i = 0, bracket =0; i<argc; ++i )
		{
			string arg = argv[i];
			
			if ( arg == "{")
			{
				bracket++;
			}

			else  if ( isdigit(arg[arg.length() - 1]) )
			{
				elements.insert(atoi(arg.c_str()));
			}

			else if ( arg == "}" )
			{
				bracket++;
				if ( bracket == 2 ) left->InputSet(elements);

				else if ( bracket == 4 ) right->InputSet(elements);

				else return 0;

				elements.clear();
				if ( type == Invalid ) type = Print;
			}
			else if ( arg == "+" )
			{
				type = Add;
			}

			else if ( arg == "-" )
			{
				type = Sub;
			}
			else if ( arg == "*" )
			{
				type = Mul;
			}

		}

		switch ( type )
		{
		case Add:
			resultset = SetUnion(left->Elements(), right->Elements()); break;
		case Sub:
			resultset = SetDifference(left->Elements(), right->Elements()); break;
		case Mul:
			resultset = SetIntersection(left->Elements(), right->Elements()); break;
		default: break;
		}

		if ( type != Invalid ) print(resultset);

		delete left;
		delete right;
	}
	return 0;
}