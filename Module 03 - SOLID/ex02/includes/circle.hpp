#pragma once

#include "shape.hpp"

class Circle : public Shape
{
private:
    static const double PI;
    double radius;

public:
    Circle(double radius) : radius(radius)
    {}

    double calculateArea() const
    {
        return Circle::PI * radius * radius;
    }

    double calculatePerimeter() const
    {
        return 2 * Circle::PI * radius;
    }

    ~Circle()
    {}
};

const double Circle::PI = 3.1415;
