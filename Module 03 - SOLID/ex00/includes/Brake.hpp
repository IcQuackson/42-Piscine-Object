#pragma once

#include <iostream>

class Brake
{
public:
    void apply_force(int force)
    {
        std::cout << "Applying a force of " << force << " to the brakes" << std::endl;
    }

    void apply_emergency_force()
    {
        std::cout << "Applying an emergency force to the brakes" << std::endl;
    }
};