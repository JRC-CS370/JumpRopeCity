#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <math.h>
#include <iostream>
#include <cstring>

#ifndef ROPE_H
#define ROPE_H

class Rope
{
	public:
		//Initializes variables
		Rope();
		//Deallocates memory
		virtual ~Rope();
		//Deallocates texture, when rope is jumped over
		void free();
		//Renders texture at given point, can also rotate
		void render(int x, int y, SDL_Rect* rect, SDL_Renderer *renderer, double angle, SDL_Point* center, SDL_RendererFlip flip);
		//Gets the width of the rope image
		int getWidth();
		//Gets the height of the rope image
		int getHeight();
		//gets start point on screen
		SDL_Point* getMidPoint();
		//gets angle
		int getAngle();
		//gets texture
		SDL_Texture* getTexture();
		//Loads image at a place
		void setTexture(std::string path, SDL_Renderer* renderer);
		//set point a position
		void setMidPoint(SDL_Point point);
		//sets angle
		void setAngle(int newAngle);

	private:
		//Image Texture
		SDL_Texture* mTexture;
		//Image dimensions
		int mWidth;             //image is 15
		int mHeight;            //image is 100
		//position on the map
		SDL_Point midpoint;
		//angle it is
		//can be 0-180
		int angle;
};
#endif /* ROPE_H */
