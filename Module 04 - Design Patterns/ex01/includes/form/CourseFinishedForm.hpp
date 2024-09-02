#pragma once

#include <memory>
#include <vector>
#include <iostream>
#include "room/Room.hpp"
#include "form/Form.hpp"

class CourseFinishedForm : public Form
{
private:

public:
	void execute()
	{
		Form::execute();
		if (isExecuted())
		{
			std::cout << "Course finished form executed" << std::endl;
		}
	}
};