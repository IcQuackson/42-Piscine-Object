#pragma once

#include <memory>
#include <vector>
#include <iostream>
#include "room/Room.hpp"
#include "form/Form.hpp"

class SubscriptionToCourseForm : public Form
{
private:

public:
	void execute()
	{
		Form::execute();
		if (isExecuted())
		{
			std::cout << "Subscription to course form executed" << std::endl;
		}
	}
};