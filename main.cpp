#include "PiGameConfig.h"
#include "raylib/src/raylib.h"
#include </usr/include/wiringPi.h>
#include <wiringPi.h>
#include <iostream>
 
int main ()
{ 
  wiringPiSetup();
  pinMode(1, OUTPUT);
  pinMode(6, INPUT);
  InitWindow(300, 200, "PiGame");
  int top = 100;
  int cnt = 0;
  int inc = 1;
  while(!WindowShouldClose())
  {
    cnt += inc;
    // if(cnt > top)
    if(digitalRead(6))
    {
      inc *= -1;
      cnt = 0;
      digitalWrite(1, HIGH);
      std::cout << "high" << std::endl; 
    }
    // if(cnt < -top)
    else
    {
      inc *= -1;
      cnt = 0;
      digitalWrite(1, LOW);
      std::cout << "low" << std::endl;
    }
    BeginDrawing();

		ClearBackground(RAYWHITE);

		DrawText("Alexi compiled raylib to pi", 20, 50, 20, LIGHTGRAY);
    // if(cnt < 0)
    if(digitalRead(6))
    {
      DrawCircle(100, 100, 20, GREEN);
    }
    else
    {
      DrawCircle(100, 100, 20, RED);
    }
    
		EndDrawing();
  }

  return 0;
}
