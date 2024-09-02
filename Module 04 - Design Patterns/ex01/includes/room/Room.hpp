#pragma once

#include <memory>
#include <vector>
#include <iostream>
#include "person/Person.hpp"


class Person;

class Room
{
private:
	long long ID;
	std::vector<Person *> _occupants;
	int _maxOccupants;

public:
	Room(int maxOccupants) : _maxOccupants(maxOccupants)
	{
		static long long id = 0;
		ID = id++;
	}

	~Room() {}

	bool canEnter()
	{
		return _occupants.size() < static_cast<size_t>(_maxOccupants);
	}

	void enter(Person *person)
	{
		if (canEnter())
		{
			_occupants.push_back(person);
		}
	}

	void exit(Person *person)
	{
		for (auto it = _occupants.begin(); it != _occupants.end(); ++it)
		{
			if (*it == person)
			{
				_occupants.erase(it);
				break;
			}
		}
	}

	void printOccupant()
	{
		std::cout << "Room " << ID << " Occupants: ";
		for (auto &occupant : _occupants)
		{
			std::cout << occupant->getName() << " ";
		}
		std::cout << std::endl;
	}

	int getMaxOccupants() const
	{
		return _maxOccupants;
	}
};
