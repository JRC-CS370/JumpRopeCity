#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "LTexture.h"

int main(int argc, char** argv)
{
    SDL_Window *window = NULL;          
    SDL_Renderer *renderer = NULL;  
    SDL_Texture *texture = NULL;
    
    
    SDL_Init(SDL_INIT_EVERYTHING);
    
    //create window
    window = SDL_CreateWindow("Map", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    if(window == NULL)
        std::cout << "window" << SDL_GetError() << std::endl;
    
    //create renderer
    renderer = SDL_CreateRenderer(window, -1, 0);
    if(renderer == NULL)
        std::cout << "renderer" << SDL_GetError() << std::endl;
    
    //create rectangle
    SDL_Rect rect = {230, 180, 200, 10};
    
    //create texture
    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_UNKNOWN, SDL_TEXTUREACCESS_STATIC, rect.w, rect.h);
    
    //running game
    bool running = true;
    SDL_Event event;
    
    while(running)
    {
        SDL_Delay(5);         //restricts to 60fps
        
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

        SDL_SetRenderDrawColor(renderer, 242, 242, 242, 255);
        SDL_RenderClear(renderer);
        
        SDL_RenderCopyEx(   renderer, 
                            texture, 
                            NULL, 
                            &rect, 
                            35, 
                            NULL, 
                            SDL_FLIP_NONE);
        
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &rect);
        
        
        SDL_RenderPresent(renderer);
    }
    
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    
    SDL_Quit();
    
    return 0;
}