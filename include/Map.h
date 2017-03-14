#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "Rope.h"

#ifndef MAP_H
#define MAP_H

class Map
{
	Map();

	~Map();

	void setRopes(Rope ropes);

	private:
		int makeRope;
		int ropeX;
		int ropeY;
};

#endif