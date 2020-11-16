#include "calendar.h"

int main()
{
	string inputs;
	Date date;
	int num;
	do
	{
		cin >> inputs;

		if ( inputs == "set" )
		{
			try
			{
				cin >> date;
			}
			catch ( InvalidDateException *e )
			{
				cout << e->ErrorMessage() << endl;
				delete e;
				continue;
			}
			cout << date;
		}
		else if ( inputs == "next_day" )
		{
			if ( date.day() == 0 )
			{
				continue;
			}
			date.NextDay();
			cout << date;
		}
		else if ( inputs == "next" )
		{
			cin >> num;
			if ( date.day() == 0 )
			{
				continue;
			}
			date.NextDay(num);
			cout << date;
		}
	}
	while ( inputs != "quit" );

	return 0;
}

