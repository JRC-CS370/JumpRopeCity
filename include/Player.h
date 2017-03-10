#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>
#include "Define.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
	public:

		//Player creation
		Player();

		//Player Deletion
		~Player();

		//Sets the compass Variable
		void setCompass(); 

		//Sets the direction
		void setDirection();

		//Sets the throttle
		void setThrottle();

		void setSpeed();

		void setNearRope();

		void setLocation();

		int getCompass();

		int getDirection();

		int getThrottle();

		int getSpeed();

		Coordinate getLocation();

		Coordinate getNearRope();

	private:
		int mCompass; //Angle the player wants to go
		int mDirection; //Angle the player is currently facing 0-360
		int mThrottle; //Speed they would like to get to
		int mSpeed; //Speed the player is currently going
		Coordinate mLocation; //X,Y of the players current location
		Coordinate mNearRope; //X,Y of the nearest rope
		
};

#endif