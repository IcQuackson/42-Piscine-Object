#pragma once

#include <iostream>
#include <vector>
#include <map>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"

struct Bank
{
	struct Account
	{
		friend class Bank; 

    private:
        int accountId;
        double balance;

	public:
        Account(int id, double balance) : accountId(id), balance(balance) {}

        int getId() const;
        double getBalance() const;

		friend std::ostream& operator<<(std::ostream& p_os, const Account& p_account);

    };

private:
	int currentAccountId;
	double liquidity;
	std::map<int, Account *> clientAccounts;

	void validateAccount(int id) const;

public:
	Bank();
	const double &getLiquidity() const;
	const Account *createAccount(double initialBalance);
	void deleteAccount(int id);
	void setLiquidity(double value);
	void increaseLiquidity(double value);
	void decreaseLiquidity(double value);
	void withdrawFromAccount(int id, double value);
	void depositToAccount(int id, double value);
	void getLoan(int id, double value);
	const Account *operator[](size_t index) const;
	friend std::ostream& operator << (std::ostream& p_os, const Bank& p_bank);
};