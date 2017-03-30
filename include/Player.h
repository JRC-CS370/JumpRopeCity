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
		void setPlayerXCordinate(int playerX);
		void setPlayerYCordinate(int playerY);

		//This creates get functions for the players height and width
		int getPlayerHeight();
		int getPlayerWidth();

		//Function used to create the player Map
		void createPlayerMap();

		//void displayPlayer(SDL_Renderer *renderer);

		//void keyMovement(int keyStroke);

	private:
		//contains the x and y coordinates of the player.
		//SDL_Point playerPosition;
		SDL_Rect player;

		int playerHeight; //Height of the player
		int playerWidth; //Width of the player
		int playerX; //Creates the x coordinte for the player
		int playerY; //Creates the y coordinate for the player

		int playerRows; //rows for the player Map
		int playerCols; //columns for the player Map

		SDL_Point playerMap[5][5]; //Creates 25 points that the player could be on
};

#endif
