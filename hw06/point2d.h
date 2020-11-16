#ifndef __POINT2D_H_
#define __POINT2D_H_

#include<iostream>
#include<string>
using namespace std;

struct Point
{
	int x_, y_;  // ¸â¹ö º¯¼ö.

	Point()
	{
	}
	Point(const Point& p)
	{
		x_ = p.x_;
		y_ = p.y_;
	}
	explicit Point(int c)
	{
		x_ = c;
		y_ = c;
	}
	Point(int x, int y)
	{
		x_ = x;
		y_ = y;
	}
};

Point operator+(const Point& lhs, const Point& rhs);
Point operator-(const Point& lhs, const Point& rhs);
Point operator*(const Point& lhs, const Point& rhs);

bool setPoint(Point& p, int x_, int y_);
bool printPoint(const Point& p);
bool IsInt(string str);
#endif