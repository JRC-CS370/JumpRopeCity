#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <time.h>
#include <stdlib.h>
#include "Define.h"

int main(int argc, char** argv)
{
   
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Texture *texture = NULL;

    srand(time(NULL));

    SDL_Init(SDL_INIT_EVERYTHING);

    //create window 1080x720
    window = SDL_CreateWindow("Map", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1080, 720, SDL_WINDOW_SHOWN);
    if(window == NULL)
        std::cout << "window" << SDL_GetError() << std::endl;

    //create renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_TARGETTEXTURE);
    if(renderer == NULL)
        std::cout << "renderer" << SDL_GetError() << std::endl;

    //create texture
    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_UNKNOWN, SDL_TEXTUREACCESS_STREAMING, 200, 20);
    if(texture == NULL)
        std::cout << "texture" << SDL_GetError() << std::endl;

    //create rectangle and angles
    LTexture rectangle [20];
    double angle [20];
    int x[20];
    int y[20];


    for(int i = 0; i < 20; i++)
    {
        angle[i] = rand() % 360;
        rectangle[i].loadFromFile(renderer, "images/rope.png");

        x[i] = rand() % 1080;
        y[i] = rand() % 720;
    }

    //running game
    bool running = true;
    SDL_Event event;


    while(running)
    {
        SDL_Delay(1000/60);         //restricts to 60fps

        SDL_PollEvent(&event);
        switch (event.type)
        {
            //close window
            case SDL_QUIT:
                running = false;
                break;

            default:
                break;

        }
        //makes window background not black
        SDL_SetRenderDrawColor(renderer, 242, 242, 242, 255);

        //resets the renderer
        SDL_RenderClear(renderer);


        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

        for(int i = 0; i < 20; i++)
        {
            rectangle[i].render(x[i], y[i], NULL, renderer, angle[i], NULL, SDL_FLIP_NONE);
        }
        //outputs the renderer. basically the rectangle
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(texture);

    SDL_Quit();

    return 0;
}
