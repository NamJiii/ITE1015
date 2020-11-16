#include "calendar.h"
#include <vector>
#include <cstdlib>

const int days_of[] = { 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

Date::Date(int year, int month, int day) : year_(year), month_(month), day_(day)
{
}

void Date::NextDay(int n)
{
	day_ += n;
	if ( day_ <= 0 )
	{
		while ( day_ <= 0 )
		{
			--year_;
			day_ += GetDaysInYear(year_);
		}

		while ( day_ > days_of[month_] )
		{
			if ( month_ == 2 && GetDaysInYear(year_) == 366 )
			{
				day_ -= 29;
			}
			else
			{
				day_ -= days_of[month_];

			}

			if ( month_ == 12 )
			{
				++year_;
				month_ = 1;
			}
			else
			{
				++month_;
			}
		}
	}

	else if ( day_ > GetDaysInYear(year_) )
	{
		while ( day_ > GetDaysInYear(year_) )
		{
			++year_;
			day_ -= GetDaysInYear(year_);
		}

		while ( day_ > days_of[month_] )
		{
			if ( month_ == 2 && GetDaysInYear(year_) == 366 )
			{
				day_ -= 29;
			}
			else
			{
				day_ -= days_of[month_];

			}
			if ( month_ == 12 )
			{
				++year_;
				month_ = 1;
			}
			else
			{
				++month_;
			}
		}
	}
	else
	{
		while ( day_ > days_of[month_] )
		{
			if ( month_ == 2 && GetDaysInYear(year_) == 366 )
			{
				day_ -= 29;
			}
			else
			{
				day_ -= days_of[month_];

			}

			if ( month_ == 12 )
			{
				++year_;
				month_ = 1;
			}
			else
			{
				++month_;
			}
		}
	}
}

bool Date::SetDate(int year, int month, int day)
{
	if ( year < 0 || month <= 0 || day <= 0 || month >= 13 )
	{
		return false;
	}

	if ( GetDaysInYear(year) == 365 )
	{
		if ( day > days_of[month] )
		{
			return false;
		}
		return true;
	}

	else
	{
		if ( month == 2 && day > 29 )
		{
			return false;
		}
		else if ( month != 2 && day > days_of[month] )
		{
			return false;
		}
		return true;
	}
}

int Date::year() const
{

	return year_;
}

int Date::month() const
{
	return month_;
}

int Date::day() const
{
	return day_;
}

int Date::GetDaysInYear(int year)
{
	if ( year % 400 == 0 )
	{
		return 366;
	}
	else if ( year % 100 == 0 )
	{
		return 365;
	}
	else if ( year % 4 == 0 )
	{
		return 366;
	}
	else
	{
		return 365;
	}
	return 0;
}

int Date::ComputeDaysFromYearStart(int year, int month, int day)
{
	int _month = 12;
	int _day = day+ GetDaysInYear(year);

	while ( month<=_month )
	{
		if ( _month == 2 && GetDaysInYear(year) == 366 )
		{
			day -= 29;
		}
		else
		{
			day -= days_of[month];

		}
		_month--;
	}
	return _day;
}
ostream& operator<<(ostream& os, const Date& date)
{
	cout << date.year() << "." << date.month() << "." << date.day() << endl;
	return os;
}

istream& operator>>(istream& is, Date& c)
{
	string str;
	string inputs;
	cin >> inputs;
	str = inputs;
	size_t pos;
	vector<int> calendar_;
	while ( true )
	{
		pos = str.find(".");
		if ( pos == string::npos && str.length() > 2 )
		{
			InvalidDateException* e = new InvalidDateException(inputs);
			throw e;
		}
		calendar_.push_back(stoi(str.substr(0, pos)));
		if ( pos > str.length() )
		{
			break;
		}
		else
		{
			str.erase(0, pos + 1);
		}
	}
	if ( c.SetDate(calendar_[0], calendar_[1], calendar_[2]) )
	{
		c = Date(calendar_[0], calendar_[1], calendar_[2]);
	}
	else
	{
		InvalidDateException* e = new InvalidDateException(inputs);
		throw e;
	}
	return is;
}


string InvalidDateException::ErrorMessage()
{
	return ( "Invalid date: " + input_date );
}