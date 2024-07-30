
#pragma once

#include "Tool.hpp"
#include <iostream>

class Hammer : public Tool
{
public:
    Hammer();
    ~Hammer();
    void use();
    friend std::ostream &operator<<(std::ostream &os, const Hammer &hammer);
    friend std::ostream &operator<<(std::ostream &os, const Hammer *hammer);
};