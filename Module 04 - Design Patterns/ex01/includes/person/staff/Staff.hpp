#pragma once

#include <memory>
#include <vector>
#include "person/Person.hpp"
#include "room/Room.hpp"
#include "form/Form.hpp"

class Staff : public Person
{
private:

public:
	Staff(std::string name) : Person(name) {}

	void sign(Form *form)
	{
		form->sign();
	}
};