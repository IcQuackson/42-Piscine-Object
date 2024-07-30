#include "Position.hpp"

Position::Position(int x, int y, int z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Position::Position()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

int Position::getX() const
{
    return this->x;
}

int Position::getY() const
{
    return this->y;
}

int Position::getZ() const
{
    return this->z;
}

void Position::setX(int x)
{
    this->x = x;
}

void Position::setY(int y)
{
    this->y = y;
}

void Position::setZ(int z)
{
    this->z = z;
}