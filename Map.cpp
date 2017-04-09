#include "Map.h"

//default constructor. default is 5x5
Map::Map()
{
	this->rows = 5;
	this->cols = 5;
}//end of Map()
Map::Map(int rows, int cols)
{
	//rope[rows][cols];
	//player[rows][cols];
	this->rows = rows;
	this->cols = cols;
}//end of Map(int rows, int cols)
Map::~Map()
{
}//end of ~Map()
SDL_Point Map::getPoint(int x, int y) // values passed in are position on grid not the game window
{
	SDL_Point point;

	point.x = (x * 125) + 50;
	point.y = (y * 125) + 50;

	return point;
}//end of getPoint(int x, int y)
bool Map::setRopes(int numRopes, SDL_Renderer* renderer)
{
	//if number of ropes is greater than the number of tiles on the map minus player, return false
	if(numRopes > (rows*cols))
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
				rope[randomy][randomx].setMidPoint(getPoint(randomy, randomx));	//sets the ropes
				angle = rand()%2;
				rope[randomy][randomx].setAngle(angle);
				rope[randomy][randomx].setTexture("/images/Rope.png", renderer);
				numRopes--;
			}//end of if statement
		}//end of while loop

		for(int y = 0; y < 5; y++)
		{
			for(int x = 0; x < 5; x++)
			{
				if(rope[y][x].getTexture() != NULL)
					std::cout << "X: " << rope[y][x].getMidPoint()->x << " Y: " << rope[y][x].getMidPoint()->y << "	";
				else
					std::cout << "		";

			}
				std::cout << std::endl;
				std::cout << std::endl;
				std::cout << std::endl;
		}
		return true;
	}//end of else statement
}//end of setRopes
void Map::displayRope(SDL_Renderer* renderer)
{
	for(int y = 0; y < rows; y++)
		for(int x = 0; x < cols; x++)
		rope[y][x].render(getPoint(x, y).x, getPoint(x, y).y, NULL, renderer, rope[y][x].getAngle(), NULL, SDL_FLIP_NONE);
}//end of displayRope(SDL_Renderer* renderer)

Rope Map::getRope(int x, int y)
{
	return rope[y][x];
}
