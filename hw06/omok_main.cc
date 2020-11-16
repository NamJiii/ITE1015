#include "omok.h"
#include <iostream>

using namespace std;

int main()
{
	Omok stage;
	int winner=1;
	int x, y;

	while ( !stage.IsOmok(&winner) )
	{
		if ( stage.Turn() ) cout << "White: ";
		else cout << "Black: ";
		cin >> x >> y;
		if ( !stage.Put(x, y) ) cout << "Can not be placed there." << endl;
	}

	cout << stage << "Winner: ";
	if ( winner == 1) cout << "Black player";
	else cout << "White player";

	cout << endl;
	cin >> x;
	return 0;
}