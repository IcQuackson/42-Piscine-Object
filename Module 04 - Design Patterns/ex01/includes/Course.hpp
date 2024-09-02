#pragma once

#include <memory>
#include <vector>
#include <algorithm>

class Student;
class Professor;

class Course
{
private:
	std::string _name;
    Professor *_responsible;
	std::vector<Student *> _students;
	int _numberOfClassesToGraduate;
	int _maxStudents;

public:
	Course(std::string name, int numberOfClassesToGraduate = 0, int maxStudents = 0) :
		_name(name),
		_numberOfClassesToGraduate(numberOfClassesToGraduate),
		_maxStudents(maxStudents) {}
	
	std::string getName() const
	{
		return _name;
	}

	std::vector<Student *> getStudents() const
	{
		return _students;
	}

	int getNumberOfClassesToGraduate() const
	{
		return _numberOfClassesToGraduate;
	}

	int getMaxStudents() const
	{
		return _maxStudents;
	}
	
	void assign(Professor *professor)
	{
		_responsible = professor;
	}

	bool isStudentSubscribed(Student *student)
	{
		return std::find(_students.begin(), _students.end(), student) != _students.end();
	}

	void subscribe(Student * student)
	{
		if (_students.size() < static_cast<size_t>(_maxStudents))
		{
			_students.push_back(student);
		}
	}
};