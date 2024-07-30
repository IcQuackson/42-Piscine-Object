#pragma once

#include "Worker.hpp"
#include "Tool.hpp"
#include <iostream>

class Worker;

struct Shovel : public Tool
{
private:

public:
    Shovel();
    ~Shovel();
    void use();

    friend std::ostream &operator<<(std::ostream &os, const Shovel &shovel);
    friend std::ostream &operator<<(std::ostream &os, const Shovel *shovel);
};