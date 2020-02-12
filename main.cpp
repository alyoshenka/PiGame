#include "PiGameConfig.h"
#include "/usr/include/raylib/src/raylib.h"
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
