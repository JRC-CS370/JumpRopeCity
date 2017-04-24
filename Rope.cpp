#include "Rope.h"
#include "Map.h"
#define PI 3.141592653
//Rope Constructor function
Rope::Rope()
{
  ropeMap.mapArray[0][0] = ropeMap.EMPTY;
}//end of the roep Constructor
//Randonly sets the ropes on the map
void Rope::setRopes()
{
  int randomAngle = rand() % 2;

  ropeMap.mapArray[2][2] = ropeMap.V_ROPE;

}//end of setRopes

void Rope::ShowRopeMap()
{
  ropeMap.DisplayMap();
}//end of Show RopeMap()
