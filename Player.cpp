
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>
#include "Player.h"
#include "Define.h"


Player::Player(SDL_Window *window)
{
	SDL_Renderer* rectRender = SDL_CreateRenderer(window, -1, SDL_RENDERER_TARGETTEXTURE);
    SDL_Rect player = {0, 0, 30, 30};
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            //Player Grid could go here
        }
    }
    
    int xCur = 2;
    int yCur = 2;
}

Player::~Player()
{

}

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
    }
}
