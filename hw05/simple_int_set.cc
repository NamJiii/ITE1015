
#include "simple_int_set.h"

#include <iostream>
#include <set>

using namespace std;

SimpleIntSet::SimpleIntSet()
{
}

SimpleIntSet::~SimpleIntSet()
{
}

set<int> SetIntersection(const set<int>& set0, const set<int>& set1)
{
	set<int> new_set;
	for ( std::set<int>::iterator it = set0.begin(); it != set0.end(); ++it )
	{
		if ( set1.find(*it) != set1.end() ) new_set.insert(*it);
	}

	return new_set;
}

set<int> SetUnion(const set<int>& set0, const set<int>& set1)
{
	set<int> new_set;
	for ( std::set<int>::iterator it = set0.begin(); it != set0.end(); ++it )
	{
		if ( new_set.find(*it) == new_set.end() ) new_set.insert(*it);
	}

	for ( std::set<int>::iterator it = set1.begin(); it != set1.end(); ++it )
	{
		if(new_set.find(*it) == new_set.end()) new_set.insert(*it);
	}
	return new_set;
}

set<int> SetDifference(const set<int>& set0, const set<int>& set1)
{
	set<int> new_set;
	for ( std::set<int>::iterator it = set0.begin(); it != set0.end(); ++it )
	{
		if ( new_set.find(*it) == new_set.end() ) new_set.insert(*it);
	}

	for ( std::set<int>::iterator it = set1.begin(); it != set1.end(); ++it )
	{
		if ( new_set.find(*it) != new_set.end() ) new_set.erase(*it);
	}
	return new_set;
}

bool SimpleIntSet::InputSet(set<int>& s)
{
	elements_ = s;
	return true;
}

void print(set<int>& elements_)
{
	cout << "{";
	for ( set<int>::iterator it = elements_.begin(); it != elements_.end(); ++it )
	{
		cout << " " << *it;
	}
	cout << " }" << endl;
}


set<int> SimpleIntSet::Elements() const
{
	return elements_;
}