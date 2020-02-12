#pragma once

#include <wiringPi.h>

#include "inputs.hpp"

class inputManager
{
	
public:	
	inputRead button;
	
	inputManager();
	
	void init();
	void update();
	
	bool getButtonDown(inputRead button);
	bool getButtonPushed(inputRead button);
	bool getButtonUp(inputRead button);
};

inputManager::inputManager(){}

void inputManager::init()
{
	wiringPiSetup();
		
	button.setPin(6);
	pinMode(button.pin, INPUT);
}

void inputManager::update()
{
	button.update();
}


