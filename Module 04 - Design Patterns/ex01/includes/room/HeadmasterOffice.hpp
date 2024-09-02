#pragma once

#include <memory>
#include <vector>
#include "room/Room.hpp"

class HeadmasterOffice : public Room
{
private:

public:
    HeadmasterOffice(int maxOccupants) : Room(maxOccupants) {}
    ~HeadmasterOffice() {}

};