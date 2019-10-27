#include "math/vec2.hpp"
#include "raylib/src/raylib.h"

struct entity
{
public:	
	vec2 pos;
	float radius;
	
	float speed;
	
	void init();
	void draw();
	
	void move(vec2 delta);
};

void entity::init()
{
	pos = { 150.0f, 100.0f };
	radius = 20;
	
	speed = 20;
}

void entity::draw()
{
	DrawCircle(pos.x, pos.y, radius, PURPLE);
}

void entity::move(vec2 delta)
{
	pos += delta * speed * GetFrameTime();
}
