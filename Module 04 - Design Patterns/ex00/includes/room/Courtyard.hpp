#pragma once

#include <memory>
#include <vector>
#include "room/Room.hpp"

class Courtyard : public Room
{
private:

public:
    Courtyard(int maxOccupants) : Room(maxOccupants) {}
    ~Courtyard() {}

};