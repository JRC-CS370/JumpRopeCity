#include "Rope.h"
#define PI 3.141592653

Rope::Rope()
{
	//Initialize
	mTexture = NULL;
	mWidth = 100;
	mHeight = 15;

	midpoint.x = 0;
	midpoint.y = 0;

	angle = 0;
}//end of Rope()

Rope::~Rope()
{
	free();
}//end of ~Rope()

void Rope::setTexture(std::string path, SDL_Renderer* renderer)
{
	if(mTexture != NULL)
	SDL_DestroyTexture(mTexture);
	//Load image
	SDL_Surface* loadedSurface = IMG_Load((JR_HOME + path).c_str());
	if(loadedSurface == NULL)
		std::cout << "Load image error " << IMG_GetError() << std::endl;
	else
	{
		//Create texture from surface pixels
		mTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);

		if(mTexture == NULL)
			std::cout << "Could not create texture from surface " << SDL_GetError() << std::endl;

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}//end of else
}//end of setTexture(std::string path, SDL_Renderer* renderer)

void Rope::free()
{
	//Free texture if it exists
	if( mTexture != NULL )
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}//end of if statement
}//end of Void Rope::free()

void Rope::render(int x, int y, SDL_Rect* rect, SDL_Renderer* renderer, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = {x, y, mWidth, mHeight};

	//Set rect rendering dimensions
	if(rect != NULL)
	{
		renderQuad.w = rect->w;
		renderQuad.h = rect->h;
	}//end of if statement

	//Render to screen
	SDL_RenderCopyEx(renderer, mTexture, rect, &renderQuad, angle, center, flip);
}//end of render(int x, int y, SDL_Rect* rect, SDL_Renderer* renderer, double angle, SDL_Point* center, SDL_RendererFlip flip)

int Rope::getWidth()
{
	return mWidth;
}//end of getWidth()

int Rope::getHeight()
{
	return mHeight;
}//end of getHeight()

SDL_Point* Rope::getMidPoint()
{
	return &midpoint;
}//end of getMidPoint()

int Rope::getAngle()
{
	return angle;
}//end of getAngle()

SDL_Texture* Rope::getTexture()
{
	return mTexture;
}//end of getTexture()

void Rope::setMidPoint(SDL_Point point)
{
	midpoint.x = point.x;
	midpoint.y = point.y;
}//end of setMidPoint(SDL_Point point)

void Rope::setAngle(int newAngle)
{
	if(newAngle == 0)
		angle = 0;
	else
		angle = 90;
}//end of setAngle(int newAngle)
