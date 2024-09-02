#pragma once

#include <memory>
#include <vector>
#include <algorithm>
#include "room/Room.hpp"
#include "room/ClassRoom.hpp"
#include "form/Form.hpp"
#include "person/Person.hpp"
#include "Course.hpp"


class Student : public Person
{
private:
	std::vector<Course *> _subscribedCourses;

public:
	Student(std::string name) : Person(name) {}

	std::vector<Course *> getSubscribedCourses() const
	{
		return _subscribedCourses;
	}

	void attendClass(ClassRoom *classRoom)
	{
		if (!classRoom)
		{
			std::cout << "Student " << getName() << " is not in a class" << std::endl;
			return;
		}

		Course *course = classRoom->getCourse();
		if (course && course->isStudentSubscribed(this))
		{
			std::cout << "Student " << getName() << " is attending class " << course << std::endl;
			classRoom->enter(this);
		}
	}

	void exitClass(ClassRoom *classRoom)
	{
		classRoom->exit(this);
	}

	void subscribe(Course *course)
	{
		// if course is not in the subscribed course list, add it
		if (std::find(_subscribedCourses.begin(), _subscribedCourses.end(), course) == _subscribedCourses.end())
		{
			std::cout << "Student " << getName() << " is subscribing to course " << course->getName() << std::endl;
			_subscribedCourses.push_back(course);
		}
		else{
			std::cout << "Student " << getName() << " is already subscribed to course " << course->getName() << std::endl;
		}
	}

	void graduate(Course *course)
	{
		// if course is in the subscribed course list, remove it
		_subscribedCourses.erase(
			std::remove_if(
				_subscribedCourses.begin(),
				_subscribedCourses.end(),
				// Check if the course is the same
				[course](Course * c) {
					return c == course;
				}
			),
			_subscribedCourses.end()
		);
	}
};