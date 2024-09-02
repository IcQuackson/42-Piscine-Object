#pragma once

#include <memory>
#include <vector>
#include "room/Room.hpp"
#include "form/Form.hpp"

class Room;
class Form;

class SecretarialOffice: public Room
{
private:
	std::vector<Form *> _archivedForms;

public:
	SecretarialOffice(int maxOccupants) : Room(maxOccupants) {}
	
	~SecretarialOffice() {}

	void archiveForm(Form *form)
	{
		_archivedForms.push_back(form);
	}

	std::vector<Form *> getArchivedForms() const
	{
		return _archivedForms;
	}

};