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
#include "miniat/miniat.h"
#include "Peripherals.h"

#define MAX_CYCLES UINT64_MAX

#define total 25

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
        ropes[i].setTexture("/images/Rope.png", renderer);

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
        for(int i = 0; i < total; i++)
            ropes[i].render(ropes[i].getMidPoint()->x, ropes[i].getMidPoint()->y, NULL, renderer, ropes[i].getAngle(), NULL, SDL_FLIP_NONE);

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
    }

    //SENDS BINARY FILE, CREATES INSTANCE OF MINIAT
    m = miniat_new(infile, NULL);

    //FOREVER
    for(;;) {
        //CLOCK CYCLE
        if(cycles < MAX_CYCLES) {
            cycles++;
        }

        miniat_clock(m);
        peripherals_clock(m);
        //We don't currently have any ports only peripherals
        //ports_clock(m);
    }

    return;
}


static void signal_handler(int sig) {

    if(sig == SIGINT || sig == SIGTERM) {
        exit(EXIT_SUCCESS);
    }

    return;
}

static void cleanup() {

    if(m) {
        /* MiniAT also closes the binary file it was passed on miniat_new */
        miniat_free(m);
    }

    /*
     * Call all the other cleanup functions
     */
    peripherals_cleanup();
    //Didnt use ports explained in the above function
    //ports_cleanup();

    if(cycles < MAX_CYCLES) {
        printf("\n%"PRIu64" cycles executed\n", cycles);
    }
    else {
        printf("Runtime exceeded %"PRIu64" cycles!\n", MAX_CYCLES);
    }

    return;
}


/*
 * print_usage()
 *
 * Display command and option usage
 */
static void print_usage() {

    fprintf(stderr, "\n");
    //fprintf(stderr, "Usage:  ",EXECUTABLE," [bin_file]\n");
    fprintf(stderr, "\n");

    return;
}


static void parse_options(int argc, char *argv[]) {

    if(argc != 2) {
        print_usage();
        exit(EXIT_FAILURE);
    }

    input_filename = argv[1];

    return;
}
