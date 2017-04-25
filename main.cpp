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
	//the total number of ropes
	int total = 0;
	std::cout << "Input the number of ropes you want to spawn " << std::endl;
	std::cin >> total;
	//Creates global variables for the window, renderer, and texture
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	SDL_Texture *texture = NULL;
	//for random number generation
	srand(time(NULL));

	SDL_Init(SDL_INIT_EVERYTHING);
	//creates the SDL_window to be the size 750x750 and centered in the screen
	window = SDL_CreateWindow("Map", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 750, 750, SDL_WINDOW_SHOWN);
	if(window == NULL)
	{
		std::cout << "window" << SDL_GetError() << std::endl;
	}//end of if statement
	//creates the SDL_Renderer rendererer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_TARGETTEXTURE);
	if(renderer == NULL)
	{
		std::cout << "renderer" << SDL_GetError() << std::endl;
	}//end of if statement
	//creates an instance of the map class called theMap
	Map theMap;
	//Calls the function .setRopes in the Map.cpp file
	bool success = theMap.setRopes(total, renderer);
	bool running = false;
	if(!success)
	{
		std::cout<<"ERROR : Map not created" << std::endl;
		running = false;
	}//end of the if statement
	else
	{
		running = true;
	}//end of the else statement
	//Creates an instance of the class player
	Player player;
	//Creates the map at which the player can move across
	player.createPlayerMap();
	//sets the location of the player to be at (0,0) on the player map
	player.setPlayerXCordinate(0);
	player.setPlayerYCordinate(0);
	//Boolean value for keyboard input to register one press
	bool keypress = false;
	bool ropeDeleted = false;
	SDL_Event event;
	//While the game continues to run
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
					player.playerMotion(&event); // Calls the playerMotion function in the Player.cpp class
					ropeDeleted = theMap.deleteRope(player.getPlayerX(), player.getPlayerY(), &event);
					if(ropeDeleted == true)
					{
						std::cout << std::endl;
						std::cout << "THE ROPE IS DELETED" << std::endl;
						std::cout << std::endl;
						ropeDeleted = false;
					}
				}//end of if statement
				break;
			case SDL_KEYUP:
				keypress = false;
				break;
			default:
				//Default case simply breaks out of the switch statement
				break;
		}//end of the switch case

		//makes window background not black
		SDL_SetRenderDrawColor(renderer, 200, 242, 242, 255);

		//resets the renderer
		SDL_RenderClear(renderer);

		//displays the ropes existing within theMap instance of the Map class using the .displayRope function in the Map.cpp file
		theMap.displayRope(renderer);

		//sets the draw color for the renderer
		SDL_SetRenderDrawColor(renderer, 100, 200, 100, 200);

		//Displays (renders) the actual player to the window
		player.renderP(renderer);

		//outputs the renderer
		SDL_RenderPresent(renderer);

		//restricts to 60fps
		SDL_Delay(1000/60);
	}//end of while loop

	//Closes out the window, renderer, and the texture
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(texture);
	SDL_Quit(); //Quits SDL

	return 0;
}
