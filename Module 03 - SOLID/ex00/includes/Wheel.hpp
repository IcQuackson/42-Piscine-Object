#pragma once

#include <iostream>

class Wheel
{
public:
    void turn(int angle)
    {
        std::cout << "Turning the wheels by " << angle << " degrees" << std::endl;
    }

    void straighten()
    {
        std::cout << "Straightening wheels" << std::endl;
    }
};