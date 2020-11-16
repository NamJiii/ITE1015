#ifndef __DRAW_SHAPE_H__
#define __DRAW_SHAPE_H__

#include <iostream>
#include <vector>

using namespace std;
class Canvas
{
public:
	vector<vector<string> > canvas;
	Canvas(size_t row, size_t col);
	~Canvas();

	// Canvas ũ�⸦ w x h �� �����Ѵ�. �׷��� ������ �����Ѵ�.
	void Resize(size_t w, size_t h);

	// (x,y) ��ġ�� ch ���ڸ� �׸���. ���� ���� x,y �� �����Ѵ�.
	bool Draw(int x, int y, char brush);

	// �׷��� ������ ��� ����� ('.'���� �ʱ�ȭ)
	void Clear();

private:
	// �׷��� ����� ������ �� �ֵ��� �����͸���� ���� (resize ���ɿ� ����)
	size_t row_, col_;
	friend ostream& operator<<(ostream& os, const Canvas& c);
};

class Shape
{
public:
	virtual ~Shape();
	virtual void Draw(Canvas* canvas) const = 0;
	int x();
	int y();
	char brush();
	string type();
	int w();
	int h();

protected:
	int x_, y_, type_, width_, height_;
	char brush_;
};

class Rectangle : public Shape
{
	public:
		Rectangle(){type_ = 0;}
		virtual void Draw(Canvas* canvas) const;

	protected:
		friend istream& operator>>(istream& is, Rectangle& r);
};

class UpTriangle : public Shape
{
public:
	UpTriangle(){ type_ = 1; }
	virtual void Draw(Canvas* canvas) const;

protected:
	friend istream& operator>>(istream& is, UpTriangle& t);
};

class DownTriangle : public Shape
{ 
public:
	DownTriangle() { type_ = 2; }
	virtual void Draw(Canvas* canvas) const;

protected:
	friend istream& operator>>(istream& is, DownTriangle& d);
};
class Diamond : public Shape
{ 
public:
	Diamond() { type_ = 3; }
	virtual void Draw(Canvas* canvas) const;

protected:
	friend istream& operator>>(istream& is, Diamond& dm);
};

ostream& operator<<(ostream& os, const Canvas& c);
istream& operator>>(istream& is, Rectangle& r);
istream& operator>>(istream& is, UpTriangle& t);
istream& operator>>(istream& is, DownTriangle& d);
istream& operator>>(istream& is, Diamond& dm);

#endif