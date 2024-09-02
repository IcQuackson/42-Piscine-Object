#pragma once

#include <iostream>

class Gear
{
private:
    int gear;

public:
    Gear() : gear(0) {}

    int get_gear() const
    {
        return gear;
    }

    void shift_up()
    {
        if (gear == 5)
        {
            std::cout << "Can't shift up anymore" << std::endl;
            return;
        }
        gear++;
        std::cout << "Shifting up to gear " << gear << std::endl;
    }

    void shift_down()
    {
        if (gear == 0)
        {
            std::cout << "Can't shift down anymore" << std::endl;
            return;
        }
        gear--;
        std::cout << "Shifting down to gear " << gear << std::endl;
    }
};