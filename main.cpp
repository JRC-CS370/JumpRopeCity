#include <iostream>
#include <string>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <time.h>
#include <errno.h>
#include <signal.h>
#include <inttypes.h>

#include "Rope.h"
#include "Scene.h"
#include "Define.h"
#include "Player.h"
#include "miniat/miniat.h"
#include "Peripherals.h"

#define MAX_CYCLES UINT64_MAX
#include "Map.h"


miniat *m = NULL;
char *input_filename = NULL;
FILE *infile = NULL;

uint64_t cycles = 0;

static void cleanup();
static void miniat_start(int argc, char *argv[]);
static void parse_options(int argc, char *argv[]);
static void print_usage();

//Might not need this one
static void signal_handler(int sig);

/**
 * [main where miniAT starts and all of the code is called]
 * @param  argc [Number of arguments being passed in]
 * @param  argv [Arguments being passed in]
 * @return      [return nothing]
 */
int main(int argc, char *argv[])
{
	try {
		miniat_start(argc, argv);
	}
		catch(...) {
		miniat_dump_error();
	}

	return EXIT_SUCCESS;
}

/**
 * [main_start Our main chunk of code where everything happesn]
 * @param  argc [Number of arguments being passed in]
 * @param  argv [Arguments being passed in]
 * @return      [return nothing]
 */
int main_start(int argc, char **argv)
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
					ropeDeleted = theMap.deleteRope(player.getPlayerX(), player.getPlayerY(), player.getPlayerPX(), player.getPlayerPY());
					if(ropeDeleted == true)
					{
						//std::cout << std::endl;
						//std::cout << "THE ROPE IS DELETED" << std::endl;
						//std::cout << std::endl;
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
		player.setTexture(renderer);
		player.displayPlayer(renderer);

		//outputs the renderer
		SDL_RenderPresent(renderer);

		if(cycles < MAX_CYCLES)
		{
			cycles++;
		}

		miniat_clock(m);
		peripherals_clock(m, player, theMap);
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

//TODO split the miniAt functions to a seperate file
//Should be trivial

/**
 * [miniat_start Should start up miniAT, read in the file and
 * create a new instance of miniAT with the inputed binary file]
 * @param argc [number of arguments inputed]
 * @param argv [arguments inputed]
 */
static void miniat_start(int argc, char *argv[]) {

    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);

    atexit(cleanup);

    parse_options(argc, argv);

    //READS IN FILENAME FROM ARGUMENTS
    infile = fopen(input_filename, "r+b");
    if(!infile) {
        fprintf(stderr, "Couldn't open \"%s\".  %s", input_filename, strerror(errno));
        exit(EXIT_FAILURE);
    }else
    {
        std::cout << "The file was opened a-ok" << std::endl;
    }

    //SENDS BINARY FILE, CREATES INSTANCE OF MINIAT
    m = miniat_new(infile, NULL);
    std::cout << "Created a new instance of MiniAT" << std::endl;
    main_start(argc, argv);
    return;
}

/**
 * [signal_handler Honestly no idea what it does, probably deals with signals]
 * @param sig [*shrug*]
 */
static void signal_handler(int sig) {

    if(sig == SIGINT || sig == SIGTERM) {
        exit(EXIT_SUCCESS);
    }

    return;
}

/**
 * [cleanup deals with releasing memory, dealing with miniAT cleanup
 * peripherals, and ports when they are added. Nothing passed or returned]
 */
static void cleanup() {

    if(m) {
        /* MiniAT also closes the binary file it was passed on miniat_new */
        miniat_free(m);
    }

    /*
     * Call all the other cleanup functions
     */
    peripherals_cleanup();
    /*Didnt use ports explained in the above function
    *
    *ports_cleanup();
    *
    *It will be used later through*/

    if(cycles < MAX_CYCLES) {
        printf("\n%" PRIu64 " cycles executed\n", cycles);
    }
    else {
        printf("Runtime exceeded %" PRIu64 " cycles!\n", MAX_CYCLES);
    }

    return;
}

/**
 * [print_usage display command and option usage]
 */
static void print_usage() {

    fprintf(stderr, "\n");
    fprintf(stderr, "Usage:  " EXECUTABLE " [bin_file]\n");
    fprintf(stderr, "\n");

    return;
}

/**
 * [parse_options rough function that deals with the parsing of the inputed
 * binary file.]
 * @param argc [number of inputed arguments]
 * @param argv [the arguments themselves]
 */
static void parse_options(int argc, char *argv[]) {

    std::cout << "reached parse_options function" << std::endl;
    if(argc != 2) {
        print_usage();
        exit(EXIT_FAILURE);
    }

    std::cout << "read in the file name a-ok" << std::endl;

    //Reads in the file name concatinate it to EXECUTABLE from the scons script
    //This also adds a / character between the contents of EXECUTABLE and argv
    std::string tempFileName = std::string(EXECUTABLE) + "/" + std::string(argv[1]);

    //Creates a new charArray the size of the file path + 1 for saftey
    char *writable = new char[tempFileName.size() + 1];

    //Copys the contents of tempFile to the writable charArray
    std::copy(tempFileName.begin(), tempFileName.end(), writable);

    //Copys one more time from writable to input_filename which is a global variable
    input_filename = writable;
    return;
}
