#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <time.h>
#include <stdlib.h>
#include "Rope.h"

#define total 30

int main(int argc, char** argv)
{
    SDL_Window *window = NULL;          
    SDL_Renderer *renderer = NULL;
    SDL_Texture *texture = NULL;
    
    //for random number generation
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
    
    //create an array of ropes
    Rope ropes[total];
    
    //creates points but they cannot be 200 pixels near each other
    //also makes it so that ropes cannot be over 300 pixels away from each other
    
    //angle of the rope
    int angle = 0;
    
    int xPos = 0;
    int yPos = rand() % 50 + 50;
    
    int situation = 0;
    
    for(int i = 0; i < total; i++)
    {
        xPos += rand() % 50 + 100;
        if(xPos > 930) //150 pixels off from the side
        {
            xPos = rand() % 50 + 100;
            yPos += rand() % 50 + 100;
        }
        
        ropes[i].setX(xPos);
        ropes[i].setY(yPos);
        
        /*std::cout << i << " x " << ropes[i].getX() << std::endl;
        std::cout << i << " y " << ropes[i].getY() << std::endl;*/
        
        angle = rand() % 180;
        ropes[i].setAngle(angle);
        
        ropes[i].setTexture("images/Rope.png", renderer);
        
    }
    
    //running game
    bool running = true;
    SDL_Event event;
    
    
    while(running)
    {
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
        //resets the renderer
        SDL_RenderClear(renderer);
        
        //makes window background not black
        SDL_SetRenderDrawColor(renderer, 242, 242, 242, 255);
        
        //renders ropes to screen
        for(int i = 0; i < total; i++)
            ropes[i].render(ropes[i].getX(), ropes[i].getY(), NULL, renderer, ropes[i].getAngle(), NULL, SDL_FLIP_NONE);
        
        //outputs the renderer
        SDL_RenderPresent(renderer);
        
        //restricts to 60fps
        SDL_Delay(1000/60);
    }
    
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(texture);
    
    SDL_Quit();
    
    return 0;
}
