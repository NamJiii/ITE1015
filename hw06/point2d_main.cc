#define Max_Point 10

#include "point2d.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string point_name[Max_Point];
	Point p[Max_Point];
	int point_num = 0;
	string inputs;

	string *argv = new string[10];
	string token;
	size_t pos;
	int argc = 0;
	while ( point_num < Max_Point )
	{
		getline(cin, inputs);
		if ( inputs == "quit" ) return false;

		else if ( inputs.find("set") == 0 )
		{
			argc = 0;
			inputs.erase(0, 4);

			while ( true )
			{
				pos = inputs.find(' ');
				token = inputs.substr(0, pos);

				argv[argc++] = token;

				if ( pos >= inputs.length() ) break;
				else inputs.erase(0, pos + 1);
			}
			point_name[point_num] = argv[0];
			setPoint(p[point_num], stoi(argv[1]), stoi(argv[2]));
			point_num++;
		}

		else if ( inputs.find("eval") == 0 )
		{
			argc = 0;
			inputs.erase(0, 5);
			int error = 0;
			Point p_lhs;
			Point p_rhs;

			while ( true )
			{
				pos = inputs.find(' ');
				token = inputs.substr(0, pos);

				argv[argc++] = token;

				if ( pos >= inputs.length() ) break;
				else inputs.erase(0, pos + 1);
			}

			if ( IsInt(argv[0]) )
			{
				int a = stoi(argv[0]);
				p_lhs.x_ = a;
				p_lhs.y_ = a;
			}
			else
			{
				int i=0;
				for ( i = 0; i < Max_Point; i++ )
				{
					if ( point_name[i] == argv[0] )
					{
						p_lhs = p[i];
						break;
					}
				}
				if ( i >= Max_Point )
				{
					cout << "input error" << endl;
					error = 1;
				}
			}

			if ( IsInt(argv[2]) )
			{
				int a = stoi(argv[2]);
				p_rhs.x_ = a;
				p_rhs.y_ = a;
			}

			else
			{
				int i;
				for ( i = 0; i < Max_Point; i++ )
				{
					if ( point_name[i] == argv[2] )
					{
						p_rhs = p[i];
						break;
					}
				}
				if ( i >= Max_Point )
				{
					cout << "input error" << endl;
					error = 1;
				}
			}
			if ( !error )
			{
				if ( argv[1] == "+" ) printPoint(p_lhs + p_rhs);
				else if ( argv[1] == "-" ) printPoint(p_lhs - p_rhs);
				else if ( argv[1] == "*" ) printPoint(p_lhs * p_rhs);
				else cout << "input error" << endl;
			}
		}
		else
		{
			cout << "input error" << endl;
		}

	}
	cout << "too much points" << endl;
	return false;
}