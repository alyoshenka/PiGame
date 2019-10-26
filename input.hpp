#include </usr/include/wiringPi.h>
#include <wiringPi.h>

class inputManager
{
	
public:	
	inputRead button;
	
	inputManager();
	
	void init();
	
	bool getButtonDown(input button);
	bool getButtonPushed(input button);
	bool getButtonUp(input button);
};

inputManager::inputManager(){}

void inputManager::init()
{
	wiringPiSetup();
		
	button = { 6 };
	pinMode(button.pin, INPUT);
}


