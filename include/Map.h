#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <time.h>


#ifndef MAP_H
#define MAP_H

class Map
{
	public:
		//Constructors
		Map();
		Map(int rows, int cols);
		//Deconstructor
		~Map();

		void DisplayMap();

		int mapArray[5][5]; //2d array of integers, 0-3
		int rows; //array rows
		int cols; //array columns

		enum MapObj
		{
			EMPTY, //Set to 0
			V_ROPE,  //Set to 1
			H_ROPE,  //Set to 2
			PLAYER   //Set to 3
		};
};
#endif
