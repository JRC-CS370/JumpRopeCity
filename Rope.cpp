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
    
    pointA.x = 0;
    pointA.y = 0;
    
    pointB.x = 0;
    pointB.y = 0;
    
    angle = 0;
}

Rope::~Rope()
{
    free();
}

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
    }
}

void Rope::free()
{
    //Free texture if it exists
    if( mTexture != NULL )
    {
        SDL_DestroyTexture(mTexture);
        mTexture = NULL;
        mWidth = 0;
        mHeight = 0;
    }
    
}

void Rope::render(int x, int y, SDL_Rect* rect, SDL_Renderer* renderer, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
    //Set rendering space and render to screen
    SDL_Rect renderQuad = {x, y, mWidth, mHeight};

    //Set rect rendering dimensions
    if(rect != NULL)
    {
        renderQuad.w = rect->w;
        renderQuad.h = rect->h;
    }

    //Render to screen
    SDL_RenderCopyEx(renderer, mTexture, rect, &renderQuad, angle, center, flip);
}

int Rope::getWidth()
{
    return mWidth;
}

int Rope::getHeight()
{
    return mHeight;
}

SDL_Point* Rope::getMidPoint()
{
    return &midpoint;
}

SDL_Point* Rope::getPointA()
{
    return &pointA;
}
SDL_Point* Rope::getPointB()
{
    return &pointB;
}

int Rope::getAngle()
{
    return angle;
}

SDL_Texture* Rope::getTexture()
{
    return mTexture;
}

void Rope::setMidPointX(int newX)
{
    midpoint.x = newX;
}

void Rope::setMidPointY(int newY)
{
    midpoint.y = newY;
}

void Rope::setAngle(int newAngle)
{
    if(newAngle == 0)
	angle = 0;
    else
   	angle = 90;

    setPointA(angle);
    setPointB(angle);
    
}

void Rope::setPointA(int angle)
{
    pointA.x = midpoint.x + (cos(angle * (PI/180)) * mWidth/2);
    pointA.y = midpoint.y + (sin(angle * (PI/180)) * mWidth/2);
}

void Rope::setPointB(int angle)
{
    pointB.x = midpoint.x - (cos(angle * (PI/180)) * mWidth/2);
    pointB.y = midpoint.y - (sin(angle * (PI/180)) * mWidth/2);
}
