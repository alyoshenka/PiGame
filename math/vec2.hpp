struct vec2
{
	float x;
	float y;
	
	vec2 operator+(vec2 rhs);
	vec2 operator+=(vec2 rhs);
	vec2 operator*(float rhs);
};

vec2 vec2::operator+(vec2 rhs)
{
	x += rhs.x;
	y += rhs.y;
	return *this;
}

vec2 vec2::operator+=(vec2 rhs)
{
	return *this + rhs;
}

vec2 vec2::operator*(float rhs)
{
	x *= rhs;
	y *= rhs;
	return *this;
}
