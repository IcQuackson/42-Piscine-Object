#pragma once

#include "shape.hpp"

class Triangle : public Shape
{
private:
    double a;
    double b;
    double c;
    
    double mySqrt(double number) const {
        double guess = number / 2.0;  // initial guess
        double epsilon = 0.00001;     // precision
    
        while ((guess * guess) - number > epsilon || (guess * guess) - number < -epsilon) {
            guess = (guess + (number / guess)) / 2.0;
        }
        return guess;
    }

public:
    Triangle(double a, double b, double c) : a(a), b(b), c(c)
    {}

    double calculateArea() const
    {
        double s = calculatePerimeter() / 2.0;  // calculate semi perimeter
        return mySqrt(s * (s - a) * (s - b) * (s - c));
    }

    double calculatePerimeter() const
    {
        return a + b + c;
    }
    
    ~Triangle()
    {}
};