#include "Bank.hpp"

Bank::Bank(): currentAccountId(0), liquidity(0)
{
}

void Bank::validateAccount(int id) const
{
	if (clientAccounts.find(id) == clientAccounts.end())
	{
		throw std::runtime_error("Account does not exist");
	}
}

const int &Bank::getLiquidity() const
{
	return this->liquidity;
}

void Bank::setLiquidity(double value)
{
	this->liquidity = value;
}

const Bank::Account* Bank::createAccount(double initialBalance)
{
	if (clientAccounts.find(this->currentAccountId) != clientAccounts.end())
	{
		throw std::runtime_error("Max number of accounts reached");
	}

	if (initialBalance < 0)
	{
		throw std::runtime_error("Initial balance must be greater or equal to 0");
	}

	// Create a new account and add it to the map
	Account *newAccount = new Account(this->currentAccountId, initialBalance);
	clientAccounts[this->currentAccountId] = newAccount;
	this->currentAccountId++;
	return newAccount;
}

void Bank::deleteAccount(int id)
{
	validateAccount(id);
	clientAccounts.erase(id);
}

void Bank::increaseLiquidity(double value)
{
	if (value <= 0)
	{
		throw std::runtime_error("Value to increase must be greater than 0");
	}

	this->liquidity += value;
}

void Bank::decreaseLiquidity(double value)
{
	if (value > this->liquidity || value <= 0)
	{
		throw std::runtime_error("Value to decrease must be less than current liquidity and greater than 0");
	}

	this->liquidity -= value;
}

void Bank::withdrawFromAccount(int id, double value)
{
	validateAccount(id);

	if (value <= 0)
	{
		throw std::runtime_error("Value to withdraw must be greater than 0");
	}

	Bank::Account *account = clientAccounts[id];
	if (value > account->balance)
	{
		throw std::runtime_error("Value to withdraw must be less or equal than current balance");
	}
	account->balance -= value;
}

void Bank::depositToAccount(int id, double value)
{
	validateAccount(id);

	if (value <= 0)
	{
		throw std::runtime_error("Value to withdraw must be greater than 0");
	}

	Account *account = clientAccounts[id];
	account->balance += value;
	// The bank must receive 5% of each money inflow 
	this->liquidity += value * 0.05;
}

void Bank::getLoan(int id, double value)
{
	validateAccount(id);
	
	if (value <= 0)
	{
		throw std::runtime_error("Value to loan must be greater than 0");
	}
	if (this->liquidity < value)
	{
		throw std::runtime_error("Bank does not have enough liquidity to loan this value");
	}
	this->depositToAccount(id, value);
}


const Bank::Account *Bank::operator[](size_t index) const
{
	validateAccount(index);
	return clientAccounts.at(index);
}

std::ostream& operator<<(std::ostream& os, const Bank& bank) {

	// Iterate over all accounts and print them
    for (std::map<int, Bank::Account*>::const_iterator it = bank.clientAccounts.begin();
		it != bank.clientAccounts.end(); ++it)
	{
        if (it->second != NULL) {
            os << *(it->second) << std::endl;
        }
    }
    return os;
}

// Account

int Bank::Account::getId() const
{
	return accountId;
}

double Bank::Account::getBalance() const
{
	return balance;
}

std::ostream& operator<<(std::ostream& p_os, const Bank::Account& p_account)
{
	p_os << "[" << p_account.getId() << "] - [" << p_account.getBalance() << "]";
	return (p_os);
}
