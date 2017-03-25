#include "Map.h"

//default constructor. default is 5x5
Map::Map()
{
	this->rows = 5;
	this->cols = 5;
	
	rope[rows][cols];
	player[rows][cols];
}


Map::Map(int rows, int cols)
{
	rope[rows][cols];
	player[rows][cols];
	this->rows = rows;
	this->cols = cols;
}

Map::~Map()
{
}

SDL_Point Map::getPoint(int x, int y)
{
	SDL_Point point;

	point.x = (x * 125) + 50;
	point.y = (y * 125) + 50;

	return point;
}


bool Map::setRopes(int numRopes, SDL_Renderer* renderer)
{
	//if number of ropes is greater than the number of tiles on the map minus player, return false
	if(numRopes >= (rows*cols)-1)
		return false;
	else
	{
		for(int y = 0; y < rows; y++)
			for(int x = 0; x < cols; x++)
				rope[y][x].free();

		srand(time(NULL));
		int randomx = 0;
		int randomy = 0;
		int angle = 0;

		while(numRopes > 0)
		{

			randomx = rand() % cols;
			randomy = rand() % rows;

			if(rope[randomy][randomx].getTexture() == NULL)
			{
				rope[randomy][randomx].setMidPoint(getPoint(randomy, randomx));
				angle = rand()%2;
				rope[randomy][randomx].setAngle(angle);
				rope[randomy][randomx].setTexture("/images/Rope.png", renderer);
				numRopes--;
			}
		}
		return true;
	}
}

void Map::displayRope(SDL_Renderer* renderer)
{
	for(int y = 0; y < rows; y++)
		for(int x = 0; x < cols; x++)
		rope[y][x].render(getPoint(x, y).x, getPoint(x, y).y, NULL, renderer, rope[y][x].getAngle(), NULL, SDL_FLIP_NONE);
}

/*void Map::displayPlayer(SDL_Renderer* renderer)
{
	for(int i = 0; i < rows*cols; i++)
		player[i].render(getPoint(i).x, getPoint(i).y, NULL, renderer, player[i].getAngle(), NULL, SDL_FLIP_NONE);
}*/
