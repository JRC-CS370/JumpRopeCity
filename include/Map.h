#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <time.h>
#include "Rope.h"

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
		void free(int y, int x);

		//displays map
		void displayRope(SDL_Renderer* renderer);
		//sets a number of ropes
		bool setRopes(int numRopes, SDL_Renderer* renderer);
		//returns a SDL_Point on the screen depending on the spot
		SDL_Point getPoint(int x, int y);

		bool isRope(int checkX, int checkY);

	private:
		//rope 2d array
		Rope rope[5][5];
		//2d array dimensions
		int rows; //array rows
		int cols; //array columns
};
#endif
