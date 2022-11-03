#pragma once
#include<vector>
using namespace std;

class snake
{
public:
	int length;
	int score;
	vector<vector<int>> coordinates; // 2*n coordinates
	bool bittenSelf;
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
	void updateCoordinates();
	bool updateScore(int fx, int fy);


};

