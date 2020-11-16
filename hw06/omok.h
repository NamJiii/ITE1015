#ifndef _OMOK_H_
#define _OMOK_H_

#define BLACK -1
#define NOBODY 0
#define WHITE 1
#define GROUND_SIZE 19

#include <iostream>
#include <vector>

class Omok
{
public:
	Omok() : width_(GROUND_SIZE), height_(GROUND_SIZE), turn_(NOBODY), ago_x(NOBODY), ago_y(NOBODY), stage_(height_ * width_, ".")
	{
	};
	~Omok()
	{
		stage_.clear();
	}

	int Put(int x, int y);
	int IsOmok(int* winner) const;
	int Turn() const
	{
		return turn_;
	}

	friend std::ostream& operator<<(std::ostream& os, const Omok& omok);

private:
	int width_, height_;
	int ago_x, ago_y;
	int turn_;
	std::vector<std::string> stage_;
};

std::ostream& operator<<(std::ostream& os, const Omok& omok);

#endif