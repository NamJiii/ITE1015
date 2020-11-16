#ifndef __CALENDAR_H__
#define __CALENDAR_H__

#include <string>
#include <iostream>

using namespace std;

class Date
{
public:
	Date(int year = 0, int month = 0, int day = 0);

	void NextDay(int n = 1);
	bool SetDate(int year, int month, int day);

	int year() const;
	int month() const;
	int day() const;

private:
	static int GetDaysInYear(int year);
	static int ComputeDaysFromYearStart(int year, int month, int day);
	int year_, month_, day_;
};

struct InvalidDateException
{
	string input_date;
	string ErrorMessage();
	InvalidDateException(const string& str) : input_date(str)
	{
	}
};


ostream& operator<<(ostream& os, const Date& c);
istream& operator>>(istream& is, Date& c);

#endif 