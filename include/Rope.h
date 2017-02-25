#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>
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

        //Gets image dimensions
        int getWidth();
        int getHeight();
        
        //gets positions on screen
        int getX();
        int getY();
        
        //gets angle
        int getAngle();
        
        //gets texture
        SDL_Texture* getTexture();
        
        //Loads image at a place
        void setTexture(std::string path, SDL_Renderer* renderer);
        
        //set position
        void setX(int newX);
        void setY(int newY);
        
        //sets angle
        void setAngle(int newAngle);

    private:
	
        //Image Texture
        SDL_Texture* mTexture;
    
        //Image dimensions
        int mWidth;             //image is 15
        int mHeight;            //image is 100
        
        //position on the map
        SDL_Point point;
        
        //angle it is
        //can be 0-180
        int angle;
        
        
};

#endif /* ROPE_H */

