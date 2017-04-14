#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <time.h>
#include "Rope.h"
#include "Player.h"

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
		
		//sets a number of ropes
		bool setRopes(int numRopes, SDL_Renderer* renderer);
		
		//returns a SDL_Point on the screen depending on the spot
		SDL_Point getPoint(int x, int y);
		
		//returns a boolean determining if there's a rope
		bool isRope(int xRope, int yRope);

		//displays map
		void displayRope(SDL_Renderer* renderer);
		
	private:
		//rope 2d array
		Rope rope[5][5];
		//2d array dimensions
		int rows; //array rows
		int cols; //array columns
};
#endif
