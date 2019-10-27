// #pragma once

#include "raylib/src/raylib.h"

#include "inputManager.hpp"
#include "entity.hpp"

class game 
{
	inputManager inputs;
	entity player;
		
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
	player.init();
	
	player.speed = 50;
	
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
		player.move({1, 0});
		if(player.pos.x > screenWidth)
		{
			player.pos.x = 0;
		}
    }
    
    player.draw();
    
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
