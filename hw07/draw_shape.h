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

	// Canvas 크기를 w x h 로 변경한다. 그려진 내용은 보존한다.
	void Resize(size_t w, size_t h);

	// (x,y) 위치에 ch 문자를 그린다. 범위 밖의 x,y 는 무시한다.
	bool Draw(int x, int y, char brush);

	// 그려진 내용을 모두 지운다 ('.'으로 초기화)
	void Clear();

private:
	// 그려진 모양을 저장할 수 있도록 데이터멤버를 정의 (resize 가능에 주의)
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