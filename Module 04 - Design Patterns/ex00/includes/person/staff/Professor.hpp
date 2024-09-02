#pragma once

#include <memory>
#include <vector>
#include <iostream>
#include "room/Room.hpp"
#include "room/ClassRoom.hpp"
#include "form/Form.hpp"
#include "person/Person.hpp"
#include "person/staff/Staff.hpp"
#include "Course.hpp"

class Professor : public Staff
{
private:
	Course * _currentCourse;

public:
	Professor(std::string name) : Staff(name), _currentCourse(nullptr) {}

	void assignCourse(Course *course)
	{
		std::cout << "Course assigned to professor" << std::endl;
		_currentCourse = course;
	}

	void doClass()
	{
		if (_currentCourse)
		{
			std::cout << "Professor " << getName() << " is teaching " << _currentCourse->getName() << std::endl;
		}
		else
		{
			std::cout << "Professor " << getName() << " has no course to teach" << std::endl;
		}
	}

	void closeCourse()
	{
		if (_currentCourse)
		{
			std::cout << "Professor " << getName() << " is closing " << _currentCourse->getName() << std::endl;
			_currentCourse = nullptr;
		}
		else
		{
			std::cout << "Professor " << getName() << " has no course to close" << std::endl;
		}
	}
};