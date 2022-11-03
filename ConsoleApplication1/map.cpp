#include<iostream>
#include "gamemap.h"

using namespace std;
gamemap::gamemap(int height,int width) {
	this->height = height;
	this->width = width;
	this->fruitEaten = false;
	this->fruitX = 0;
	this->fruitY = 0;
	this->grid.resize(height, vector<char>(width, ' '));
}

void gamemap::printMap(vector<vector<int> > snakeCoordinates) {
	grid[snakeCoordinates[0][0]][snakeCoordinates[1][0]] = '0';
	for (int i = 1; i < snakeCoordinates.size(); i++) {
		grid[snakeCoordinates[0][i]][snakeCoordinates[1][i]] = 'o';
	}
	grid[fruitX][fruitY] = '*';
	for (int i = 0; i <= width + 1; i++) std::cout << "#";
	for (int i = 0; i < height; i++) {
		for (int j = 0; j <= width+1; j++) {
			if (j == 0 || j == width + 1) cout << "#";
			else cout << grid[i][j - 1] ;
		}
		cout << "\n";
	}
}

vector<int> gamemap::getFruitCoordinates() {
	vector<int> ans(2);
	ans[0] = fruitX;
	ans[1] = fruitY;
	return ans;
}

void gamemap::setHeight(int h) {
	this->height = h;
}
void gamemap::setWidht(int w) {
	this->width = w;
}

void gamemap::fruitUpdate() {
	this->fruitX = rand() % (this->height);
	this->fruitY = rand() % (this->width);
	this->fruitEaten = false;
}