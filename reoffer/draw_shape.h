#ifndef _DRAW_SHAPE__
#define _DRAW_SHAPE__
#include <vector>

using namespace std;

enum
{
	RECTANGLE, TRIANGLE_UP, TRIANGLE_DOWN
};
enum
{
	ERROR_OUT_OF_CANVAS = -1, ERROR_INVALID_INPUT = -2
};

struct Shape
{
	Shape(int type0, int x0, int y0, int height0, int width0, char brush0)
	{
		type = type0; x = x0; y = y0; width = width0; height = height0; brush = brush0;
	}
	int type;
	int x, y;
	int width, height;
	char brush;  // The character to draw the shape.
};

class Canvas
{
public:
	Canvas(size_t row, size_t col);
	~Canvas();
	int AddShape(const Shape &s);  // Return the index of the shape.
	void DeleteShape(int index);
	void Draw(ostream& os);
	void Dump(ostream& os);

private:
	size_t row_, col_;
	vector<Shape> shapes_;
};
#endif