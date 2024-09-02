#pragma once

#include <memory>
#include <vector>
#include "room/Room.hpp"

class Room;

class Person
{
private:
	std::string _name;
	Room *_currentRoom;

public:
	Person(std::string name) : _name(name) {}
    ~Person() {}

    std::string getName()
    {
        return (_name);
    }

	Room * getCurrentRoom()
    {
        return _currentRoom;
    }

};