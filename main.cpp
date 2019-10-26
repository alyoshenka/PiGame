#include "PiGameConfig.h"
#include "raylib/src/raylib.h"
#include </usr/include/wiringPi.h>
#include <wiringPi.h>
#include <iostream>

#include "game.hpp"
 
int main ()
{ 
  game app;
  app.init();
  
  while(!app.shouldClose())
  {
    app.tick();
    
    app.draw();
  }
  
  app.exit();

  return 0;
}
