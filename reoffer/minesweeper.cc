#include "minesweeper.h"
#define RIGHT map[_y][_x + 1]
#define LEFT map[_y][_x - 1]
#define DOWN map[_y + 1][_x] 
#define UP map[_y - 1][_x]
#define UPLEFT map[_y - 1][_x - 1]
#define UPRIGHT map[_y - 1][_x + 1]
#define DOWNLEFT map[_y + 1][_x - 1]
#define DOWNRIGHT map[_y + 1][_x + 1]

Minesweeper::Minesweeper()
{
}

Minesweeper::~Minesweeper()
{
}

bool Minesweeper::setMap(size_t _width, size_t _height, vector<string>& _map)
{
	width_ = _width;
	height_ = _height;

	map.clear();
	_map.resize(_height, "");
	map.resize(_height, "");

	for ( int i = 0; i < _height; i++ )
	{
		getline(cin, _map[i]);
		if ( _map[i].length() != _width ) return false;
		map[i] = _map[i];
		for ( int j = 0; j < _width; j++ )
		{
			map[i][j] = '0';
		}
	}

	for ( int i = 0; i<_height; i++ )
	{
		for ( int j = 0; j<_width; j++ )
		{
			if ( _map[i][j] == '*' )
			{
				for ( int k = -1; k <= 1; k++ )
				{
					for ( int l = -1; l <= 1; l++ )
					{
						if ( i + k<0 || j + l<0 || i + k >= _height || j + l >= _width || _map[i + k][j + l] == '*' ) continue;
						else map[i + k][j + l]++;
					}
				}
			}
		}
	}
	for ( int i = 0; i<_height; i++ )
	{
		for ( int j = 0; j<_width; j++ )
		{
			if ( _map[i][j] == '*' )
			{
				cout << "*";
				map[i][j] = _map[i][j];
			}
			else cout << map[i][j];
		}
		cout << endl;
	}
	ready = true;
}

bool Minesweeper::toggleMine(int _x, int _y)
{
	if ( _x < 0 || _y < 0 || _x > width() - 1 || _y > height() - 1 ) return false;
	if ( map[_y][_x] != '*' )
	{
		if ( _x < width_ - 1 && RIGHT != '*' )  RIGHT += 1;
		if ( _x > 0 && LEFT != '*' )  LEFT += 1;
		if ( _y < height_ - 1 && DOWN != '*' )  DOWN += 1;
		if ( _y > 0 && UP != '*' )  UP += 1;
		if ( _y > 0 && _x > 0 && UPLEFT != '*' )  UPLEFT += 1;
		if ( _y < height_ - 1 && _x > 0 && DOWNLEFT != '*' )  DOWNLEFT += 1;
		if ( _y > 0 && _x < width_ - 1 && UPRIGHT != '*' )  UPRIGHT += 1;
		if ( _y < height_ - 1 && _x < width_ - 1 && DOWNRIGHT != '*' )  DOWNRIGHT += 1;
		map[_y][_x] = '*';
	}
	else if ( map[_y][_x] == '*' )
	{
		if ( _x < width_ - 1 && RIGHT != '*' )  RIGHT -= 1;
		if ( _x > 0 && LEFT != '*' )  LEFT -= 1;
		if ( _y < height_ - 1 && DOWN != '*' )  DOWN -= 1;
		if ( _y > 0 && UP != '*' )  UP -= 1;
		if ( _y > 0 && _x > 0 && UPLEFT != '*' )  UPLEFT -= 1;
		if ( _y < height_ - 1 && _x > 0 && DOWNLEFT != '*' )  DOWNLEFT -= 1;
		if ( _y > 0 && _x < width_ - 1 && UPRIGHT != '*' )  UPRIGHT -= 1;
		if ( _y < height_ - 1 && _x < width_ - 1 && DOWNRIGHT != '*' )  DOWNRIGHT -= 1;

		map[_y][_x] = '0';
		for ( int k = -1; k <= 1; k++ )
		{
			for ( int l = -1; l <= 1; l++ )
			{
				if ( _y + k<0 || _x + l<0 || _y + k >= height_ || _x + l >= width_) continue;
				else if ( map[_y + k][_x + l] == '*' ) map[_y][_x]+=1;
			}
		}
	}
	for ( int i = 0; i < map.size(); i++ )
	{
		cout << map[i] << endl;
	}
	return true;
}

size_t Minesweeper::width() const
{
	return width_;
}

size_t Minesweeper::height() const
{
	return height_;
}

char Minesweeper::get(int _x, int _y) const
{
	if ( _x < 0 || _y < 0 ) return ' ';
	return map[_y][_x];
}

bool Minesweeper::setPlay()
{
	if ( ready == false ) return false;
	sweeping = map;
	for ( int i = 0; i < height_; i++ )
	{
		sweeping[i] = map[i];
		for ( int j = 0; j < width_; j++ )
		{
			sweeping[i][j] = '_';
		}
	}
	for ( int i = 0; i < map.size(); i++ )
	{
		cout << sweeping[i] << endl;
	}
	NumofPlay(0);
	return true;
}

bool Minesweeper::touchMap(int _x, int _y)
{
	if ( _x > width_ - 1 || _y > height_ - 1 ) return false;
	playtime += 1;
	if ( map[_y][_x] == '*' ) return true;
	else
	{
		sweeping[_y][_x] = map[_y][_x];
		for ( int i = 0; i < map.size(); i++ )
		{
			cout << sweeping[i] << endl;
		}
		return false;
	}
}
void Minesweeper::NumofPlay(int _playtime)
{
	playtime = _playtime;
}

int Minesweeper::touchCount() const
{
	return playtime;
}