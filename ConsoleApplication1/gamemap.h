#pragma once
#include<vector>
using namespace std;
class gamemap {
public:
	int height;
	int width;
	vector<vector<char>> grid;
	bool fruitEaten;
	int fruitX, fruitY;
	void printMap(vector< vector<int> >,int ,int);
	vector<int> getFruitCoordinates();
	void setHeight(int);
	void setWidht(int);
	void fruitUpdate();
	gamemap(int, int);
};