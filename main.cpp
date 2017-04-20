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


int main(int argc, char **argv)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	Scene myScene;
	myScene.SceneCreation();

	SDL_Event event;
	bool keypress = false;
	bool running = true;
	
	Player newPlayer;
	newPlayer.ShowPlayerMap();

	while(running)
	{
		SDL_PollEvent(&event);
		switch (event.type)
		{
			//close window
			case SDL_QUIT:
				//Quits the actual program if the user presses exit
				running = false;
				break;

			case SDL_KEYDOWN:
				if(!keypress) // if the keypress is false
				{
					keypress = true;
					switch(event.key.keysym.sym)
					{
						case SDLK_UP:
							std::cout<<"up"<<std::endl;
							newPlayer.movePlayerNorth();
							newPlayer.ShowPlayerMap();
							break;
						
						case SDLK_DOWN:
							std::cout<<"down"<<std::endl;
							newPlayer.movePlayerSouth();
							newPlayer.ShowPlayerMap();							
							break;

						case SDLK_LEFT:
							std::cout<<"left"<<std::endl;
							break;
						
						case SDLK_RIGHT:
							std::cout<<"right"<<std::endl;							
							break;
						
						default:
							break;
					}
					
				}
				break;
			
			case SDL_KEYUP:
				keypress = false;
				break;

			default:
				//Default case simply breaks out of the switch statement
				break;
		}

		myScene.display();
	}

	SDL_Quit();
	
	return 0;
}