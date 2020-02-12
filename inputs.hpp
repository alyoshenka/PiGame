#include <wiringPi.h>

struct inputRead
{
	int pin;
	bool isDown; // is this currently down?
	bool wasDown; // was this down on the previous update?
	
public:

	inputRead();

	void update();
	
	void setPin(int number);
	int getPin();
	
	bool getDown();
	bool getPushed();
	bool getUp();
};

inputRead::inputRead()
{
	isDown = false;
	wasDown = false;
}

void inputRead::update()
{
	wasDown = isDown;
	// isDown = digitalRead(pin);
}

void inputRead::setPin(int number)
{
	pin = number;
}

int inputRead::getPin()
{
	return pin;
}

bool inputRead::getDown()
{
	return isDown && !wasDown;
}

bool inputRead::getPushed()
{
	return isDown;
}

bool inputRead::getUp()
{
	return !isDown && wasDown;
}

