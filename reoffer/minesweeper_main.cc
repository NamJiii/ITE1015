#include<iostream>
#include<string>
#include<string.h>
#include "minesweeper.h"

using namespace std;

bool SetMap(Minesweeper *_minesweeper)
{
	int _width, _height;
	std::vector<string> _map;
	bool start = false;

	while ( true )
	{
		string order;
		getline(cin, order);
		string token;
		string *argv = new string[10];
		size_t pos;
		int argc = 0;

		if ( order.find(":set")==0 )
		{
			argc = 0;
			order.erase(0, 5);
			while ( true )
			{
				pos = order.find(' ');
				token = order.substr(0, pos);

				argv[argc++] = token;

				if ( pos >= order.length() ) break;
				else order.erase(0, pos + 1);
			}

			_width = stoi(argv[0]);
			_height = stoi(argv[1]);

			_minesweeper->setMap(_width, _height, _map);
			_map.clear();
		}
		else if ( order.find(":toggle")==0)
		{
			argc = 0;
			order.erase(0, 8);
			while ( true )
			{
				pos = order.find(' ');
				token = order.substr(0, pos);

				argv[argc++] = token;

				if ( pos >= order.length() ) break;
				else order.erase(0, pos + 1);
			}
			int _x = stoi(argv[0]);
			int _y = stoi(argv[1]);
			_minesweeper->toggleMine(_x, _y);
			_map.clear();
		}
		else if ( order.find(":play") == 0 )
		{
			_minesweeper->setPlay();
			start = true;
		}
		else if ( order.find(":touch")== 0 && start == true )
		{
			argc = 0;
			order.erase(0, 7);
			while ( true )
			{
				pos = order.find(' ');
				token = order.substr(0, pos);

				argv[argc++] = token;

				if ( pos >= order.length() ) break;
				else order.erase(0, pos + 1);
			}
			int x = stoi(argv[0]);
			int y = stoi(argv[1]);

			if ( _minesweeper->touchMap(x, y) == true )
			{
				cout << "DEAD (" << _minesweeper->touchCount() << ")" << endl;
			}
		}
		else return false;
	}

}

int main(void)
{
	Minesweeper *minesweeper = new Minesweeper();

	while ( SetMap(minesweeper) )
	{
		continue;
	}

	delete minesweeper;
	return 0;
}
