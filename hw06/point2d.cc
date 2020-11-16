#include <iostream>
#include "point2d.h"
using namespace std;

Point operator+(const Point& lhs, const Point& rhs)
{
	Point new_p;
	new_p.x_ = lhs.x_ + rhs.x_;
	new_p.y_ = lhs.y_ + rhs.y_;

	return new_p;
}

Point operator-(const Point& lhs, const Point& rhs)
{
	Point new_p;
	new_p.x_ = lhs.x_ - rhs.x_;
	new_p.y_ = lhs.y_ - rhs.y_;

	return new_p;
}

Point operator*(const Point& lhs, const Point& rhs)
{
	Point new_p;
	new_p.x_ = lhs.x_ * rhs.x_;
	new_p.y_ = lhs.y_ * rhs.y_;

	return new_p;
}

bool setPoint(Point& p, int x_, int y_)
{
	p.x_ = x_;
	p.y_ = y_;
	return true;
}

bool printPoint(const Point& p)
{
	cout << "(" << p.x_ << ", " << p.y_ << ")" << endl;
	return true;
}

bool IsInt(string str)
{
	string integers = "0123456789";
	int flag;
	int error = 0;
	if ( str == "" )
	{
		return false;
	}

	for ( unsigned int i = 0; i < str.length(); i++ )
	{
		flag = 0;
		for ( int j = 0; j < 10; j++ )
		{
			if ( str[i] != integers[j] )
			{
				flag++;
			}
			if ( flag>9 ) error++;
		}
	}
	if ( !error )
	{
		return true;
	}
	else
	{
		return false;
	}
}