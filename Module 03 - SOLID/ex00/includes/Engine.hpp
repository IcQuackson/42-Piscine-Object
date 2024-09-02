#pragma once

#include <iostream>

class Engine
{
public:
    void start()
    {
        std::cout << "Starting the engine" << std::endl;
    }

    void stop()
    {
        std::cout << "Stopping the engine" << std::endl;
    }

    void accelerate(int speed)
    {
        std::cout << "Increasing the speed by " << speed << " km/h" << std::endl;
    }
};