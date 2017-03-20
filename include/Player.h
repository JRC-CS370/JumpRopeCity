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

		//Used for Initializing variables
		Player();

		//Deallocates memory
		//virtual ~Player();

		//Renders the actual player on the window
		void renderP(SDL_Renderer *renderer);

		//Gets the location of the player
		SDL_Point* getPlayerPosition();

		//Sets the x and y positions of the player
		void setPlayerXCordinate(int playerPositionX);
		void setPlayerYCordinate(int playerPositionY);

		//This creates get functions for the players height and width
		int getPlayerHeight();
		int getPlayerWidth();



		//void keyMovement(int keyStroke);

		//void renderPlayer(SDL_Renderer *renderer);

	private:
		//contains the x and y coordinates of the player.
		SDL_Point playerPosition;
		SDL_Rect player;

		int playerHeight; //Height of the player
		int playerWidth; //Width of the player
};

#endif
