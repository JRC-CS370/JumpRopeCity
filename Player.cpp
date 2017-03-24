#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>
#include "Player.h"
#include "Define.h"

Player::Player()
{
	playerPosition.x = 100;
	playerPosition.y = 100;
	playerHeight = 30;
	playerWidth = 30;

	//Creates the actual player rectangle
	player.x = playerPosition.x;
	player.y = playerPosition.y;
	player.w = playerWidth;
	player.h = playerHeight;

}//end of Player function

//This function creates the renderer and displays the actual player
void Player::renderP(SDL_Renderer *renderer)//x and y coordinates
{
	SDL_RenderFillRect(renderer, &player);
}//end of renderP


SDL_Point* Player::getPlayerPosition()
{
	return &playerPosition;
}//end of getPlayerPosition

int Player::getPlayerHeight()
{
	return playerHeight;
}//end of getPlayerHeight

int Player::getPlayerWidth()
{
	return playerWidth;
}//end of getPlayerWidth


void Player::setPlayerXCordinate(int playerPositionX)
{
	playerPosition.x = playerPositionX;
}//end of setPlayerXCordinate

void Player::setPlayerYCordinate(int playerPositionY)
{
	playerPosition.y = playerPositionY;
}//end of setPlayerYCordinate








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