
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>
#include "Player.h"
#include "Define.h"

Player::Player()
{
	//Makes the players height and width values
	playerHeight = 30;
	playerWidth = 30;
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
	this->playerX = playerX;
	player.x = playerMap[playerY][playerX].x;
}//end of setPlayerXCordinate
//This function sets the player y coordinate on the playerMap 2D array
void Player::setPlayerYCordinate(int playerY)
{
	this->playerY = playerY;
	player.y = playerMap[playerY][playerX].y;
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
				playerMap[y][x].y = (y*125) + 50;
				//for testing
				std::cout<<"x= " << playerMap[y][x].x << std::endl; //Delete this code eventually
				std::cout<<"y= " << playerMap[y][x].y << std::endl; //Delete this code eventually
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
			std::cout<<"UP" <<std::endl;
			break;
			//Deals with Down motion and calls the function movePlayerDown()
			case SDLK_DOWN:
			movePlayerDown();
			std::cout<<"DOWN"<<std::endl;
			break;
			//Deals with Left motion and calls the function movePlayerLeft()
			case SDLK_LEFT:
			movePlayerLeft();
			std::cout<<"LEFT"<<std::endl;
			break;
			//Deals with Right motion and calls the function movePlayerRight()
			case SDLK_RIGHT:
			movePlayerRight();
			std::cout<<"RIGHT"<<std::endl;
			break;
			//Default case set to no value and breaks the switch statement
			default:
			break;
		}//end of switch case
}//end of Player::playerMotion function
//Function to increment player.y and calls setPlayerYCordinate
void Player::movePlayerUp()
{
	player.y = player.y - 1;
	setPlayerYCordinate(player.y);
}//end of movePlayerUp
//Function to increment player.y and calls setPlayerYCordinate
void Player::movePlayerDown()
{
	player.y = player.y + 1;
	setPlayerYCordinate(player.y);
}//end of Player::movePlayerDown
//Function to increment player.x and calls setPlayerXCordinate
void Player::movePlayerLeft()
{
	player.x = player.x - 1;
	setPlayerXCordinate(player.x);
}//end of Player::movePlayerLeft
//Function to increment player.x and calls setPlayerXCordinate
void Player::movePlayerRight()
{
	player.x = player.x + 1;
	setPlayerXCordinate(player.x);
}//end of movePlayerRight



/*
Player::~Player()
{
	free();
}//end of ~Player
*/
