#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <time.h>
#include "Rope.h"
#include "Scene.h"
#include "Define.h"
#include "Player.h"

#define total 5

int main(int argc, char** argv)
{

    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Texture *texture = NULL;

    //for random number generation
    srand(time(NULL));

    SDL_Init(SDL_INIT_EVERYTHING);

    //create window 1080x720
    window = SDL_CreateWindow("Map", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 860, 720, SDL_WINDOW_SHOWN);
    if(window == NULL)
        std::cout << "window" << SDL_GetError() << std::endl;

    //create renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_TARGETTEXTURE);
    if(renderer == NULL)
        std::cout << "renderer" << SDL_GetError() << std::endl;

    //create an array of ropes
    Rope ropes[5][5];

    //angle of the rope
    int angle = 0;
    int xPos = 0;
    int yPos = 100;
    int makeRope = 0;

    for(int y = 0; y < total; y++)
    {
	for(int x = 0; x < total; x++)
    	{
    	    makeRope = rand() % 3;

            if(makeRope == 0)
            {
                xPos+=125;

                //Sets the x,y position of the rope
                ropes[y][x].setMidPointX(xPos);
                ropes[y][x].setMidPointY(yPos);

                //Decides the angle for the rope to be set to
                angle = rand() % 2;

                //Actually sets the rope and loads the textur
                ropes[y][x].setAngle(angle);
                ropes[y][x].setTexture("/images/Rope.png", renderer);
            }
	}
		yPos += 125;
		xPos = 0;
    }


    //running game
    bool running = true;
    SDL_Event event;

    //player rect for testing.
    //SDL_Renderer* rectRender = SDL_CreateRenderer(window, -1, SDL_RENDERER_TARGETTEXTURE);
    //SDL_Rect player = {0, 0, 30, 30};
    Player newCharacter = Player(window);

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
                        newCharacter.keyMovement(1);
                        break;
                    case SDLK_RIGHT:
                        newCharacter.keyMovement(2);
                        break;
                    case SDLK_UP:
                        newCharacter.keyMovement(3);
                        break;
                    case SDLK_DOWN:
                        newCharacter.keyMovement(4);
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
        for(int y = 0; y < total; y++)
	{
             for(int x = 0; x < total; x++)
             {
                  ropes[y][x].render(ropes[y][x].getMidPoint()->x, ropes[y][x].getMidPoint()->y, NULL, renderer, ropes[y][x].getAngle(), NULL, SDL_FLIP_NONE);
             }
        }
        //SDL_RenderFillRect(renderer, &player);
        //newCharacter.renderPlayer(renderer);

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
