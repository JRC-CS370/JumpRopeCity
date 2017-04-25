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

		//Used for Initializing variables that exist in the Player.cpp file
		Player();

		//Renders the actual player on the window
		void renderP(SDL_Renderer *renderer);

		//Sets the x and y positions of the player
		void setPlayerXCordinate(int playerX);
		void setPlayerYCordinate(int playerY);

		//This creates get functions for the players height and width
		int getPlayerHeight();
		int getPlayerWidth();

		//Returns location on array
		int getPlayerX();
		int getPlayerY();

		//Function used to create the player Map
		void createPlayerMap();

		//Function to move the player around the playerMap
		void playerMotion(SDL_Event *event);

		//Fuction that moves the player UP on the SDL_Point playerMap[5][5]
		void movePlayerUp();

		//Fuction that moves the player DOWN on the SDL_Point playerMap[5][5]
		void movePlayerDown();

		//Fuction that moves the player LEFT on the SDL_Point playerMap[5][5]
		void movePlayerLeft();

		//Fuction that moves the player RIGHT on the SDL_Point playerMap[5][5]
		void movePlayerRight();

		//Function for MiniAT integration: moves the player DOWN then RIGHT
		void movePlayerSouthEast();

		//Function for MiniAT integration: moves the player DOWN then LEFT
		void movePlayerSouthWest();

		//Function for MiniAT integration: moves the player UP then RIGHT
		void movePlayerNorthEast();

		//Function for MiniAT integration: moves the player UP then LEFT
		void movePlayerNorthWest();

	private:
		SDL_Rect player; //Creates a rectangle to display as the actual player
		int playerHeight; //Height of the player
		int playerWidth; //Width of the player
		int playerX; //Creates the x coordinte for the player
		int playerY; //Creates the y coordinate for the player
		int playerRows; //rows for the player Map
		int playerCols; //columns for the player Map
		SDL_Point playerMap[5][5]; //Creates 25 points that the player could be on in a 5x5 2D array
};

#endif
