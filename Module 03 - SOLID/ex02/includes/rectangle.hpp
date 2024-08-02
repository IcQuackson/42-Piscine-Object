#pragma once

#include "shape.hpp"

class Rectangle : public Shape
{
private:
    double width;
    double height;
public:
    Rectangle(double width, double height) : width(width), height(height)
    {}

    double calculateArea() const
    {
        return width * height;
    }

    double calculatePerimeter() const
    {
        return 2 * (width + height);
    }

    ~Rectangle()
    {}
};