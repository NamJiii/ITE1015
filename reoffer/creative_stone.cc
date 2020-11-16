#include "creative_stone.h"

using namespace std;

CreativeStone::CreativeStone()
{
}
CreativeStone::~CreativeStone()
{
}

void CreativeStone::add(string _name, string _Status)
{
	L_cards[_name] = _Status;
}

void CreativeStone::foeadd(string _name, string _Status)
{
	R_cards[_name] = _Status;
}

bool CreativeStone::attack(string a_name, string e_name)
{
	map<string, string>::iterator a_it = L_cards.find(a_name);
	map<string, string>::iterator e_it = R_cards.find(e_name);
	if ( a_it == L_cards.end() || e_it == R_cards.end() )
	{
		cout << "CANNOT FIND MINION" << endl;
		return false;
	}
	else
	{
		int a_hp = stoi(getHp(a_it->second)) - stoi(getPower(e_it->second));
		int e_hp = stoi(getHp(e_it->second)) - stoi(getPower(a_it->second));
		string a_Status = intString(a_hp) + " " + getPower(a_it->second);
		string e_Status = intString(e_hp) + " " + getPower(e_it->second);
		if ( a_hp > 0 ) add(a_name, a_Status);
		else
		{
			L_cards.erase(a_it);
		}
		if ( e_hp > 0 ) foeadd(e_name, e_Status);
		else
		{
			R_cards.erase(e_it);
		}
		return true;
	}
}

void CreativeStone::burnAll(int _damage)
{
	list<map<string, string>::iterator> arr;
	for ( map<string, string>::iterator it = R_cards.begin(); it != R_cards.end(); it++ )
	{
		int e_hp = stoi(getHp(it->second)) - _damage;
		string Status = getHp(it->second) + " " + intString(e_hp);
		if ( e_hp > 0 ) foeadd(it->first, Status);
		else
		{
			arr.push_back(it);
		}
	}
	for ( list<map<string, string>::iterator>::iterator it = arr.begin(); it != arr.end(); it++ )
	{
		R_cards.erase(*it);
	}
	print();
}

bool CreativeStone::burnOne(string _name, int _damage)
{
	map<string, string>::iterator a_it = L_cards.find(_name);
	map<string, string>::iterator e_it = R_cards.find(_name);
	bool a = true, e = true;
	if ( a_it == L_cards.end() ) a = false;
	if ( e_it == R_cards.end() ) e = false;
	if ( a == false && e == false )
	{
		cout << "CANNOT FIND MINION" << endl;
		return false;
	}
	if ( a == true )
	{
		int a_hp = stoi(getHp(a_it->second)) - _damage;
		string a_Status = intString(a_hp) + " " + getPower(a_it->second);
		if ( a_hp > 0 ) add(a_it->first, a_Status);
		else
		{
			L_cards.erase(a_it);
		}
	}
	if ( e == true )
	{
		int e_hp = stoi(getHp(e_it->second)) - _damage;
		string e_Status = intString(e_hp) + " " + getPower(e_it->second);
		if ( e_hp > 0 ) foeadd(e_it->first, e_Status);
		else
		{
			R_cards.erase(e_it);
		}
	}
	return true;
}

string CreativeStone::getHp(string Status)
{
	int pos = Status.find(' ');
	string hp = Status.substr(0, pos);
	return hp;
}
string CreativeStone::getPower(string Status)
{
	int pos = Status.find(' ');
	string power = Status.substr(pos, Status.length());
	return power;
}

string CreativeStone::intString(int n)
{
	string num;
	for ( n; n % 10 != 0; n /= 10 )
	{
		num += ( n % 10 + '0' );
	}
	string number;
	for ( int i = 0; i < num.size(); i++ )
	{
		number += num[num.size() - i - 1];
	}
	return number;
}

void CreativeStone::print()
{
	map<string, string> print_map;
	list<string> a, e;
	map<string, string>::iterator a_it = L_cards.begin();
	map<string, string>::iterator e_it = R_cards.begin();
	int max, i, j;
	if ( L_cards.size() > R_cards.size() ) max = L_cards.size();
	else
	{
		max = R_cards.size();
	}
	for ( i = 0; i < max; i++ )
	{
		if ( i < L_cards.size() )
		{
			string left = string(a_it->first) + " " + string(a_it->second);
			a.push_back(left);
		}
		else
		{
			a.push_back(" ");
		}
		if ( L_cards.size() == 0 )
		{
		}
		else if ( i < L_cards.size() - 1 ) a_it++;
	}
	for ( j = 0; j < max; j++ )
	{
		if ( j < R_cards.size() )
		{
			string right = " / ";
			right += string(e_it->first) + " " + string(e_it->second);
			e.push_back(right);
		}
		else
		{
			e.push_back(" ");
		}
		if ( R_cards.size() == 0 )
		{
		}
		else if ( j < R_cards.size() - 1 ) e_it++;
	}
	list<string>::iterator a_list = a.begin();
	list<string>::iterator e_list = e.begin();
	for ( int i = 0; i < max; i++ )
	{
		print_map.insert(make_pair(*a_list, *e_list));
		if ( i < max - 1 )
		{
			a_list++;
			e_list++;
		}
	}
	for ( map<string, string>::iterator it = print_map.begin(); it != print_map.end(); it++ )
	{
		cout << it->first << it->second << endl;
	}

}