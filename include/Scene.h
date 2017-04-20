#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>
#include "Define.h"

#ifndef SCENE_H
#define SCENE_H

class Scene
{
	public:

		//Initialization
		Scene();

		//Deallocation
		~Scene();

		//Creates the Window
		bool SceneCreation();

		//Get datatype functions
		SDL_Window* getWindow();
		SDL_Renderer* getRenderer();
		SDL_Texture* getTexture();
		SDL_Surface* getSurface();
		SDL_Event* getEvent();
		
		//displays
		void display();

	private:
		//Screne Peramaters
		int mSceneWidth;
		int mSceneHeight;
		std::string mSceneName;

		//SDL Stuff
		SDL_Window *mWindow;
		SDL_Renderer *mRenderer;
		SDL_Texture *mTexture;
		SDL_Surface *mSurface;
		SDL_Event event;
};

#endif
