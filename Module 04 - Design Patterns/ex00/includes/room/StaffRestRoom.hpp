#pragma once

#include <memory>
#include <vector>
#include "room/Room.hpp"

class StaffRestRoom : public Room
{
private:

public:
    StaffRestRoom(int maxOccupants) : Room(maxOccupants) {}
    ~StaffRestRoom() {}

};