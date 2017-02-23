#include <iostream>
#include "Define.h"

#ifndef SCENE_H
#define SCENE_H

class SCENE
{
  public:

    //Initialization
    Scene();

    //Deallocation
    ~Scene();

    //Creates the Window
    SceneCreation();



  private:
    //Screne Peramaters
    int mSceneWidth;
    int mSceneHeight;
    string mSceneName;

    //SDL Stuff
    SDL_Window *mWindow;
    SDL_Renderer *mRenderer;
    SDL_Texture *mTexture;
}
