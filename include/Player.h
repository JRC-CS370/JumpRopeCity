#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
	public:

		Player();

		~Player();

		void setCompass();

		void setDirection();

		void setThrottle();

		void setSpeed();

		int getCompass();

		int getDirection();

		int getThrottle();

		int getSpeed();

	private:
		int mCompass;
		int mDirection;
		int mThrottle;
		int mSpeed;
		typedef struct mCoor
		{
			int x;
			int y;
		}mCoor;
};

#endif