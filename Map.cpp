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

void Map::free(int y, int x)
{
	rope[y][x].free();
}
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

				//Verticle / Horizontal
				angle = rand()%2;

				//Sets the texture based on angle
				rope[randomy][randomx].setAngle(angle);
				rope[randomy][randomx].setTexture("/images/Rope.png", renderer);

				numRopes--;
			}//end of if statement
		}//end of while loop

		//Outputs the location of ropes. formatted to simulate the actual map
		/***************************************************************************************************************
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
		*************************************************************************************************************/

		return true;
	}//end of else statement
}//end of setRopes

void Map::displayRope(SDL_Renderer* renderer)
{
	for(int y = 0; y < rows; y++)
		for(int x = 0; x < cols; x++)
			rope[y][x].render(getPoint(x, y).x, getPoint(x, y).y, NULL, renderer, rope[y][x].getAngle(), NULL, SDL_FLIP_NONE);
}//end of displayRope(SDL_Renderer* renderer)


/**
 * [Map::isRope checks to see if there is a rope at the given spot]
 * @param  checkX [X coordinate of the spot being checked]
 * @param  checkY [Y coordinate of the spot being checked]
 * @return        [Whether or not there is a rope in that spot]
 */
bool Map::isRope(int xRope, int yRope)
{

	if(rope[yRope][xRope].getTexture() == NULL)
		return false;
	else
		return true;
}

//deletes ropes
/*
* [Map::delteRope will delete the rope at the x,y coordinate given]
* @Param int x: [The players X coordinate]
* @Param int y: [The players Y coordinate]
*/
bool Map::deleteRope(int x, int y, int Px, int Py)
{
	//first test
	if(	rope[y][x].getTexture() != NULL &&			//check if there is a texture
		rope[y][x].getAngle() == 0 &&				//checks to see if horizontal rope
		((Px == x && Py > y) || 		//checks to see if player pressed up
		 (Px == x && Py < y))	)		//or player pressed down
	{
		std::cout << "up/down being called" << std::endl;
		std::cout << "rope deleted" << std::endl;

		rope[y][x].free();
		return true;
	}
	else
	{
		if(	rope[y][x].getTexture() != NULL && 		//check if there is a texture
			rope[y][x].getAngle() == 90 &&			//checks to see if vertical rope
			((Px > x && Py == y) || //checks to see if player pressed right
			 (Px < x && Py == y)))	//or player pressed down
		{
			std::cout << "left/right being called" << std::endl;
			std::cout << "rope deleted" << std::endl;

			rope[y][x].free();
			return true;
		}
		else
		{
			std::cout << "X " << x << "Y " << y << " Rope not deleted" << std::endl;
			return false;
		}
	}
}
