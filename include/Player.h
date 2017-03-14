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

		//Player creation
		Player(SDL_Window *window);

		//Player Deletion
		~Player();

		void keyMovement(int keyStroke);

		//void renderPlayer(SDL_Renderer *renderer);

	private:
		int x; //X coordinate for player
		int y; //Y coordinate for player

		
};

#endif