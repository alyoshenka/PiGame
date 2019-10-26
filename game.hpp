// #pragma once

#include "raylib/src/raylib.h"

#include "inputManager.hpp"

class game 
{
	inputManager inputs;
	
public:
	game();
	
	int screenWidth;
	int screenHeight;
	
	void init();
	void tick();
	void draw();
	void exit();
	
	bool shouldClose();
};

game::game(){}

void game::init()
{
	screenWidth = 300;
	screenHeight = 200;
	
	inputs.init();
	
	InitWindow(screenWidth, screenHeight, "PiGame");
}

void game::tick()
{
	inputs.update();
}

void game::draw()
{
	BeginDrawing();

	ClearBackground(RAYWHITE);

	DrawText("Alexi compiled raylib to pi", 20, 50, 20, LIGHTGRAY);
    if(inputs.button.getPushed())
    {
		DrawCircle(100, 100, 20, GREEN);
    }
    else
    {
		DrawCircle(100, 100, 20, BLUE);
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
