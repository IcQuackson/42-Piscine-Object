#pragma once

#include <memory>
#include <vector>
#include <iostream>
#include "room/Room.hpp"
#include "form/Form.hpp"

class NeedMoreClassRoomForm : public Form
{
private:

public:
	void execute()
	{
		Form::execute();
		if (isExecuted())
		{
			std::cout << "Need more classroom form executed" << std::endl;
		}
	}
};