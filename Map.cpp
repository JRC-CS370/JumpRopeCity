#include "Map.h"

//default constructor. default is 5x5
Map::Map()
{
	this->rows = 5;
	this->cols = 5;
}


Map::Map(int rows, int cols)
{
	rope[rows * cols];
	player[rows * cols];
	this->rows = rows;
	this->cols = cols;
}

Map::~Map()
{
}

Rope* Map::getRopeMap()
{
	return rope;
}

Player* Map::getPlayerMap()
{
	return player;
}

SDL_Point Map::getPoint(int position)
{
	int newx = position % cols;
	int newy = position / rows;
	SDL_Point point;

	point.x = (newx * 125) + 50;
	point.y = (newy * 125) + 50;

	return point;
}


bool Map::setRopes(int numRopes, SDL_Renderer* renderer)
{

	//if number of ropes is greater than the number of tiles on the map minus player, return false
	if(numRopes >= (rows*cols)-1)
		return false;
	else
	{

		for(int i = 0; i < rows*cols; i++)
			rope[i].free();

		srand(time(NULL));
		int randomspot = 0;
		int angle = 0;

		while(numRopes > 0)
		{
			randomspot = rand() % (rows*cols);
			if(rope[randomspot].getTexture() == NULL)
			{
				rope[randomspot].setMidPointX(getPoint(randomspot).x);
				rope[randomspot].setMidPointY(getPoint(randomspot).y);
				angle = rand()%2;
				rope[randomspot].setAngle(angle);
				rope[randomspot].setTexture("/images/Rope.png", renderer);
				numRopes--;
			}
		}
		return true;
	}
}

void Map::displayRope(SDL_Renderer* renderer)
{
	for(int i = 0; i < rows*cols; i++)
		rope[i].render(getPoint(i).x, getPoint(i).y, NULL, renderer, rope[i].getAngle(), NULL, SDL_FLIP_NONE);
}

/*void Map::displayPlayer(SDL_Renderer* renderer)
{
	for(int i = 0; i < rows*cols; i++)
		player[i].render(getPoint(i).x, getPoint(i).y, NULL, renderer, player[i].getAngle(), NULL, SDL_FLIP_NONE);
}*/
