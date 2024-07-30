#pragma once

struct Position
{
private:
    int x;
    int y;
    int z;

public:
    Position(int x, int y, int z);
    Position();
    int getX() const;
    int getY() const;
    int getZ() const;
    void setX(int x);
    void setY(int y);
    void setZ(int z);
};