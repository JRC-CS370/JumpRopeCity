
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

	//Sets the point of hte player to 0,0 by default
	playerX = 0;
	playerY = 0;

	//Creates the actual player rectangle
	player.x = playerMap[0][0].x;
	player.y = playerMap[0][0].y;
	player.w = playerWidth;
	player.h = playerHeight;

	this->playerRows = 5;
	this->playerCols = 5;

}//end of Player function

//This function creates the renderer and displays the actual player
void Player::renderP(SDL_Renderer *renderer)
{
	//SDL_SetRenderDrawColor(30, 30, 30, 200);
	SDL_RenderFillRect(renderer, &player);
}//end of renderP

/*
SDL_Point* Player::getPlayerPosition()
{
	return &playerPosition;
}//end of getPlayerPosition
*/

int Player::getPlayerHeight()
{
	return playerHeight;
}//end of getPlayerHeight

int Player::getPlayerWidth()
{
	return playerWidth;
}//end of getPlayerWidth


void Player::setPlayerXCordinate(int playerX)
{
	this->playerX = playerX;
	player.x = playerMap[playerY][playerX].x;
}//end of setPlayerXCordinate

void Player::setPlayerYCordinate(int playerY)
{
	this->playerY = playerY;
	player.y = playerMap[playerY][playerX].y;
}//end of setPlayerYCordinate

void Player::createPlayerMap()
{

		for (int y=0; y < playerRows; y++)
		{
			for (int x=0; x < playerCols; x++)
			{
				//Spaces the values of the
				playerMap[y][x].x = (x*125) + 50;
				playerMap[y][x].y = (y*125) + 50;

				std::cout<<"x= " << playerMap[y][x].x << std::endl;
				std::cout<<"y= " << playerMap[y][x].y << std::endl;

			}//end of for loop with y
		}//end of for loop with x

}//end of createPlayerMap

/*
void displayPlayer(SDL_Renderer * renderer)
{
	SDL_SetRenderDrawColor(renderer, 30, 30, 30, 200);

}
*/







/**************************************************************************************
Player::~Player()
{
	free();
}//end of ~Player



void Player::keyMovement(int keyStroke)
{
    switch(keyStroke)
    {
        case 1:
            std::cout << "Left" << std::endl;
            break;
        case 2:
            std::cout << "Right" << std::endl;
            break;
        case 3:
            std::cout << "UP" << std::endl;
            break;
        case 4:
            std::cout << "DOWN" << std::endl;
            break;
        default:
            break;
    }//end of switch
}//end of keyMovement
****************************************************************************************/
