#include "Scene.h"

Scene::Scene()
{
  mSceneWidth = 0;
  mSceneHeight = 0;
  mSceneName = 'Default';

  mWindow = NULL;
  mRenderer = NULL;
  mTexture = NULL;
}

Scene::~Scene()
{
  free();
}

Scene::SceneCreation()
{
  SDL_Init(SDL_INIT_EVERYTHING);

  //Window Creation
  mWindow = SDL_CreateWindow(mSceneName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_W, SCREEN_H);

  //Renderer Creation
  mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_TARGETTEXTURE);

  //Texture Creation
  mTexture = SDL_CreateTexture(mRenderer, SDL_PIXELFORMAT_UNKNOWN, SDL_TEXTUREACCESS_STREAMING, 200, 20);

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
