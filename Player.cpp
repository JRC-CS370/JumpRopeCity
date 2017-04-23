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
	if(canMoveTo(playerX, playerY - 1))
	{
		PlayerMap.mapArray[playerY - 1][playerX] = PlayerMap.PLAYER;
		PlayerMap.mapArray[playerY][playerX] = PlayerMap.EMPTY;

		playerY--;
	}
	else
	{
		std::cout << "cannot move north" << std::endl;
	}

	std::cout << "X = " << playerX << " Y = " << playerY << std::endl;
}

void Player::movePlayerSouth()
{
	if(canMoveTo(playerX, playerY + 1))
	{
		PlayerMap.mapArray[playerY + 1][playerX] = PlayerMap.PLAYER;
		PlayerMap.mapArray[playerY][playerX] = PlayerMap.EMPTY;

		playerY++;
	}
	else
	{
		std::cout << "cannot move south" << std::endl;
	}

	std::cout << "X = " << playerX << " Y = " << playerY << std::endl;
}

void Player::movePlayerEast()
{
	if(canMoveTo(playerX + 1, playerY))
	{
		PlayerMap.mapArray[playerY][playerX + 1] = PlayerMap.PLAYER;
		PlayerMap.mapArray[playerY][playerX] = PlayerMap.EMPTY;

		playerX++;
	}
	else
	{
		std::cout << "cannot move east" << std::endl;
	}
	
	std::cout << "X = " << playerX << " Y = " << playerY << std::endl;
}

void Player::movePlayerWest()
{
	if(canMoveTo(playerX - 1, playerY))
	{
		PlayerMap.mapArray[playerY][playerX - 1] = PlayerMap.PLAYER;
		PlayerMap.mapArray[playerY][playerX] = PlayerMap.EMPTY;

		playerX--;
	}
	else
	{
		std::cout << "cannot move west" << std::endl;
	}

	std::cout << "X = " << playerX << " Y = " << playerY << std::endl;
}

void Player::movePlayerNorthEast()
{
	if(canMoveTo(playerX + 1, playerY - 1))
	{
		PlayerMap.mapArray[playerY - 1][playerX + 1] = PlayerMap.PLAYER;
		PlayerMap.mapArray[playerY][playerX] = PlayerMap.EMPTY;

		playerX++;
		playerY--;
	}
	else
	{
		std::cout << "cannot move north east" << std::endl;
	}

	std::cout << "X = " << playerX << " Y = " << playerY << std::endl;
}

void Player::movePlayerNorthWest()
{
	if(canMoveTo(playerX - 1, playerY - 1))
	{
		PlayerMap.mapArray[playerY - 1][playerX - 1] = PlayerMap.PLAYER;
		PlayerMap.mapArray[playerY][playerX] = PlayerMap.EMPTY;

		playerX--;
		playerY--;
	}
	else
	{
		std::cout << "cannot move north west" << std::endl;
	}

	std::cout << "X = " << playerX << " Y = " << playerY << std::endl;
}

void Player::movePlayerSouthEast()
{
	if(canMoveTo(playerX + 1, playerY + 1))
	{
		PlayerMap.mapArray[playerY + 1][playerX + 1] = PlayerMap.PLAYER;
		PlayerMap.mapArray[playerY][playerX] = PlayerMap.EMPTY;

		playerX++;
		playerY++;
	}
	else
	{
		std::cout << "cannot move south east" << std::endl;
	}

	std::cout << "X = " << playerX << " Y = " << playerY << std::endl;
}


void Player::movePlayerSouthWest()
{
	if(canMoveTo(playerX - 1, playerY + 1))
	{
		PlayerMap.mapArray[playerY + 1][playerX - 1] = PlayerMap.PLAYER;
		PlayerMap.mapArray[playerY][playerX] = PlayerMap.EMPTY;

		playerX--;
		playerY++;
	}
	else
	{
		std::cout << "cannot move south west" << std::endl;
	}

	std::cout << "X = " << playerX << " Y = " << playerY << std::endl;
}

bool Player::canMoveTo(int x, int y)
{
	std::cout << "canMoveTo params X" << x << " Y" << y << std::endl;
	return 	(x >= 0) && (x < PlayerMap.cols) && 
			(y >= 0) && (y < PlayerMap.rows);
}

void Player::addToRenderer()
{
	//implementing now
}
