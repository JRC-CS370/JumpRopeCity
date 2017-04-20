#include "Player.h"

Player::Player()
{
	PlayerMap.mapArray[0][0] = PlayerMap.PLAYER;
	playerX = 0;
	playerY = 0;
}

void Player::ShowPlayerMap()
{
	PlayerMap.DisplayMap();
}

/*
This starts the movement functions for player, If youd like to learn more
Look into the Player.h file for descriptions of the functions.
 */

void Player::movePlayerNorth()
{
	PlayerMap.mapArray[playerY - 1][playerX] = PlayerMap.PLAYER;
	PlayerMap.mapArray[playerY][playerX] = PlayerMap.EMPTY;
	playerY--;
}

void Player::movePlayerNorthEast()
{

}

void Player::movePlayerEast()
{

}

void Player::movePlayerSouthEast()
{

}

void Player::movePlayerSouth()
{
	PlayerMap.mapArray[playerY + 1][playerX] = PlayerMap.PLAYER;
	PlayerMap.mapArray[playerY][playerX] = PlayerMap.EMPTY;
	playerY++;
}

void Player::movePlayerSouthWest()
{

}

void Player::movePlayerWest()
{

}

void Player::movePlayerNorthWest()
{

}

void Player::SendToRenderer()
{
	//This is where we would send the PlayerMap.mapArray to the
	//Renderer in the Scene file
}