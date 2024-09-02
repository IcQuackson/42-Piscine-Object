#pragma once

#include <memory>
#include <vector>
#include "room/Room.hpp"
#include "Course.hpp"

class Room;

class ClassRoom : public Room
{
private:
    Course * _course; 

public:
	ClassRoom(int maxOccupants) : Room(maxOccupants) {}

	~ClassRoom() {}

	void assignCourse(Course *course)
	{
		std::cout << "Course assigned to class room" << std::endl;
		_course = course;
	}

	Course * getCourse() const
	{
		return _course;
	}
};