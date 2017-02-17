#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "LTexture.h"

int main(int argc, char** argv)
{
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Texture* texture = NULL;
    
    SDL_Init(SDL_INIT_EVERYTHING);
    
    window = SDL_CreateWindow("Map", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    LTexture rectangle;
    rectangle.setWidth(200);
    rectangle.setHeight(5);
    
    SDL_Rect drawingRect;
    drawingRect.x = 200
    drawingRect.y = 200;
    drawingRect.w = 20;
    drawingRect.h = 20;
    
    bool running = true;
    SDL_Event event;
    
    while(running)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
                running = false;
            
        }
        render( 200, 200, &drawingRect, renderer, 0.0, SDL_Point* NULL, SDL_FLIP_NONE );
    
        SDL_UpdateWindowSurface(window);
        SDL_Delay(1000/60);
    }
    
    SDL_DestroyWindow(window);
    
    window = NULL;
    
    SDL_Quit();
    
    return 0;
}