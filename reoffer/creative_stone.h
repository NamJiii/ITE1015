#ifndef __CREATIVE_STONE_H__
#define __CREATIVE_STONE_H__

#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <map>
#include <list>


using namespace std;

class CreativeStone
{
private:
	map<string, string> L_cards, R_cards;

public:
	CreativeStone();
	~CreativeStone();

	string intString(int n);
	string getHp(string Status);
	string getPower(string Status);

	void add(string _name, string _Status);
	void foeadd(string _name, string _Status);
	bool attack(string _L_monster, string _R_monster);
	void burnAll(int _damage);
	bool burnOne(string _name, int _damage);
	void print();

};

#endif