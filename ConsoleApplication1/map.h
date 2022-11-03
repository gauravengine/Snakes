#pragma once
#include<vector>
using namespace std;
class map {
public:
	int height;
	int width;
	vector<vector<int>> grid;
	bool fruitEaten;
	int fruitX, fruitY;
	void printMap(vector< vector<int> > snakeCoordinates,);
	vector<int> getFruitCoordinates();
	void setHeight();
	void setWidht();
	void fruitUpdate();
};