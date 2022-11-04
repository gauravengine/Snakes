#pragma once
#include<vector>
#include "gamemap.h"
using namespace std;

class snake
{
public:
	int length;
	int score;
	vector<vector<int>> coordinates; // 2*n coordinates
	bool bittenSelf;
	int height, width;
	enum direction
	{
		STOP,
		EAST,
		WEST,
		SOUTH,
		NORTH
	};
	direction MYDIR;
	void incscore();
	void updateCoordinates(gamemap& );
	
	bool updateScore(int fx, int fy);
	snake(int,int);

};

