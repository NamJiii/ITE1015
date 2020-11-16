#include<iostream>
#include<string>
#include<string.h>
#include "minesweeper.h"

using namespace std;

bool SetMap(Minesweeper *_minesweeper){
	int _width, _height;
	string input;
	std::vector<string> _map;
	
	while(true){
		getline(cin,input);
		if(input.find(":set")==0){
			int space = 6;
			_width = stoi(input.substr(5,space-1));
			_height = stoi(input.substr(7,input.length()));
	
			for(int i=0;i<_height;i++){
				getline(cin,input);
				_map.push_back(input);
			}
			_minesweeper->setMap(_width,_height,_map);
			_map.clear();
		}
		else if(input.find(":toggle")==0){
			int space = 9;
			int _x = stoi(input.substr(8,space-1));
			int _y = stoi(input.substr(space+1,input.length()));
			_minesweeper->toggleMine(_x,_y);
			_map.clear();
		}
		else return false;
	}
}

int main(void){
	Minesweeper *minesweeper = new Minesweeper();
	
	while(SetMap(minesweeper)){continue;}

	delete minesweeper;
	return 0;
}

