#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <math.h>
#include <iostream>
#include <cstring>
#include "Map.h"

#ifndef ROPE_H
#define ROPE_H

class Rope
{
	public:
		//Initializes variables
		Rope();
		//Set ropes function to set the ropes
		void setRopes();

	private:
		//Creates an instance of the Map for the Ropes
		Map ropeMap;
		//enum used to determine if the rope is horizontal or verticle.
		enum angle
		{
			HORIZONTAL = 1,
			VERTICLE = 2
		};//end of enum angle
};
#endif /* ROPE_H */
