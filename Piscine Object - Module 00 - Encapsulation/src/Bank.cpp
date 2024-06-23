#include "Bank.hpp"

Bank::Bank(): liquidity(0)
{
}

int Bank::getLiquidity() const
{
	return this->liquidity;
}

void Bank::setLiquidity(int value)
{
	this->liquidity = value;
}

void Bank::setClientAccounts(const std::vector<Account *> &accounts)
{
	this->clientAccounts = accounts;
}

const std::vector<Account *> &Bank::getClientAccounts() const
{
	return this->clientAccounts;
}

void Bank::addClientAccount(Account *account)
{
	this->clientAccounts.push_back(account);
}

void Bank::increaseLiquidity(int value)
{
	this->liquidity += value;
}

void Bank::decreaseLiquidity(int value)
{
	this->liquidity -= value;
}


std::ostream& operator << (std::ostream& p_os, const Bank& p_bank)
{
	p_os << "Bank informations : " << std::endl;
	p_os << "Liquidity : " << p_bank.getLiquidity() << std::endl;

	const std::vector<Account *> clientAccounts = p_bank.getClientAccounts();

	for (std::vector<Account *>::const_iterator it = clientAccounts.begin(); it != clientAccounts.end(); ++it)
	{
		p_os << **it << std::endl;
    }

	return (p_os);
}