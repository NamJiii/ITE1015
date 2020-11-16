#include "world_clock.h"
#include <vector>
#include <cstdlib>

void WorldClock::Tick(int n)
{
	second_ += n;
	if ( second_ <= 0 )
	{
		while ( second_ <= 0 )
		{
			--hour_;
			second_ += 3600;
		}

		while ( second_ > 59 )
		{
			++minute_;
			second_ -= 60;
		}
	}
	while ( second_ > 59 )
	{
			++minute_;
			second_ -= 60;
	}
	while ( minute_ > 59 )
	{
			++hour_;
			minute_ -= 60;
	}
	while ( hour_ > 23 )
	{
		hour_-=24;
	}
	while ( hour_ < 0 )
	{
		hour_ += 24;
	}
}

bool WorldClock::SetTime(int hour, int minute, int second)
{
	if ( hour < 0 || minute < 0 || second < 0 || minute >=60 || hour > 23 || second >= 60 )
	{
		return false;
	}
	else
	{
		hour_ = hour;
		minute_ = minute;
		second_ = second;

		return true;
	}
}

int WorldClock::hour() const
{

	return hour_;
}

int WorldClock::minute() const
{
	return minute_;
}

int WorldClock::second() const
{
	return second_;
}
ostream& operator<<(ostream& os, const WorldClock& Time)
{
	os << Time.hour() << ":" << Time.minute() << ":" << Time.second();
	return os;
}

istream& operator>>(istream& is, WorldClock& c)
{
	string str;
	string inputs;
	cin >> inputs;
	str = inputs;
	size_t pos;
	vector<int> timer_;
	while ( true )
	{
		pos = str.find(":");
		if ( pos == string::npos && str.length() > 2 )
		{
			InvalidTimeException* e = new InvalidTimeException(inputs);
			throw e;
		}
		timer_.push_back(stoi(str.substr(0, pos)));
		if ( pos > str.length() )
		{
			break;
		}
		else
		{
			str.erase(0, pos + 1);
		}
	}
	if ( c.SetTime(timer_[0], timer_[1], timer_[2]) )
	{
	}
	else
	{
		InvalidTimeException e(inputs);
		throw e;
	}
	return is;
}