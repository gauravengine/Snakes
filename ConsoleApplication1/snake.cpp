#include "snake.h"
#include "gamemap.h"
#include<iostream>
using namespace std;

snake::snake(int h,int w) {
	MYDIR = NORTH;
	length = 1;
	score = 0;
	coordinates.resize(2, vector<int>(405, 0));
	coordinates[0][0] = 1;
	coordinates[1][0] = 1;
	bittenSelf = false;
	this->height = h;
	this->width = w;
}
void snake::incscore() {
	this->score += 2;
}
void snake::updateCoordinates(gamemap &mymap) {
	int prevX = coordinates[0][0];
	int prevY = coordinates[1][0];
	switch (this->MYDIR) {
		case EAST:
			coordinates[1][0] -= 1; //how do you handle
			if (coordinates[1][0] == -1) coordinates[1][0] = width - 1;
			break;
		case WEST:
			coordinates[1][0] += 1; //how do you handle
			if (coordinates[1][0] == width) coordinates[1][0] = 0;
			break;
		case SOUTH:
			coordinates[0][0] += 1;
			if (coordinates[0][0] == height) coordinates[0][0] = 0;
			break;
		case NORTH:
			coordinates[0][0] -= 1;
			if (coordinates[0][0] == -1) coordinates[0][0] = height-1;
			break;
		default:
			break;
	}
	
	if (prevX == mymap.fruitX && prevY == mymap.fruitY) {
		incscore();
		this->length += 1;
		mymap.fruitUpdate();
	}
	if (prevX == coordinates[0][0] && prevY == coordinates[1][0]) this->bittenSelf = true;
	for (int i = 1; i < length; i++) {
		if (coordinates[0][i] == coordinates[0][0] && coordinates[1][i] == coordinates[1][0]) this->bittenSelf = true;
	}
	for (int i = 1; i < length; i++) {
		int tempX = coordinates[0][i];
		int tempY = coordinates[1][i];
		this->coordinates[0][i] = prevX;
		this->coordinates[1][i] = prevY;
		prevX = tempX;
		prevY = tempY;
	}
}

bool snake::updateScore(int fx, int fy) {
	if (coordinates[0][0] == fx && coordinates[1][0] == fy) {
		this->incscore();
		return true;
	}
	return false;
}