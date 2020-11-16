#include"minesweeper.h"

Minesweeper::Minesweeper(){
}

Minesweeper::~Minesweeper(){
}

bool Minesweeper::setMap(size_t _width, size_t _height, vector<string>& _map){
	map = &_map;
	width_ =_width;
	height_ = _height;

	int array[height_][width_] = {};
	
	for(int i=0; i<_height;i++){
		for(int j=0; j<_width;j++){
			if(_map[i][j]=='*'){
				for(int k=-1;k<=1;k++){
					for(int l=-1;l<=1;l++){
						if(i+k<0||j+l<0||i+k>=_height||j+l>=_width||_map[i+k][j+l]=='*') continue;
						else array[i+k][j+l]++;
					}
				}
			}
		}
	}
	for(int i=0; i<_height;i++){
		for(int j=0; j<_width;j++){
			if(_map[i][j]=='*') cout<<"*";
			else if(_map[i][j]=='.') cout<< array[i][j];
			else return false;
		}
		cout << "\n";
	}
}

bool Minesweeper::toggleMine(int _x, int _y){
	cout<<get(_y,_x);
	if(get(_x,_y)=='*') {map[_y][_x]="."; cout<<map[_y][_x];}
	else if(get(_y,_x)=='.') {map[_y][_x]="*"; cout<<map[_y][_x];}
	else return false;
	setMap(width(),height(),*map);
}

size_t Minesweeper::width() const{
	return width_;
}

size_t Minesweeper::height() const{
	return height_;
}

char Minesweeper::get(int _x, int _y) const{
	string pos = map->at(_y);
	return pos[_x];
}
