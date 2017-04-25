#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>
#include "Player.h"
#include "Define.h"
#include "Map.h"

Player::Player()
{
	//Makes the players height and width values
	playerHeight = 120;
	playerWidth = 100;
	//Sets the point of the player to 0,0 by default
	playerX = 0;
	playerY = 0;
	//Creates the actual player rectangle
	player.x = playerMap[0][0].x;
	player.y = playerMap[0][0].y;
	player.w = playerWidth;
	player.h = playerHeight;
	//Makes the value of the playerRows and playerCols to be 5
	this->playerRows = 5;
	this->playerCols = 5;
}//end of Player function
//This function creates the renderer and displays the actual player
void Player::renderP(SDL_Renderer *renderer)
{
	SDL_RenderFillRect(renderer, &player);
}//end of renderP
//This function gets the players height
int Player::getPlayerHeight()
{
	return playerHeight;
}//end of getPlayerHeight
//This function gets the players width
int Player::getPlayerWidth()
{
	return playerWidth;
}//end of getPlayerWidth
//This function sets the players x coordinate on the playerMap 2D array
void Player::setPlayerXCordinate(int playerX)
{
	if (playerX > 4)
	{
		playerX = 4;
	}//end of if statement
	else if (playerX < 0)
	{
		playerX = 0;
	}//end of else if statement
	else
	{
		this->playerX = playerX;
		player.x = playerMap[playerY][playerX].x;
	}//end of else statement
}//end of setPlayerXCordinate
//This function sets the player y coordinate on the playerMap 2D array
void Player::setPlayerYCordinate(int playerY)
{
	if (playerY > 4)
	{
		playerY = 4;
	}//end of if statement
	else if (playerY < 0)
	{
		playerY = 0;
	}//end of else if
	else
	{
		this->playerY = playerY;
		player.y = playerMap[playerY][playerX].y;
	}//end of else
}//end of setPlayerYCordinate
//This function creates the player map
void Player::createPlayerMap()
{
		for (int y=0; y < playerRows; y++)
		{
			for (int x=0; x < playerCols; x++)
			{
				//Starts the top left corner of the playerMap at (50,50) Also spaces the x and y coordinates apart by a measure of 125
				playerMap[y][x].x = (x*125) + 50;
				playerMap[y][x].y = (y*125) + 0;
			}//end of for loop with y
		}//end of for loop with x
}//end of createPlayerMap
void Player::playerMotion(SDL_Event *event)
{
		switch(event->key.keysym.sym)
		{
			//Deals with Up motion and calls the function movePlayerUp()
			case SDLK_UP:
			movePlayerUp();
			//Testing purposes
			std::cout<<"UP "<<"("<<playerX<<","<<playerY<<")"<<"   "<<"xpos: "<<player.x<<"  "<<"ypos: "<<player.y<<std::endl;
			
			break;
			//Deals with Down motion and calls the function movePlayerDown()
			case SDLK_DOWN:
			movePlayerDown();
			//Testing purposes
			std::cout<<"DOWN "<<"("<<playerX<<","<<playerY<<")"<<"   "<<"xpos: "<<player.x<<"  "<<"ypos: "<<player.y<<std::endl;
			
			break;
			//Deals with Left motion and calls the function movePlayerLeft()
			case SDLK_LEFT:
			movePlayerLeft();
			//Testing purposes
			std::cout<<"LEFT "<<"("<<playerX<<","<<playerY<<")"<<"   "<<"xpos: "<<player.x<<"  "<<"ypos: "<<player.y<<std::endl;
			
			break;
			//Deals with Right motion and calls the function movePlayerRight()
			case SDLK_RIGHT:
			movePlayerRight();
			//Testing purposes
			std::cout<<"RIGHT "<<"("<<playerX<<","<<playerY<<")"<<"   "<<"xpos: "<<player.x<<"  "<<"ypos: "<<player.y<<std::endl;
			
			break;
			//Default case set to no value and breaks the switch statement
			default:
			break;
		}//end of switch case
}//end of Player::playerMotion function
//Function to increment player.y and calls setPlayerYCordinate
void Player::movePlayerUp()
{
	setPlayerYCordinate(playerY - 1);
}//end of movePlayerUp
//Function to increment player.y and calls setPlayerYCordinate
void Player::movePlayerDown()
{
	setPlayerYCordinate(playerY + 1);
}//end of Player::movePlayerDown
//Function to increment player.x and calls setPlayerXCordinate
void Player::movePlayerLeft()
{
	setPlayerXCordinate(playerX - 1);
}//end of Player::movePlayerLeft
//Function to increment player.x and calls setPlayerXCordinate
void Player::movePlayerRight()
{
	setPlayerXCordinate(playerX + 1);
}//end of movePlayerRight
//Function for MiniAT integration: moves the player DOWN then RIGHT
void Player::movePlayerSouthEast()
{
	setPlayerYCordinate(playerY + 1);
	setPlayerXCordinate(playerX + 1);
}//end of movePlayerSouthEast()
//Function for MiniAT integration: moves the player DOWN then LEFT
void Player::movePlayerSouthWest()
{
	setPlayerYCordinate(playerY + 1);
	setPlayerXCordinate(playerX - 1);
}//end of movePlayerSouthWest()
//Function for MiniAT integration: moves the player UP then RIGHT
void Player::movePlayerNorthEast()
{
	setPlayerYCordinate(playerY - 1);
	setPlayerXCordinate(playerX + 1);
}//end of the movePlayerNorthEast
//Function for MiniAT integration: moves the player UP then LEFT
void Player::movePlayerNorthWest()
{
	setPlayerYCordinate(playerY - 1);
	setPlayerXCordinate(playerX - 1);
}//end of the movePlayerNorthWest()

/**
 * [Player::scanNorth scans every position to the north of the player for a rope]
 * @return [true if there is a rope, false if not]
 */
bool Player::scanNorth(Map ropeMap)
{
	for(int y = playerY; y > 0; y--)
	{
		if(ropeMap.isRope(playerX, y) == true)
		{
			return true;
		}
	}
	return false;
}

/**
 * [Player::scanSouth scans every position to the south of the player for a rope]
 * @return [true if there is a rope, false if not]
 */
bool Player::scanSouth(Map ropeMap)
{
	for(int y = playerY; y < 5; y++)
	{
		if(ropeMap.isRope(playerX, y) == true)
		{
			return true;
		}
	}
	return false;
}

/**
 * [Player::scanWest scans every position to the west of the player for a rope]
 * @return [true if there is a rope, false if not]
 */
bool Player::scanWest(Map ropeMap)
{
	for(int x = playerX; x > 0; x--)
	{
		if(ropeMap.isRope(x, playerY) == true)
		{
			return true;
		}
	}
	return false;
}

/**
 * [Player::scanEast scans every position to the east of the player for a rope]
 * @return [true if there is a rope, false if not]
 */
bool Player::scanEast(Map ropeMap)
{
	for(int x = playerX; x < 5; x++)
	{
		if(ropeMap.isRope(x, playerY) == true)
		{
			return true;
		}
	}
	return false;
}

//void Player::ropeHit(Map ropeMap)
//{
//	ropeMap.free(playerY, playerX);
//}