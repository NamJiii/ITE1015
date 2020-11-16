#include "omok.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;


int Omok::Put(int x, int y)
{
	if ( x >= width_ || y >= height_ )
	{
		return false;
	}

	else if ( stage_[height_ * y + x] != "." )
	{
		return false;
	}

	else
	{
		if ( Turn() )
		{
			stage_[height_ * y + x] = "x";
		}
		else
		{
			stage_[height_ * y + x] = "o";
		}
		ago_x = x;
		ago_y = y;

		turn_ = !turn_;

		return true;
	}
}

int Omok::IsOmok(int* winner) const
{
	/*Implement here*/
	string target;
	int left, right, top, bottom;

	if ( turn_ )
	{
		target = "o";
	}
	else
	{
		target = "x";
	}

	left = ( ago_x - 5 < 0 ) ? 0 : ago_x - 5;
	right = ( ago_x + 5 < width_ - 1 ) ? ago_x + 5 : width_ - 1;
	top = ( ago_y - 5 < 0 ) ? 0 : ago_y - 5;
	bottom = ( ago_y + 5 < height_ - 1 ) ? ago_y + 5 : height_ - 1;

	// omok case -
	for ( int j = top; j <= bottom; ++j )
	{
		for ( int i = left; i < right - 3; ++i )
		{
			if ( stage_[j * width_ + i] == target && stage_[j * width_ + i + 1] == target && stage_[j * width_ + i + 2] == target && stage_[j * width_ + i + 3] == target && stage_[j * width_ + i + 4] == target )
			{
				if ( i - 1 > 0 )
				{
					if ( stage_[j * width_ + i - 1] == target )
					{
						return false;
					}
				}
				else if ( i + 5 <= width_ - 1 )
				{
					if ( stage_[j * width_ + i + 5] == target )
					{
						return false;
					}
				}
				if ( !turn_ )
				{
					*winner = BLACK;
				}
				return true;
			}
		}
	}
	//omok case |
	for ( int j = top; j < bottom - 3; ++j )
	{
		for ( int i = left; i <= right; ++i )
		{
			if ( stage_[j * width_ + i] == target && stage_[( j + 1 ) * width_ + i] == target && stage_[( j + 2 ) * width_ + i] == target && stage_[( j + 3 ) * width_ + i] == target && stage_[( j + 4 ) * width_ + i] == target )
			{
				if ( j - 1 > 0 )
				{
					if ( stage_[( j - 1 ) * width_ + i] == target )
					{
						return false;
					}
				}
				else if ( j + 5 <= height_ - 1 )
				{
					if ( stage_[( j + 5 ) * width_ + i] == target )
					{
						return false;
					}
				}
				if ( !turn_ )
				{
					*winner = BLACK;
				}
				return true;
			}
		}
	}

	for ( int j = top; j < bottom - 3; ++j )
	{
		for ( int i = left; i < right - 3; ++i )
		{
			if ( stage_[j * width_ + i] == target && stage_[( j + 1 ) * width_ + i + 1] == target && stage_[( j + 2 ) * width_ + i + 2] == target && stage_[( j + 3 ) * width_ + i + 3] == target && stage_[( j + 4 ) * width_ + i + 4] == target )
			{
				if ( i - 1 > 0 && j - 1 > 0 )
				{
					if ( stage_[( j - 1 ) * 19 + i - 1] == target )
					{
						return false;
					}
				}
				if ( i + 5 <= width_ - 1 && j + 5 <= height_ - 1 )
				{
					if ( stage_[( j + 5 ) * 19 + i + 5] == target )
					{
						return false;
					}
				}
				if ( !turn_ )
				{
					*winner = BLACK;
				}
				return true;
			}
		}
	}

	for ( int j = top; j < bottom - 3; ++j )
	{
		for ( int i = left + 4; i < right; ++i )
		{
			if ( stage_[j * width_ + i] == target && stage_[( j + 1 ) * width_ + i - 1] == target && stage_[( j + 2 ) * width_ + i - 2] == target && stage_[( j + 3 ) * width_ + i - 3] == target && stage_[( j + 4 ) * width_ + i - 4] == target )
			{
				if ( i + 1 <= width_ - 1 && j - 1 > 0 )
				{
					if ( stage_[( j - 1 ) * 19 + i + 1] == target )
					{
						return false;
					}
				}
				if ( i - 5 < 0 && j + 5 <= height_ - 1 )
				{
					if ( stage_[( j + 5 ) * 19 + i - 5] == target )
					{
						return false;
					}
				}
				if ( !turn_ )
				{
					*winner = BLACK;
				}
				return true;
			}
		}
	}
	return 0;

}

ostream& operator<<(std::ostream& os, const Omok& omok)
{
	for ( int j = 0; j < omok.width_; ++j )
	{
		for ( int i = 0; i < omok.height_; ++i )
		{
			os << omok.stage_[j * omok.width_ + i] << " ";
		}
		os << endl;
	}
	return os;

}