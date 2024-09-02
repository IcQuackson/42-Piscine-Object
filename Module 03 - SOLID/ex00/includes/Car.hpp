
#pragma once

#include <iostream>
#include <vector>
#include "Engine.hpp"
#include "Gear.hpp"
#include "Wheel.hpp"
#include "Brake.hpp"

class Car
{
private:
    Engine engine;
    Gear gear;
    std::vector<Wheel> wheels;
    Brake brake;

public:

    void start()
    {
        engine.start();
    }

    void stop()
    {
        engine.stop();
    }

    void accelerate(int speed)
    {
        engine.accelerate(speed);
    }

    void shift_gears_up()
    {
        gear.shift_up();
    }

    void shift_gears_down()
    {
        gear.shift_down();
    }

    void reverse()
    {
        while (gear.get_gear() != 0)
        {
            gear.shift_down();
        }
        std::cout << "Reversing" << std::endl;
    }

    void turn_wheel(int angle)
    {
        for (auto &wheel : wheels)
        {
            wheel.turn(angle);
        }
    }

    void straighten_wheels()
    {
        for (auto &wheel : wheels)
        {
            wheel.straighten();
        }
    }

    void apply_force_on_brakes(int force)
    {
        brake.apply_force(force);
    }

    void apply_emergency_brakes()
    {
        brake.apply_emergency_force();
    }
};