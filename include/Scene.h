#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

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
    void SceneCreation();

    //Displays Screen
    void SceneDisplay();



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
};

#endif
