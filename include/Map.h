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

		//displays map
		void displayRope(SDL_Renderer* renderer);
		void displayPlayer(SDL_Renderer* renderer);

		//sets a number of ropes
		bool setRopes(int numRopes, SDL_Renderer* renderer);
		
		//get functions
		Rope* getRopeMap();
		Player* getPlayerMap();

		SDL_Point getPoint(int position);

	
	private:
		
		//rope and player 2d array
		Rope rope[25];
		Player player[25];
		
		//2d array dimensions
		int rows;
		int cols;
};

#endif
