#include <iostream>
#include <string>
#include <vector>
#include "draw_shape.h"

using namespace std;

Canvas::Canvas(size_t row, size_t col)
{
	row_ = row;
	col_ = col;
}

Canvas::~Canvas()
{
}

int Canvas::AddShape(const Shape &s)
{
	int error_num = 0;
	if ( ( s.type == 0 && s.x - s.width / 2 + 1 < 0 ) || ( s.type == 0 && s.x + s.width / 2 >= int(row_) ) )
	{
		error_num = -1;
	}
	else if ( ( s.type != 0 && s.x - s.width + 1 < 0 ) || ( s.type != 0 && s.x + s.width > int(col_) ) )
	{
		error_num = -1;
	}
	else if ( ( s.type == 0 && s.y - s.height / 2 + 1 < 0 ) || ( s.type == 0 && s.y + s.height / 2 >= int(col_) ) )
	{
		error_num = -1;
	}
	else if ( s.type == 0 && ( s.width % 2 == 0 || s.height % 2 == 0 ) )
	{
		error_num = -2;
	}
	else if ( s.type == 1 && s.y - s.height + 1 < 0 )
	{
		error_num = -1;
	}
	else if ( s.type == 2 && s.y + s.height > int(col_) )
	{
		error_num = -1;
	}
	else
	{
		shapes_.push_back(s);
	}

	if ( error_num == -1 ) cout << "error out of canvas" << endl;
	else if ( error_num == -2 ) cout << "error invalid input" << endl;

	return 0;
}

void Canvas::DeleteShape(int index)
{
	if (index < shapes_.size() )
	{
		shapes_.erase(shapes_.begin() + index);
	}
}

void Canvas::Draw(ostream& os)
{
	vector<vector<string> > canvas;
	canvas.resize(col_);
	for ( unsigned int j = 0; j< col_; ++j )
	{
		for ( unsigned int i = 0; i < row_; ++i )
		{
			canvas[j].push_back(".");
		}
	}
	for ( vector<Shape>::iterator it = shapes_.begin(); it != shapes_.end(); ++it )
	{
		if ( it->type == 0 )
		{
			for ( int j = -( it->height ) / 2; j <= ( it->height ) / 2; ++j )
			{
				for ( int i = -( it->width ) / 2; i <= ( it->width ) / 2; ++i )
				{
					canvas[it->y + j][it->x + i] = it->brush;
				}
			}
		}
		if ( it->type == 1 )
		{
			for ( int j = 0; j < int(it->height); ++j )
			{
				for ( int i = -j; i <= j; ++i )
				{
					canvas[it->y - j][it->x + i] = it->brush;
				}
			}
		}
		if ( it->type == 2 )
		{

			for ( int j = 0; j< int(it->height); ++j )
			{
				for ( int i = -j; i <= j; ++i )
				{
					canvas[it->y + j][it->x + i] = it->brush;
				}
			}
		}
	}

	os << " ";
	for ( unsigned int i = 0; i< row_; ++i )
	{
		os << (i%10);
	}
	os << endl;
	for ( unsigned int j = 0; j < col_; ++j )
	{
		os << (j%10);
		for ( unsigned int i = 0; i < row_; ++i )
		{
			os << canvas[j][i];
		}
		os << endl;
	}
}

void Canvas::Dump(ostream& os)
{
	for ( unsigned int i = 0; i < shapes_.size(); ++i )
	{
		os << i << " ";
		if ( shapes_[i].type == 0 )
		{
			os << "rect ";
		}
		else if ( shapes_[i].type == 2 )
		{
			os << "tri_up ";
		}
		else if ( shapes_[i].type == 1 )
		{
			os << "tri_down ";
		}
		os << shapes_[i].x << " " << shapes_[i].y << " " << shapes_[i].width << " ";
		if ( shapes_[i].type == 0 )
		{
			os << shapes_[i].height << " ";
		}
		os << shapes_[i].brush << endl;
	}
}
