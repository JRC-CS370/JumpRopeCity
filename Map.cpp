#include "Map.h"

//default constructor. default is 5x5
Map::Map()
{
	//Fill the array with 0
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			mapArray[i][j] = NO_ROPE;
		}
	}
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

void Map::DisplayMap()
{
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			std::cout << mapArray[i][j];
		}

		std::cout << std::endl;
	}
}
