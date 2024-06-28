#include "Vector2.hpp"

Vector2::Vector2(float x, float y) : x(x), y(y)
{
}

float Vector2::getX() const
{
	return this->x;
}

float Vector2::getY() const
{
	return this->y;
}

void Vector2::setX(float x)
{
	this->x = x;
}

void Vector2::setY(float y)
{
	this->y = y;
}

std::ostream& operator<<(std::ostream& os, const Vector2& vector)
{
	os << "Vector2(" << vector.getX() << ", " << vector.getY() << ")";
	return os;
}