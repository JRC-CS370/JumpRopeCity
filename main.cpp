#include <iostream>
#include "Define.h"
#include "Scene.h"

//Output just explains what is going on in ther terminal for simple error finding

int main(int argc, char *argv[])
{
   Scene testScene;
   std::cout << "Successfully Initiated the Scene" << std::endl;

   testScene.SceneCreation();

   std::cout << "Window made" << std::endl;

   testScene.SceneDisplay();

   std::cout << "Scene Displayed" << std::endl;

    SDL_Quit();

    return 0;
}
