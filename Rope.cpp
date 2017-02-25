#include "Rope.h"

Rope::Rope()
{
    //Initialize
    mTexture = NULL;
    mWidth = 15;
    mHeight = 100;
    
    point.x = 0;
    point.y = 0;
    
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
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
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

int Rope::getX()
{
    return point.x;
}

int Rope::getY()
{
    return point.y;
}

int Rope::getAngle()
{
    return angle;
}

void Rope::setX(int newX)
{
    point.x = newX;
}

void Rope::setY(int newY)
{
    point.y = newY;
}

void Rope::setAngle(int newAngle)
{
    angle = newAngle;
}

SDL_Texture* Rope::getTexture()
{
    return mTexture;
}
