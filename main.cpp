#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <time.h>
#include "Rope.h"
#include "Scene.h"
#include "Define.h"
#include "Player.h"
#include "Map.h"

#define total 5

int main(int argc, char **argv)
{

	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	SDL_Texture *texture = NULL;

	//for random number generation
	srand(time(NULL));

	SDL_Init(SDL_INIT_EVERYTHING);

	//create window 1080x720
	window = SDL_CreateWindow("Map", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 700, 700, SDL_WINDOW_SHOWN);
	if(window == NULL)
	{
		std::cout << "window" << SDL_GetError() << std::endl;
	}//end of if statement

	//create renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_TARGETTEXTURE);
	if(renderer == NULL)
	{
		std::cout << "renderer" << SDL_GetError() << std::endl;
	}//end of if statement


	//create a map
	Map theMap;
	bool success = theMap.setRopes(10, renderer);
	if (success)
		std::cout << "YAY" << std::endl;




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


			/**************************************************************************************************************************

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

              **********************************************************************************************************************/

			default:
				break;

		}
		//makes window background not black
		SDL_SetRenderDrawColor(renderer, 242, 242, 242, 255);

		//resets the renderer
		SDL_RenderClear(renderer);

		//draws a rectangle
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

		//displays ropes to screen
		theMap.displayRope(renderer);

		//displays the player
		player.renderP(renderer);


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
