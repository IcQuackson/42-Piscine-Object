
#include "Car.hpp"

int main()
{
    Car car;

    car.start();
    car.accelerate(50);
    car.shift_gears_up();
    car.shift_gears_down();
    car.reverse();
    car.turn_wheel(90);
    car.straighten_wheels();
    car.apply_force_on_brakes(100);
    car.apply_emergency_brakes();
    car.stop();
}