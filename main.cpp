#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <time.h>
#include "Rope.h"

#define total 25

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


    for(int i = 0; i < total; i++)
    {
        xPos += rand() % 50 + 100;
        if(xPos > 900) //150 pixels off from the side
        {
            xPos = rand() % 50 + 100;
            yPos += rand() % 100 + 100;
        }

        ropes[i].setMidPointX(xPos);
        ropes[i].setMidPointY(yPos);


        angle = rand() % 180;
        ropes[i].setAngle(angle);
        ropes[i].setTexture("images/Rope.png", renderer);

    }


    //running game
    bool running = true;
    SDL_Event event;

    //player rect for testing.
    SDL_Renderer* rectRender = SDL_CreateRenderer(window, -1, SDL_RENDERER_TARGETTEXTURE);
    SDL_Rect player = {0, 0, 30, 30};


    while(running)
    {
        SDL_PollEvent(&event);
        switch (event.type)
        {
            //close window
            case SDL_QUIT:
                running = false;
                break;

            //move the player
            //unsure how to do diagonal
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_LEFT:
                        player.x--;
                        break;
                    case SDLK_RIGHT:
                        player.x++;
                        break;
                    case SDLK_UP:
                        player.y--;
                        break;
                    case SDLK_DOWN:
                        player.y++;
                        break;
                }
                break;

            default:
                break;

        }
        //makes window background not black
        SDL_SetRenderDrawColor(renderer, 242, 242, 242, 255);

        //resets the renderer
        SDL_RenderClear(renderer);

        //draws a rectangle
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        //renders ropes to screen
/*        for(int i = 0; i < total; i++)
            ropes[i].render(ropes[i].getMidPoint()->x, ropes[i].getMidPoint()->y, NULL, renderer, ropes[i].getAngle(), NULL, SDL_FLIP_NONE);
*/
        ropes[0].setAngle(0);
        ropes[0].render(ropes[0].getMidPoint()->x, ropes[0].getMidPoint()->y, NULL, renderer, ropes[0].getAngle(), NULL, SDL_FLIP_NONE);
        
        std::cout<<"midpoint1 x = " << ropes[0].getMidPoint()->x << " y= " << ropes[0].getMidPoint()->y << std::endl;
        std::cout<<"point1 x = " << ropes[0].getPointA()->x << " y= " << ropes[0].getPointA()->y << std::endl;
        
        
        ropes[1].setAngle(90);
        ropes[1].render(ropes[1].getMidPoint()->x, ropes[1].getMidPoint()->y, NULL, renderer, ropes[1].getAngle(), NULL, SDL_FLIP_NONE);
        
        std::cout<<"midpoint2 x = " << ropes[1].getMidPoint()->x << " y= " << ropes[1].getMidPoint()->y << std::endl;
        std::cout<<"point2 x = " << ropes[1].getPointA()->x << " y= " << ropes[1].getPointA()->y << std::endl;
                
        
        SDL_RenderFillRect(renderer, &player);


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
