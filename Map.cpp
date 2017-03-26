#include "Map.h"

Map::Map()
{

}//end of Map::Map

Map::~Map()
{

}//end of ~Map

Map::setRopes(Rope ropes)
{
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			makeRope = rand() % 3;

			if(makeRope == 0)
			{

			}//end of if statement
		}//end of for loop with j
	}//end of for loop with i
}//end of Map::setRopes
