#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>
#include "Map.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
	
	public:

		/**
		 * [Player: This is the initializer for the Player Class, and sets
		 * 	all of the starting variables]
		 */
		Player();
	
		/**
		 * [setPlayerXCordinate This function is not currently in use, could
		 * 	be used later to allow the user to pick the location the person
		 * 	would start at, this is the X position]
		 * @param playerX [value of the players X position]
		 */
		void setPlayerXCordinate(int playerX);

		/**
		 * [setPlayerYCordinate This function is not currently in use, could
		 * 	be used later to allow the user to pick the location the person
		 * 	woudl start at, this is the Y position]
		 * @param playerY [value of the players Y position]
		 */
		void setPlayerYCordinate(int playerY);

		/**
		 * [ShowPlayerMap will traverse the current player array, and draw
		 * 	that to the screen. Nothing is being passed in or out]
		 */
		void ShowPlayerMap();

		/**
		 * [movePlayerNorth moves the player in the north direction one tile
		 *  at a time, thats y-1 and x stays the same]
		 */
		void movePlayerNorth();

		/**
		 * [movePlayerSouth moves the player in the south direction one tile
		 * 	at a time, thats y+1 and x stays the same]
		 */
		void movePlayerSouth();

		/**
		 * [movePlayerWest moves the player in the West direction one tile
		 * 	at a time, thats x -1 and y stays the same]
		 */
		void movePlayerWest();

		/**
		 * [movePlayerEast moves the player in the East direction one tile
		 * 	at a time, thats x + 1 and y stays the same]
		 */
		void movePlayerEast();

		/**
		 * [movePlayerSouthEast moves the player in the SouthEast direction
		 * 	one tile at a time, thats y + 1, x + 1. And it always moves horizontally
		 * 	first]
		 */
		void movePlayerSouthEast();
		
		/**
		 * [movePlayerSouthWest moves the player in the SouthWest direction
		 * 	one tile at a time, thats y + 1, x - 1. And it always moves horizontally
		 * 	first]
		 */
		void movePlayerSouthWest();

		/**
		 * [movePlayerNorthEast moves the player in the NorthEast direction
		 * 	one tile at a time, thats y - 1, x + 1. And it always moves horizontally
		 * 	first]
		 */
		void movePlayerNorthEast();

		/**
		 * [movePlayerNorthWest moves the player in the NorthWest direction
		 * 	one tile at a time, thats y - 1, x - 1. And it always moves horizontally
		 * 	first]
		 */
		void movePlayerNorthWest();

		/**
		 * [SendToRenderer This function is not yet implemented but will allow us to
		 * 	send the mapArray[][] to the renderer and have it displayed on the screen]
		 */
		void SendToRenderer();

	private:
		int playerX; //Creates the x coordinte for the player
		int playerY; //Creates the y coordinate for the player
		int playerRows; //rows for the player Map
		int playerCols; //columns for the player Map
		Map PlayerMap; //Contains all of the things needed for a map, look into Map.h for more
		
};

#endif
