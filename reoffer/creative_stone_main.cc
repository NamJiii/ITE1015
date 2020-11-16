#include "creative_stone.h"

using namespace std;

int main(void)
{
	CreativeStone *cs = new CreativeStone();
	while ( true )
	{
		string order;
		getline(cin, order);
		string token;
		string *argv = new string[10];
		size_t pos;
		int argc = 0;

		if ( order.find(":quit") == 0 ) return 0;
		else if ( order.find(":add") == 0 )
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
			string name = argv[0];
			string hp = argv[1];
			string power = argv[2];
			string Status = hp + " " + power;
			cs->add(name, Status);
			cs->print();
		}

		else if ( order.find(":foeadd") == 0 )
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
			string name = argv[0];
			string hp = argv[1];
			string power = argv[2];
			string Status = hp + " " + power;
			cs->foeadd(name, Status);
			cs->print();
		}

		else if ( order.find(":attack") == 0 )
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

			string name1 = argv[0];
			string name2 = argv[1];

			if ( cs->attack(name1, name2) ) cs->print();
		}
		else if ( order.find(":burn") == 0 )
		{
			argc = 0;
			order.erase(0, 6);
			while ( true )
			{
				pos = order.find(' ');
				token = order.substr(0, pos);

				argv[argc++] = token;

				if ( pos >= order.length() ) break;
				else order.erase(0, pos + 1);
			}

			if ( argc>1 )
			{
				string name = argv[0];
				int damage = stoi(argv[1]);
				if ( cs->burnOne(name, damage)) cs->print();
			}
			else
			{
				int damage = stoi(argv[0]);
				cs->burnAll(damage);
			}
		}
	}
	return 0;
}