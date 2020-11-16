#include <iostream>
#include <string>
#include "draw_shape.h"


using namespace std;

int main()
{
	int row, col;
	cin >> col >> row;

	Canvas canvas(row, col);
	canvas.Draw(cout);

	while ( true )
	{
		string command;
		int x, y, width, height;
		char brush;

		cin >> command;

		if ( command == "add" )
		{
			cin >> command;

			if ( command == "rect" )
			{
				cin >> x >> y >> height >> width >> brush;
				Shape newRect(0, x, y, height, width, brush);
				canvas.AddShape(newRect);
			}

			else if ( command == "tri_up" )
			{
				cin >> x >> y >> height >> brush;
				Shape newTriup(2, x, y, height, height, brush);
				canvas.AddShape(newTriup);

			}

			else if ( command == "tri_down" )
			{
				cin >> x >> y >> height >> brush;
				Shape newTridown(1, x, y, height, height, brush);
				canvas.AddShape(newTridown);
			}

			else break;
		}

		else if ( command == "delete" )
		{
			int index;
			cin >> index;
			canvas.DeleteShape(index);
		}

		else if ( command == "draw" )
		{
			canvas.Draw(cout);
		}
		else if ( command == "dump" )
		{
			canvas.Dump(cout);
		}

		else
			break;
	}
}