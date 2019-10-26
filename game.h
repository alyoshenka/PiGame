#pragma once

#include "raylib/src/raylib.h"
#include </usr/include/wiringPi.h>
#include <wiringPi.h>

class game 
{
public:
	int screenWidth;
	int screenHeight;
	
	void init();
	void tick();
	void draw();
	void exit();
	
	bool shouldClose();
};

void game::init()
{
	screenWidth = 300;
	screenHeight = 200;
	
	wiringPiSetup();
	pinMode(1, OUTPUT);
	pinMode(6, INPUT);
	
	InitWindow(screenWidth, screenHeight, "PiGame");
}

void game::tick()
{
	
}

void game::draw()
{
	BeginDrawing();

	ClearBackground(RAYWHITE);

	DrawText("Alexi compiled raylib to pi", 20, 50, 20, LIGHTGRAY);
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

void game::exit()
{
	CloseWindow();
}

bool game::shouldClose()
{
	return WindowShouldClose();
}
