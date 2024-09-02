#pragma once

#include <memory>
#include <vector>
#include "room/Room.hpp"
#include "form/Form.hpp"
#include "enums/FormType.hpp"

class Form
{
private:
	FormType _formType;
	bool _isSigned;
	bool _isExecuted;

public:
	Form(FormType formType) : _formType(formType) {}
	virtual ~Form() {}

	FormType getFormType() const
	{
		return _formType;
	}

	virtual void execute() {
		if (_isSigned && !_isExecuted)
		{
			_isExecuted = true;
		}
	}

	void sign()
	{
		_isSigned = true;
	}

	bool isSigned()
	{
		return _isSigned;
	}

	bool isExecuted()
	{
		return _isExecuted;
	}
};
