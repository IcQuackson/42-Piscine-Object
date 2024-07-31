
#pragma once

#include <iostream>

class Car
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

    void shift_gears_up()
    {
        std::cout << "Shifting up to the next gear" << std::endl;
    }

    void shift_gears_down()
    {
        std::cout << "Shifting down to the previous gear" << std::endl;
    }

    void reverse()
    {
        std::cout << "Reversing" << std::endl;
    }

    void turn_wheel(int angle)
    {
        std::cout << "Turning the wheels by " << angle << " degrees" << std::endl;
    }

    void straighten_wheels()
    {
        std::cout << "Straightening wheels" << std::endl;
    }

    void apply_force_on_brakes(int force)
    {
        std::cout << "Applying a force of " << force << " to the brakes" << std::endl;
    }

    void apply_emergency_brakes()
    {
        std::cout << "Applying the brakes with maximum force for an emergency stop" << std::endl;
    }
    
};