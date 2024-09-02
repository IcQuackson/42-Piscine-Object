#pragma once

#include <memory>
#include <vector>
#include <iostream>
#include "room/Room.hpp"
#include "form/Form.hpp"

class NeedCourseCreationForm : public Form
{
private:

public:
	void execute()
	{
		Form::execute();
		if (isExecuted())
		{
			std::cout << "Need course creation form executed" << std::endl;
		}
	}
};