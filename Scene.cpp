#include "Scene.h"
#include "Define.h"
#include <iostream>
#include <string>

//Output just explains what is going on in ther terminal for simple error finding

Scene::Scene()
{
  mSceneWidth = 0;
  mSceneHeight = 0;
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
}

//Creates Window, Renderer, Texture, and Surface
//Checks to make sure they are created if not returns an error
void Scene::SceneCreation()
{
  SDL_Init(SDL_INIT_EVERYTHING);

  mSceneName = "Default";
  //Window Creation
  mWindow = SDL_CreateWindow("Default", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_W, SCREEN_H, 0);

  //Renderer Creation
  mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_TARGETTEXTURE);

  //Texture Creation
  mTexture = SDL_CreateTexture(mRenderer, SDL_PIXELFORMAT_UNKNOWN, SDL_TEXTUREACCESS_STREAMING, 200, 20);

  //Surface Creation
  mSurface = SDL_CreateRGBSurface(0, SCREEN_W, SCREEN_H, 32, 0, 0, 0, 0);
  std::cout << "Binding to mSurface == Success" << std::endl;

  //Error Checking
  if(mWindow == NULL)
  {
    std::cout << "Error in the winow creation" << std::endl;
  }
  if(mRenderer == NULL)
  {
    std::cout << "Error in the renderer creation" << std::endl;
  }
  if(mTexture == NULL)
  {
    std::cout << "Error in the texture creation" << std::endl;
  }

}

//Draws the rect, and updates to the window
void Scene::SceneDisplay()
{
  SDL_FillRect (mSurface, NULL, SDL_MapRGB( mSurface->format, 255, 255, 255));
  std::cout << "Fillrect == Success" << std::endl;

  SDL_UpdateWindowSurface(mWindow);
  std::cout << "UPdate surface = Success" << std::endl;

  //Delay
  SDL_Delay(2000);
}
