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
							std::cout<<"north"<<std::endl;
							newPlayer.movePlayerNorth(); 
							newPlayer.ShowPlayerMap();
							break;
						
						case SDLK_DOWN:
							std::cout<<"south"<<std::endl;
							newPlayer.movePlayerSouth();
							newPlayer.ShowPlayerMap();							
							break;

						case SDLK_LEFT:
							std::cout<<"west"<<std::endl;
							newPlayer.movePlayerWest();
							newPlayer.ShowPlayerMap();							
							break;
						
						case SDLK_RIGHT:
							std::cout<<"east"<<std::endl;							
							newPlayer.movePlayerEast();
							newPlayer.ShowPlayerMap();							
							break;

						case SDLK_a:
							std::cout << "north east" << std::endl;
							newPlayer.movePlayerNorthEast();
							newPlayer.ShowPlayerMap();
							break;
						case SDLK_s:
							std::cout << "north west" << std::endl;
							newPlayer.movePlayerNorthWest();
							newPlayer.ShowPlayerMap();
							break;
						case SDLK_d:
							std::cout << "south east" << std::endl;
							newPlayer.movePlayerSouthEast();
							newPlayer.ShowPlayerMap();
							break;
						case SDLK_f:
							std::cout << "south west" << std::endl;
							newPlayer.movePlayerSouthWest();
							newPlayer.ShowPlayerMap();
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
