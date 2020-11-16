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

void Canvas::Resize(size_t w, size_t h)
{
	row_ = w;
	col_ = h;
}

bool Canvas::Draw(int x, int y, char brush)
{
	if ( x >= 0 && x < col_ && y >= 0 && y < row_ )
	{
		canvas[x][y] = brush;
	}
	return true;
}

void Canvas::Clear()
{
	vector<vector<string>> pure_canvas;
	pure_canvas.resize(col_);
	for ( int i = 0; i < col_; i++ )
	{
		for ( int j = 0; j < row_; j++ )
		{
			pure_canvas[i].push_back(".");
		}
	}
	canvas = pure_canvas;
}
ostream& operator<<(ostream& os, const Canvas& c)
{
	os << " ";
	for ( unsigned int i = 0; i< c.row_; ++i )
	{
		os << (i%10);
	}
	os << endl;
	for ( unsigned int j = 0; j < c.col_; ++j )
	{
		os << (j%10);
		for ( unsigned int i = 0; i < c.row_; ++i )
		{
			os << c.canvas[j][i];
		}
		os << endl;
	}
	return os;
}
Shape::~Shape()
{

}

void Rectangle::Draw(Canvas* canvas) const
{
	for ( int j = 0; j <= ( height_ ) -1; ++j )
	{
		for ( int i = 0; i <= width_-1; ++i )
		{
			canvas->Draw(y_ + j, x_ + i, brush_);
		}
	}
}

void DownTriangle::Draw(Canvas* canvas) const
{
	for ( int j = 0; j< height_; ++j )
	{
		for ( int i = -j; i <= j; ++i )
		{
			canvas->Draw(y_ - j, x_ + i, brush_);
		}
	}
}

void UpTriangle::Draw(Canvas* canvas) const
{
	for ( int j = 0; j < height_; ++j )
	{
		for ( int i = -j; i <= j; ++i )
		{
			canvas->Draw(y_ + j, x_ + i, brush_);
		}
	}
}

void Diamond::Draw(Canvas* canvas) const
{
	for ( int j = 0; j < height_+1; ++j )
	{
		for ( int i = -j; i <= j; ++i )
		{
			canvas->Draw(y_ + j, x_ + i, brush_);
		}
	}
	for ( int j = 0; j< height_; ++j )
	{
		for ( int i = -j; i <= j; ++i )
		{
			canvas->Draw((y_+2*height_) - j, x_ + i, brush_);
		}
	}
}

istream& operator>>(istream& is, Rectangle& r)
{
	size_t x_, y_, width_, height_;
	char brush_;
	is >> x_ >> y_ >> width_ >> height_ >> brush_;
	r.x_ = x_;
	r.y_ = y_;
	r.width_ = width_;
	r.height_ = height_;
	r.brush_ = brush_;
	return is;
}

istream& operator>>(istream& is, UpTriangle& t)
{
	size_t x_, y_, height_;
	char brush_;
	is >> x_ >> y_>> height_ >> brush_;
	t.x_ = x_;
	t.y_ = y_;
	t.height_ = height_;
	t.brush_ = brush_;
	return is;
}

istream& operator>>(istream& is, DownTriangle& d)
{
	size_t x_, y_, height_;
	char brush_;
	is >> x_ >> y_ >> height_ >> brush_;
	d.x_ = x_;
	d.y_ = y_;
	d.height_ = height_;
	d.brush_ = brush_;
	return is;
}

istream& operator>>(istream& is, Diamond& dm)
{
	size_t x_, y_, half_height_;
	char brush_;
	is >> x_ >> y_ >> half_height_ >> brush_;
	dm.x_ = x_;
	dm.y_ = y_;
	dm.height_ = half_height_;
	dm.brush_ = brush_;
	return is;
}

int Shape::x()
{
	return x_;
}
int Shape::y()
{
	return y_;
}
char Shape::brush()
{
	return brush_;
}
string Shape::type()
{
	if ( type_ == 0 ) return "rect";
	else if ( type_ == 1 ) return "tri_up";
	else if ( type_ == 2 ) return "tri_down";
	else if ( type_ == 3 ) return "diamond";
	else return "unknown";
}
int Shape::w()
{
	return width_;
}
int Shape::h()
{
	return height_;
}