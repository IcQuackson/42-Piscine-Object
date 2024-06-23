
#include "Account.hpp"

Account::Account()  : id(-1), value(0)
{
}

int Account::getId() const
{
	return this->id;
}

int Account::getValue() const
{
	return this->value;
}

void Account::setId(int newId)
{
	this->id = newId;
}

void Account::setValue(int newValue)
{
	this->value = newValue;
}

void Account::increaseValue(int value)
{
	this->value += value;
}

void Account::decreaseValue(int value)
{
	this->value -= value;
}

std::ostream& operator<<(std::ostream& p_os, const Account& p_account)
{
	p_os << "[" << p_account.getId() << "] - [" << p_account.getValue() << "]";
	return (p_os);
}