#include "Scene.h"

//Output just explains what is going on in ther terminal for simple error finding

Scene::Scene()
{
	mSceneWidth = SCREEN_W;
	mSceneHeight = SCREEN_H;
	mSceneName = "";

	mWindow = NULL;
	mRenderer = NULL;
	mTexture = NULL;
	mSurface = NULL;
}

Scene::~Scene()
{
	SDL_DestroyWindow(mWindow);
	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyTexture(mTexture);

	mWindow = NULL;
	mRenderer = NULL;
	mTexture = NULL;
	mSurface = NULL;

}

//Creates Window, Renderer, Texture, and Surface
//Checks to make sure they are created if not returns an error
bool Scene::SceneCreation()
{
	mSceneName = "Default";

	//Window Creation
	mWindow = SDL_CreateWindow("Jump Rope City", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_W, SCREEN_H, 0);
	if(mWindow == NULL)
		std::cout << "Error in the window creation" << std::endl;

	//Renderer Creation
	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_TARGETTEXTURE);
	if(mRenderer == NULL)
		std::cout << "Error in the renderer creation" << std::endl;

	//Texture Creation
	mTexture = SDL_CreateTexture(mRenderer, SDL_PIXELFORMAT_UNKNOWN, SDL_TEXTUREACCESS_STREAMING, 200, 20);
	if(mTexture == NULL)
		std::cout << "Error in the texture creation" << std::endl;

	//Surface Creation
	mSurface = SDL_CreateRGBSurface(0, SCREEN_W, SCREEN_H, 32, 0, 0, 0, 0);
	if(mSurface != NULL)
		std::cout << "Binding to mSurface = Success" << std::endl;
}

//Get functions
SDL_Window* Scene::getWindow()
{
	return mWindow;
}

SDL_Renderer* Scene::getRenderer()
{
	return mRenderer;
}

SDL_Texture* Scene::getTexture()
{
	return mTexture;
}

SDL_Surface* Scene::getSurface()
{
	return mSurface;
}

SDL_Event* Scene::getEvent()
{
	return &event;
}

void Scene::display()
{
	//makes window background not black
	SDL_SetRenderDrawColor(mRenderer, 200, 242, 242, 255);

	//resets the renderer
	SDL_RenderClear(mRenderer);

	//displays the ropes existing within theMap instance of the Map class using the .displayRope function in the Map.cpp file
	SDL_SetRenderDrawColor(mRenderer, 100, 200, 100, 200);

	//outputs the renderer
	SDL_RenderPresent(mRenderer);

	//restricts to 60fps
	SDL_Delay(1000/60);
}
