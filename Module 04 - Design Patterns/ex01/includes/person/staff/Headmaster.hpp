#pragma once

#include <vector>
#include "room/Room.hpp"
#include "room/ClassRoom.hpp"
#include "form/Form.hpp"
#include "person/Person.hpp"
#include "person/staff/Staff.hpp"
#include "Course.hpp"

class Headmaster : public Staff
{
private:
	std::vector<Form *> _formToSign;
	
public:
	Headmaster(std::string name) : Staff(name) {}

	void receiveForm(Form * form)
	{
		_formToSign.push_back(form);
	}

	void signForms()
	{
		for (auto &form : _formToSign)
		{
			form->sign();
		}
		_formToSign.clear();
	}
};