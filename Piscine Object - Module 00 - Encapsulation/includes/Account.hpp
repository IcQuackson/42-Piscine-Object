#pragma once

#include <iostream>
#include <vector>

struct Account
{
private:
	int id;
	int value;

public:
	Account();
	int getId() const;
	int getValue() const;
	void setId(int newId);
	void setValue(int newValue);
	void increaseValue(int value);
	void decreaseValue(int value);
	friend std::ostream& operator<<(std::ostream& p_os, const Account& p_account);
};