#pragma once

#include <iostream>
#include <vector>
#include "Account.hpp"

struct Bank
{
private:
	int liquidity;
	std::vector<Account *> clientAccounts;

public:
	Bank();
	int getLiquidity() const;
	const std::vector<Account *> &getClientAccounts() const;
	void addClientAccount(Account *account);
	void setLiquidity(int value);
	void setClientAccounts(const std::vector<Account *> &accounts);
	void increaseLiquidity(int value);
	void decreaseLiquidity(int value);
	friend std::ostream& operator << (std::ostream& p_os, const Bank& p_bank);
};