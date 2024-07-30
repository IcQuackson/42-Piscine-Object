#pragma once

#include <iostream>

struct Vector2
{
private:
	float x;
	float y;

public:
	Vector2(float x, float y);
	float getX() const;
	float getY() const;
	void setX(float x);
	void setY(float y);
	friend std::ostream& operator<<(std::ostream& os, const Vector2& vector);
};
