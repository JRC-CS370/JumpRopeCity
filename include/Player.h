#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>
#include <fstream>
#include "Define.h"
#include "Map.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
	public:

		//Used for Initializing variables that exist in the Player.cpp file
		Player();
		~Player();


		//Sets the x and y positions of the player
		void setPlayerXCordinate(int playerX);
		void setPlayerYCordinate(int playerY);

		//This creates get functions for the players height and width
		int getPlayerHeight();
		int getPlayerWidth();

		//Returns location on array
		int getPlayerX();
		int getPlayerY();
		int getPlayerPX();
		int getPlayerPY();

		//Function used to create the player Map
		void createPlayerMap();

		//Function to move the player around the playerMap
		void playerMotion(SDL_Event *event);

		//Fuction that moves the player UP on the SDL_Point playerMap[5][5]
		void movePlayerUp(Map &theMap);

		//Fuction that moves the player DOWN on the SDL_Point playerMap[5][5]
		void movePlayerDown(Map &theMap);

		//Fuction that moves the player LEFT on the SDL_Point playerMap[5][5]
		void movePlayerLeft(Map &theMap);

		//Fuction that moves the player RIGHT on the SDL_Point playerMap[5][5]
		void movePlayerRight(Map &theMap);

		//Function for MiniAT integration: moves the player DOWN then RIGHT
		void movePlayerSouthEast(Map &theMap);

		//Function for MiniAT integration: moves the player DOWN then LEFT
		void movePlayerSouthWest(Map &theMap);

		//Function for MiniAT integration: moves the player UP then RIGHT
		void movePlayerNorthEast(Map &theMap);

		//Function for MiniAT integration: moves the player UP then LEFT
		void movePlayerNorthWest(Map &theMap);

		//sets playerimage
		void setTexture(SDL_Renderer *renderer);
		//displays player
		void displayPlayer(SDL_Renderer *renderer);

		bool scanSouth(Map ropeMap);
		bool scanNorth(Map ropeMap);
		bool scanWest(Map ropeMap);
		bool scanEast(Map ropeMap);
		void ropeHit(Map ropeMap);

		std::ofstream myFile;

	private:
		SDL_Rect player; //Creates a rectangle for the texture to render to
		SDL_Texture* playerTexture; //playerimage

		int direction;
		/* *******************************
		 * direction is number from 1-4
		 * 1 = down		default
		 * 2 = up
		 * 3 = right
		 * 4 = left
		 * ******************************/

		int playerHeight; //Height of the player
		int playerWidth; //Width of the player
		int playerX; //Creates the x coordinte for the player
		int playerY; //Creates the y coordinate for the player

		int playerPX; //Previous player X position before moving
		int playerPY; // Previous player Y position before moving

		int playerRows; //rows for the player Map
		int playerCols; //columns for the player Map
		SDL_Point playerMap[5][5]; //Creates 25 points that the player could be on in a 5x5 2D array
};

#endif
