

#ifndef __hw05__SIMPLE_INT_SET__
#define __hw05__SIMPLE_INT_SET__

#include <string>
#include <set>
using namespace std;

class SimpleIntSet
{
public:
	SimpleIntSet();
	~SimpleIntSet();
	set<int> Elements() const;
	bool InputSet(set<int>& s);


private:
	set<int> elements_;
};
set<int> SetUnion(const set<int>& set0, const set<int>& set1);
set<int> SetDifference(const set<int>& set0, const set<int>& set1);
set<int> SetIntersection(const set<int>& set0, const set<int>& set1);

void print(set<int>& elements_);

#endif