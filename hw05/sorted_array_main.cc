#include "sorted_array.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

SortedArray::SortedArray()
{
}

SortedArray::~SortedArray()
{
}

void SortedArray::AddNumber(int num)
{
	numbers_.push_back(num);
	sort(numbers_.begin(), numbers_.end());
}

vector<int> SortedArray::GetSortedAscending() const
{
	for ( vector<int>::const_iterator it = numbers_.begin(); it != numbers_.end(); it++ )
	{
		cout << *it << " ";
	}
	return numbers_;
}

vector<int> SortedArray::GetSortedDescending() const
{
	for ( vector<int>::const_iterator it = numbers_.end(); it != numbers_.begin(); )
	{
		cout << *(--it) << " ";
	}
	return numbers_;
}

int SortedArray::GetMax() const
{
	vector<int>::const_iterator it = numbers_.end();
	it--;
	cout << *it;
	return *it;
}

int SortedArray::GetMin() const
{
	vector<int>::const_iterator it = numbers_.begin();
	cout << *it;
	return *it;
}